#include "Collision.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#include <iostream>
#include <algorithm>

namespace whyengine
{
  void Collider::onInitialize()
  {
    size = rend::vec3(size);
    center = rend::vec3(0);
  }

	void Collision::onInitialize()
	{
		std::shared_ptr<Collision> self = getEntity()->getComponent<Collision>();
		getCore()->colliderList.push_back(self);

		std::shared_ptr<Collider> tCollider = std::make_shared<Collider>();
    
		std::cout << "Size: " << tCollider->size.x << ", " << tCollider->size.y << ", " << tCollider->size.z << std::endl;
		std::cout << "Center: " << tCollider->center.x << ", " << tCollider->center.y << ", " << tCollider->center.z << std::endl;

		id = getCore()->GetID();

		collider = getEntity()->getComponent<Collider>();

		collisions = std::vector<std::shared_ptr<Collision>>();
	}

	void Collision::moveEntity(rend::vec3 position)
	{
		if (!checkColliders(position))
		{
			getEntity()->getTransform()->position += position;
		}
	}

	bool Collision::checkColliders(rend::vec3 position)
	{
		bool collision = false;

		rend::vec3 checkPos = getEntity()->getTransform()->position + position + collider->center;

    //  the next set of vector 2 is essentailly to get the plane of a axis that forms the cubes
		rend::vec2 colliderRangeX = rend::vec2(checkPos.x - (collider->size.x / 2), 
                                     checkPos.x + (collider->size.x / 2));

		rend::vec2 colliderRangeY = rend::vec2(checkPos.y - (collider->size.y / 2), 
                                     checkPos.y + (collider->size.y / 2));

		rend::vec2 colliderRangeZ = rend::vec2(checkPos.z - (collider->size.z / 2), 
                                     checkPos.z + (collider->size.z / 2));
    
		for (int i = 0; i < getCore()->colliderList.size(); i++)    //  this cycles through the list of colliders
		{
			std::shared_ptr<Collision> rb = getCore()->colliderList[i];

			if (rb->id != id) //  this check is essentially to see if an AABB is colliding with its self. Does this by assigning an ID in Core.
			{
				rend::vec3 o_position = rb->getTransform()->position + rb->collider->center;

        //  similar to the old set of vec 2 just for a new position.
				rend::vec2 _ColliderRangeX = rend::vec2(o_position.x - (rb->collider->size.x / 2), 
                                         o_position.x + (rb->collider->size.x / 2));

				rend::vec2 _ColliderRangeY = rend::vec2(o_position.y - (rb->collider->size.y / 2), 
                                         o_position.y + (rb->collider->size.y / 2));

				rend::vec2 _ColliderRangeZ = rend::vec2(o_position.z - (rb->collider->size.z / 2), 
                                         o_position.z + (rb->collider->size.z / 2));

				if (colliderRangeX.y > _ColliderRangeX.x && colliderRangeX.x < _ColliderRangeX.y 
         && colliderRangeY.y > _ColliderRangeY.x && colliderRangeY.x < _ColliderRangeY.y 
         && colliderRangeZ.y > _ColliderRangeZ.x && colliderRangeZ.x < _ColliderRangeZ.y) //  checks the bounds of the AABB 
				{
					collision = true;

					bool check = false;
          //  stores the lists of collisisons to see what state they are in
					if (!std::count(collisions.begin(), collisions.end(), rb))
					{
						getEntity()->collisionEnter(rb);
						collisions.push_back(rb);
						check = true;
					}

					if (!check)
					{
						getEntity()->collisionStay(rb);
					}
				}
				else
        {
					  if (std::count(collisions.begin(), collisions.end(), rb))
					{
						getEntity()->collisionLeave(rb);
						collisions.erase(collisions.begin() + i);
						collisions.shrink_to_fit();
					}
				}
			}
		}
		return collision;
	}
}