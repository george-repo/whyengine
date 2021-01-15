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

#include <memory>

namespace whyengine
{
  struct Entity;
  struct Core;
  struct Transform;

  struct Component
  {
  public:
    friend struct whyengine::Entity;

    virtual void onInitialize();

    void tick();
    virtual void onTick();

    void render();
    virtual void onRender();

    void destroy();
    virtual void onDestroy();

    std::shared_ptr<Entity> getEntity();
    std::shared_ptr<Core> getCore();
    std::shared_ptr<Transform> getTransform();
    
  private:
    std::weak_ptr<Entity> entity;
  };

}

#endif // _COMPONENT_H_