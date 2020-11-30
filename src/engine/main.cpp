#include <whyengine/whyengine.h>

#define shared std::shared_ptr

int main()
{
  std::shared_ptr<Core> core = Core::initialize();
  std::shared_ptr<Entity> playerEntity = core->addEntity();
  std::shared_ptr<Renderer> playerRender = playerEntity->addComponent<Renderer>();
  std::shared_ptr<Keyboard> kB  = playerEntity->addComponent<Keyboard>();
  core->fetchKey = kB;

  playerRender->getTransform()->setPosition(rend::vec3(-1 ,-1 , -2));
  core->fetchKey->directionalMovement('w', 's', 'a', 'd', 0.1f);

  std::cout << "Calling start" << std::endl;

  core->start();
 
  return 0;
}
