#include <whyengine/whyengine.h>

#include <iostream>

struct Player : public Component
{
  void onInitialize(int team, int type, std::string name)
  {
    std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();

    std::shared_ptr<Model> cm = getCore()->getAssets()->load<Model>("models/curuthers/curuthers");

    r->setModel(cm);
  }
};

struct Killer : public Component
{
  void onTick()
  {
    if(getCore()->getKeymap()->setKeymap('k'))
    {
      std::cout << "Should destroy" << std::endl;
      getEntity()->destroy();
    }
  }

  void onDestroy()
  {
    std::cout << "Destroyed" << std::endl;
  }
};

struct Controller : public Component
{
  //try use my keyboard input here?
  //may need to add a new function to component
  
  void onTick()
  {
    if(getCore()->getKeymap()->setKeymap('w'))
    {
      getTransform()->translate(0, 0, -0.1f);
    }
    else if(getCore()->getKeymap()->setKeymap('s'))
    {
      getTransform()->translate(0, 0, 0.1f);
    }

    if(getCore()->getKeymap()->setKeymap('a'))
    {
      getTransform()->rotate(0, 0.1f, 0);
    }
    else if(getCore()->getKeymap()->setKeymap('d'))
    {
      getTransform()->rotate(0, -0.1f, 0);
    }
  }
  
};

struct Enemy : public Component
{
  void onInitialize()
  {
    std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();

    std::shared_ptr<Model> em = getCore()->getAssets()->load<Model>("models/curuthers/curuthers");

    r->setModel(em);
  }
};

int main()
{
  std::shared_ptr<Core> core = Core::initialize();

  std::shared_ptr<Entity> pe = core->addEntity();
  pe->getTransform()->setPosition(rend::vec3(0, 0, -10));
  std::shared_ptr<Player> p = pe->addComponent<Player>(1, 2, "Karsten");
  pe->addComponent<Killer>();

  std::shared_ptr<Entity> ee = core->addEntity();
  ee->getTransform()->setPosition(rend::vec3(5, 0, -10));
  std::shared_ptr<Enemy> e = ee->addComponent<Enemy>();

  std::shared_ptr<Entity> camera = core->addEntity();
  camera->addComponent<Camera>();
  camera->addComponent<Controller>();

  std::shared_ptr<Entity> c2 = core->addEntity();
  c2->getTransform()->setPosition(rend::vec3(0, 20, 0));
  c2->getTransform()->rotate(-90, 0, 0);
  std::shared_ptr<Camera> mc = c2->addComponent<Camera>();
  mc->addRenderTexture();

  core->start();

  return 0;
}

/*
#include <whyengine/whyengine.h>

#define shared std::shared_ptr

struct Player : public Component
{
  void onInitialize(int team, int type, std::string name)
  {
    std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();

    std::shared_ptr<Model> cm = getCore()->getAssets()->
      load<Model>("models/curuthers/curuthers");

    r->setModel(cm);
  }
};

struct Controller : public Component
{
  void onTick()
  {
    if(getCore()->getKeymap()->setKeymap('w'))
    {
      getTransform()->translate(0, 0, -0.1f);
    }
    else if(getCore()->getKeymap()->setKeymap('s'))
    {
      getTransform()->translate(0, 0, 0.1f);
    }

    if(getCore()->getKeymap()->setKeymap('a'))
    {
      getTransform()->rotate(0, 1, 0);
    }
    else if(getCore()->getKeymap()->setKeymap('d'))
    {
      getTransform()->rotate(0, -1, 0);
    }
  }
};
int main()
{
  std::shared_ptr<Core> core = Core::initialize();


  std::shared_ptr<Entity> playerEntity = core->addEntity();
  playerEntity->getTransform()->setPosition(rend::vec3(0, 0, -2));
  std::shared_ptr<Player> p = playerEntity->addComponent<Player>(1, 2, "Karsten");
  
  std::shared_ptr<Entity> camera = core->addEntity();
  camera->addComponent<Camera>();
  camera->addComponent<Controller>();

  std::shared_ptr<Entity> c2 = core->addEntity();
  c2->getTransform()->setPosition(rend::vec3(0, 20, 0));
  c2->getTransform()->rotate(-90, 0, 0);
  std::shared_ptr<Camera> mc = c2->addComponent<Camera>();
  mc->addRenderTexture();



  
  std::shared_ptr<Keyboard> kB = playerEntity->addComponent<Keyboard>();
  core->fetchKey = kB;
  playerEntity->getTransform()->setPosition(rend::vec3(-1 ,-1 , -2));
  core->fetchKey->directionalMovement('p', 'l', 'k', 'i', 0.1f);

  std::cout << "Calling start" << std::endl;
  
  core->start();
  
  return 0;
}

if(getCore()->getKeymap()->setKeymap('w'))
    {
      getTransform()->translate(0, 0, -0.1f);
    }
    else if(getCore()->getKeymap()->setKeymap('s'))
    {
      getTransform()->translate(0, 0, 0.1f);
    }

    if(getCore()->getKeymap()->setKeymap('a'))
    {
      getTransform()->rotate(0, 0.1f, 0);
    }
    else if(getCore()->getKeymap()->setKeymap('d'))
    {
      getTransform()->rotate(0, -0.1f, 0);
    }

*/