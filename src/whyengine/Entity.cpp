///
///  @file  Entity.cpp
///  @brief returns a couple of shared_ptr functions to allow the entities to be usable.
///  As well as housing the tick and render components.  

// header include
#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace whyengine // namespace
{
  // the next two functions are similar just for different purposes
  void Entity::tick()
  {
    for(size_t ci = 0; ci < components.size(); ci++)
    {
      components.at(ci)->tick();  // testing if ci is in bounds of componenets. assigns to tick();
    }
  }

  void Entity::render()
  {
    for(size_t ci = 0; ci < components.size(); ci++)
    {
      components.at(ci)->render();  // essentially the same as the function above just used different on a backend product pov
    }
  }

  std::shared_ptr<Core> Entity::getCore()
  {
    return core.lock(); // locks all objects that are passed as arguments
  }

  std::shared_ptr<Transform> Entity::getTransform()
  {
    return getComponent<Transform>(); // returns the use of getComponent with the transform struct
  }

  void Entity::destroy()
  {
    if(alive) // alive?
    {
      alive = false;  // set alive to false

      for(size_t ci = 0; ci < components.size(); ci++)
      {
        components.at(ci)->destroy(); // destroy the component
      }
    }
  }

  void Entity::collisionEnter(std::shared_ptr<Collision> state)
  {
    for (size_t ci = 0; ci < components.size(); ci++)
    {
        components.at(ci)->collisionEnter(state);
    }
  }

  void Entity::collisionStay(std::shared_ptr<Collision> state)
  {
    for (size_t ci = 0; ci < components.size(); ci++)
    {
        components.at(ci)->collisionStay(state);
    }
  }

  void Entity::collisionLeave(std::shared_ptr<Collision> state)
  {
    for (size_t ci = 0; ci < components.size(); ci++)
    {
        components.at(ci)->collisionLeave(state);
    }
  }
}