#include <whyengine/whyengine.h>

#define shared std::shared_ptr

int main()
{
  std::shared_ptr<Core> core = Core::initialize();
  
  std::shared_ptr<Entity> playerEntity = core->addEntity();
  std::shared_ptr<Renderer> playerRender = playerEntity->addComponent<Renderer>();
  playerRender->getTransform()->setPosition(rend::vec3(0 ,0 , -2));


  core->start();

  return 0; 
}