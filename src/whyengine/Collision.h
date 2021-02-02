/// \brief The header file that is responsible for the main collision system
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 02/01/21
/// \todo ...

#ifndef WHYENGINE_COLLISION_H
#define WHYENGINE_COLLISION_H

//  system includes
#include <rend/rend.h>

//  header includes
#include "Component.h"

namespace whyengine //  namespace
{
	//  the collider its self and its values
  struct Collider;
  
  //  everything else todo with the collision
  struct Collision : public Component
  {
    void onInitialize();
    void moveEntity(rend::vec3 position); //  moves the entity with collisions in consideration
    bool checkColliders(rend::vec3 position); //  checks collisions

    std::vector<std::shared_ptr<Collision>> collisions; //  a list of all collisions
    std::shared_ptr<Collider> collider;

    int id; //  id to prevent self collisions
  };

  //  the values for the aabb
  struct Collider : Component
  {
    rend::vec3 size;
    rend::vec3 center;
    void onInitialize();
  };

}

#endif  //  _COLLISION_H_