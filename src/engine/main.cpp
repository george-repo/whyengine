#include <whyengine/whyengine.h>

#include <iostream>

#define shared std::shared_ptr

int main()
{
  std::shared_ptr<Core> core = Core::initialize();
  
  std::shared_ptr<Entity> pe = core->addEntity();
  std::shared_ptr<Renderer> pr = pe->addComponent<Renderer>();

  std::shared_ptr<Entity> ee = core->addEntity();
  std::shared_ptr<Renderer> er = ee->addComponent<Renderer>();

  core->start();

  return 0;
}