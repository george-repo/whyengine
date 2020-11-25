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
    friend struct whyengine::Entity;

    virtual void onInitialize();

    void tick();
    virtual void onTick();

    void render();
    virtual void onRender();

    std::shared_ptr<Entity> getEntity();
    std::shared_ptr<Core> getCore();
    std::shared_ptr<Transform> getTransform();

  private:
    std::weak_ptr<Entity> entity;
  };

}

#endif
