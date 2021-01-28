/// \brief the main elemenets for using the COMPONENT ENTITY SYSTEM or CES starts from here
/// \author George Jennings
/// \version 1.5
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// Added template function to take arguments 16/12/20
/// Added everything todo with destroy function 20/12/20
/// \todo ...

#ifndef WHYENGINE_ENTITY_H
#define WHYENGINE_ENTITY_H

// system includes
#include <vector>
#include <memory>
#include "Collision.h"

namespace whyengine // namspace 
{
  // different structs from different .h files to allow access to varibles
  struct Component;
  struct Core;
  struct Exception;
  struct Transform;

  struct Entity // main struct here
  {
  public:
    friend struct ::whyengine::Core;  // encapsulates the core struct

    // template function
    template <typename T>
    std::shared_ptr<T> addComponent() // add component function. Essentailly adds user defined components in main function
    {                                         
      std::shared_ptr<T> rtn = std::make_shared<T>();
      rtn->entity = self; // entity is now its self

      components.push_back(rtn); // new element added towards the back of the vector

      rtn->onInitialize();
      return rtn; // returning values
    }
    
    // template function
    template <typename T, typename ... Args>
    std::shared_ptr<T> addComponent(Args&& ... args)  // the same as above but can support user defined arguments
    {
      std::shared_ptr<T> rtn = std::make_shared<T>();
      rtn->entity = self;

      components.push_back(rtn);

      rtn->onInitialize(std::forward<Args>(args) ...);
      return rtn;
    } 

    // template function for getting a component
    template <typename T>
    std::shared_ptr<T> getComponent()
    {
      for(size_t i = 0; i < components.size(); i++) // checking the size of the vector
      {
        std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(components.at(i));  // dynamic pointer that checks if components are in bounds
        if(!rtn) continue; // if this does not happen then it will continue
        return rtn;
      }
    }
  
    void tick();  // the tick used for onTick.
    void render();  // the render it self
    void destroy(); // the destroy function capable of destroying entities

    void collisionEnter(std::shared_ptr<Collision> state);
    void collisionStay(std::shared_ptr<Collision> state);
    void collisionLeave(std::shared_ptr<Collision> state);
    

    std::shared_ptr<Core> getCore();  // for the user to get the core functions
    std::shared_ptr<Transform> getTransform();  // for the user to get the transform functions

  private:
    std::vector<std::shared_ptr<Component>> components; // vector with shared pointer from the Components struct
    std::weak_ptr<Core> core;
    std::weak_ptr<Entity> self;
    bool alive; // testing state of the destroy function
  };

}
#endif // _ENTITY_H_