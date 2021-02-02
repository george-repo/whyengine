#ifndef WHYENGINE_COLLISION_H
#define WHYENGINE_COLLISION_H

#include "Component.h"
#include <rend/rend.h>

namespace whyengine
{
	
  struct Collider;

  struct Collision : public Component
  {
    void onInitialize();
    void moveEntity(rend::vec3 position);
    bool checkColliders(rend::vec3 position);

    std::vector<std::shared_ptr<Collision>> collisions;
    std::shared_ptr<Collider> collider;

    int id;
  };

  struct Collider : Component
  {
    rend::vec3 size;
    rend::vec3 center;
    void onInitialize();
  };

}

#endif