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

#include <vector>
#include <memory>

namespace whyengine
{

  struct Component;
  struct Core;
  struct Exception;
  struct Transform;

  struct Entity
  {
  public:
    friend struct ::whyengine::Core;

    template <typename T>
    std::shared_ptr<T> addComponent()
    {
      std::shared_ptr<T> rtn = std::make_shared<T>();
      rtn->entity = self;

      components.push_back(rtn);

      rtn->onInitialize();
      return rtn;
    }

    template <typename T, typename ... Args>
    std::shared_ptr<T> addComponent(Args&& ... args)
    {
      std::shared_ptr<T> rtn = std::make_shared<T>();
      rtn->entity = self;

      components.push_back(rtn);

      rtn->onInitialize(std::forward<Args>(args) ...);
      return rtn;
    }

    template <typename T>
    std::shared_ptr<T> getComponent()
    {
      for(size_t i = 0; i < components.size(); i++)
      {
        std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(components.at(i));
        if(!rtn) continue;
        return rtn;
      }
    }
  
    void tick();
    void render();
    void destroy();    

    std::shared_ptr<Core> getCore();
    std::shared_ptr<Transform> getTransform();

  private:
    std::vector<std::shared_ptr<Component>> components;
    std::weak_ptr<Core> core;
    std::weak_ptr<Entity> self;
    bool alive;
  };

}
#endif // _ENTITY_H_