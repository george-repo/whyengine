/// \brief The other half of the CES (component entity system)
/// \author George Jennings
/// \version 0.9
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// Added everything todo with destroy function 20/12/20
/// \todo ...

#ifndef WHYENGINE_COMPONENT_H
#define WHYENGINE_COMPONENT_H

//  system includes
#include <memory>

namespace whyengine // namespace
{
  // structs from other headers
  struct Entity;
  struct Core;
  struct Transform;
  struct Collision;

  struct Component  // main struct of Component files
  {
  public:
    friend struct whyengine::Entity;  // since this engine has an CES entity and component need to encapsulate each other

    virtual void onInitialize();  // virtual function to be used in main loop

    void tick();  // used locally in .cpp
    virtual void onTick();  // virtual function to be used in main loop

    void render();
    virtual void onRender();  // virtual function to be used in main loop

    void destroy();
    virtual void onDestroy(); // virtual function to be used in main loop

    void collisionEnter(std::shared_ptr<Collision> state);
    virtual void onCollisionEnter(std::shared_ptr<Collision> state);  //  responbile for state of collision

    void collisionStay(std::shared_ptr<Collision> state);
    virtual void onCollisionStay(std::shared_ptr<Collision> state);

    void collisionLeave(std::shared_ptr<Collision> state);
    virtual void onCollisionLeave(std::shared_ptr<Collision> state);

    std::shared_ptr<Entity> getEntity();  // these are used in main loop too however they are ptr functions to utilize structs better
    std::shared_ptr<Core> getCore();
    std::shared_ptr<Transform> getTransform();
    
  private:
    std::weak_ptr<Entity> entity; // local value
  };

}

#endif // _COMPONENT_H_