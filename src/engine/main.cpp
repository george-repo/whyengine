#include <whyengine/whyengine.h>

#include <iostream>
#include <ctime>

struct Enviroment : public Component
{
  void onInitialize()
  {
    std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();
    r->setModel(getCore()->getAssets()->load<Model>("models/Floor"));
  }
};

struct Player : public Component
{
  void onInitialize()
  {
    std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();
    std::shared_ptr<SoundSource> ss = getEntity()->addComponent<SoundSource>(getCore()->getAssets()->load<Sound>("sounds/yeah")); 
    
    r->setModel(getCore()->getAssets()->load<Model>("models/curuthers/curuthers"));
  }
};

struct Controller : public Component
{
  void moveEntity(rend::vec3 velocity)
  {
    getEntity()->getComponent<Collision>()->moveEntity(velocity);
  }

  void move()
  {
    rend::vec3 velocity = rend::vec3(0);

    if(getCore()->getKeymap()->setKeymap('w'))
    {
      velocity += rend::vec3(0, 0, -0.1f);
    }
    else if(getCore()->getKeymap()->setKeymap('s'))
    {
      velocity += rend::vec3(0, 0, +0.1f);
    }

    if(getCore()->getKeymap()->setKeymap(SDLK_SPACE))
    {
      velocity += rend::vec3(0, 0.1f, 0);
    }
    else if(getCore()->getKeymap()->setKeymap(SDLK_LSHIFT))
    {
      velocity += rend::vec3(0, -0.1, 0);
    }

    if(getCore()->getKeymap()->setKeymap('a'))
    {
      getTransform()->rotate(0.05f, 0, 0);
    }
    else if(getCore()->getKeymap()->setKeymap('d'))
    {
      getTransform()->rotate(-0.05f, 0, 0);
    }

    moveEntity(velocity);
  }

  void onTick()
  {
    move();
  }
  
};

struct Enviro : public Component
{
  void onInitialize()
  {
    std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();
    r->setModel(getCore()->getAssets()->load<Model>("models/Floor"));
  }
};

int main()
{
  std::shared_ptr<Core> core = Core::initialize(800, 800);

  // player
  std::shared_ptr<Entity> pe = core->addEntity();
  pe->getTransform()->setPosition(rend::vec3(0, 30, -10));
  pe->addComponent<Collider>();
  pe->getComponent<Collider>()->size = rend::vec3 (1,15,1);
  pe->addComponent<Collision>();
  pe->getTransform()->mass = 1.0f;

  //std::shared_ptr<SoundSource> ss = pe->addComponent<SoundSource>(core->getAssets()->load<Sound>("sounds/test"));
  std::shared_ptr<Player> p = pe->addComponent<Player>();

  //  camera
  std::shared_ptr<Entity> camera = core->addEntity();
  camera->addComponent<Camera>();
  camera->addComponent<Controller>();
  camera->addComponent<Collider>();
  camera->addComponent<Collision>();

  // world
  std::shared_ptr<Entity> world = core->addEntity();
  world->getTransform()->setPosition(rend::vec3(0, -5, -10));
  world->getTransform()->setScale(rend::vec3(0.1,0.1,0.1));
  std::shared_ptr<Enviroment> envy = world->addComponent<Enviroment>();
  
  core->start();

  return 0;
}