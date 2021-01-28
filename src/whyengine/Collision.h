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
    void onTick();
    void moveEntity(rend::vec3 position);
    bool checkColliders(rend::vec3 position);

    std::vector<std::shared_ptr<Collision>> collisions;
    std::shared_ptr<Collider> collider;
    rend::vec3 velocity;
    bool gravity;
    int id;
  };

  struct Collider : Component
  {
    rend::vec3 size;
    rend::vec3 center;

    void onInitialize(rend::vec3 size)
    {
      size = rend::vec3(size);
      center = rend::vec3(0);
    }

    void onInitialize()
    {
      size = rend::vec3(1);
      center = rend::vec3(0);
    }
  };

}

#endif