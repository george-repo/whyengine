///
///  @file  Component.cpp
///  @brief the other half of the CES. This sets out to allow the usability of structs in main.

// header includes
#include "Component.h"
#include "Entity.h"

namespace whyengine // namespace
{
  void Component::tick()  // the next three functions call the virtual function counterparts
  {
    onTick();
  }

  void Component::render()
  {
    onRender();
  }

  void Component::destroy()
  {
    onDestroy();
  }

  // all the virtual functions 
  void Component::onInitialize() { }
  void Component::onTick() { }
  void Component::onRender() { }
  void Component::onDestroy() { }

  std::shared_ptr<Entity> Component::getEntity()  // gets the entity
  {
    return entity.lock(); // locks all objects that are passed as arguments
  }

  std::shared_ptr<Core> Component::getCore()  // gets the core via the entity
  {
    return getEntity()->getCore();
  }

  std::shared_ptr<Transform> Component::getTransform()  // gets the transform via the entity
  {
    return getEntity()->getTransform();
  }
}