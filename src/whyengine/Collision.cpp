#include "Collision.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#include <iostream>
#include <algorithm>

namespace whyengine
{
	void Collision::onInitialize()
	{
		std::shared_ptr<Collision> self = getEntity()->getComponent<Collision>();
		getCore()->colliderList.push_back(self);

		std::shared_ptr<Collider> tCollider = std::make_shared<Collider>();
    
		std::cout << "Size: " << tCollider->size.x << ", " << tCollider->size.y << ", " << tCollider->size.z << std::endl;
		std::cout << "Center: " << tCollider->center.x << ", " << tCollider->center.y << ", " << tCollider->center.z << std::endl;

		id = getCore()->GetID();

		collider = getEntity()->getComponent<Collider>();

		velocity = rend::vec3(0);

		gravity = true;

		collisions = std::vector<std::shared_ptr<Collision>>();
	}

	void Collision::onTick()
	{
		if (gravity)
		{
			float bottom = getEntity()->getTransform()->position.y - (getEntity()->getTransform()->position.y + collider->center.y - (collider->size.y / 2));
			float maxVel = -10.0f;

			if(!checkColliders(rend::vec3(0, -0.01, 0)))
			{
				velocity.y = std::max(velocity.y + -9.81f / 500, std::min(maxVel, -bottom));
				moveEntity(velocity);
      }
      else
      {
        velocity.y = 0;
      }
		}
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

		rend::vec3 m_position = getEntity()->getTransform()->position + position + collider->center;

		rend::vec2 m_xrange = rend::vec2(m_position.x - (collider->size.x / 2), m_position.x + (collider->size.x / 2));
		rend::vec2 m_yrange = rend::vec2(m_position.y - (collider->size.y / 2), m_position.y + (collider->size.y / 2));
		rend::vec2 m_zrange = rend::vec2(m_position.z - (collider->size.z / 2), m_position.z + (collider->size.z / 2));

		for (int i = 0; i < getCore()->colliderList.size(); i++)
		{
			std::shared_ptr<Collision> rb = getCore()->colliderList[i];

			if (rb->id != id)
			{
				rend::vec3 o_position = rb->getTransform()->position + rb->collider->center;

				rend::vec2 o_xrange = rend::vec2(o_position.x - (rb->collider->size.x / 2), o_position.x + (rb->collider->size.x / 2));
				rend::vec2 o_yrange = rend::vec2(o_position.y - (rb->collider->size.y / 2), o_position.y + (rb->collider->size.y / 2));
				rend::vec2 o_zrange = rend::vec2(o_position.z - (rb->collider->size.z / 2), o_position.z + (rb->collider->size.z / 2));

				if (m_xrange.y > o_xrange.x && m_xrange.x < o_xrange.y && m_yrange.y > o_yrange.x && m_yrange.x < o_yrange.y && m_zrange.y > o_zrange.x && m_zrange.x < o_zrange.y)
				{
					collision = true;

					bool check = false;

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