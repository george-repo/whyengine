///
///  @file  Component.cpp
///  @brief the other half of the CES. This sets out to allow the usability of structs in main.

// header includes
#include "Component.h"
#include "Entity.h"
#include "Collision.h"

namespace whyengine // namespace
{
  void Component::tick()  // the next three functions call the virtual function counterparts
  {
    onTick();
  }

  void Component::render()
  {
    onRender(); //  RENDERS EVERYTHING
  }

  void Component::destroy()
  {
    onDestroy();  //  DESTROYS THE ENTITY
  }

  //  the following series is responsible for the state of a collision
  void Component::collisionEnter(std::shared_ptr<Collision> state)
  {
	  onCollisionEnter(state);
  }

  void Component::collisionStay(std::shared_ptr<Collision> state)
  {
	  onCollisionStay(state);
  }

  void Component::collisionLeave(std::shared_ptr<Collision> state)
  {
	  onCollisionLeave(state);
  }



  // all the virtual functions 
  void Component::onInitialize() { }
  void Component::onTick() { }
  void Component::onRender() { }
  void Component::onDestroy() { }
  
  //  responsible for states of a collision
  void Component::onCollisionEnter(std::shared_ptr<Collision> state) { }
  void Component::onCollisionStay(std::shared_ptr<Collision> state) { }
  void Component::onCollisionLeave(std::shared_ptr<Collision> state) { }

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