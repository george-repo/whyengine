#include <whyengine/whyengine.h>

#define shared std::shared_ptr

struct test : public Component
{
  void onTick()
  {
    if(getCore()->getKeymap()->setKeymap('k'))
    {
      std::cout << "Test" << std::endl;
      getEntity()->destroy();
    }

    if(getCore()->getKeymap()->setKeymap('r'))
    {
      getTransform()->translate(0, 0, -0.1f);
    }
    else if(getCore()->getKeymap()->setKeymap('t'))
    {
      getTransform()->translate(0, 0, 0.1f);
    }

    if(getCore()->getKeymap()->setKeymap('y'))
    {
      getTransform()->rotate(0, 1, 0);
    }
    else if(getCore()->getKeymap()->setKeymap('u'))
    {
      getTransform()->rotate(0, -1, 0);
    }
  }

  void onDestroy()
  {
    std::cout << "Test true" << std::endl;
  }
};

int main()
{
  std::shared_ptr<Core> core = Core::initialize();


  std::shared_ptr<Entity> playerEntity = core->addEntity();
  std::shared_ptr<Renderer> playerRender = playerEntity->addComponent<Renderer>();  

  playerEntity->addComponent<test>();

  std::shared_ptr<Keyboard> kB = playerEntity->addComponent<Keyboard>();
  core->fetchKey = kB;

  playerEntity->getTransform()->setPosition(rend::vec3(-1 ,-1 , -2));
  core->fetchKey->directionalMovement('w', 's', 'a', 'd', 0.1f);

  std::cout << "Calling start" << std::endl;
  
  core->start();
  
  return 0;
}