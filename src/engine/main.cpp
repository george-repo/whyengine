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
    //std::shared_ptr<SoundSource> ss = getEntity()->addComponent<SoundSource>(getCore()->getAssets()->load<Sound>("sounds/yeah")); 
    
    r->setModel(getCore()->getAssets()->load<Model>("models/curuthers/curuthers"));
  }
};

struct Test : public Component
{
  void onInitialize()
  {
    std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();
    
    r->setModel(getCore()->getAssets()->load<Model>("models/two"));
  }

  void onTick()
  {
    getTransform()->rotate(0.1, 0, 0);

    if(getCore()->getKeymap()->setKeymap('k'))
    {
      getEntity()->destroy();
    }
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

    if(getCore()->getKeymap()->setKeymap('w'))  //  back and forth
    {
      velocity += rend::vec3(0, 0, -0.1f);
    }
    else if(getCore()->getKeymap()->setKeymap('s'))
    {
      velocity += rend::vec3(0, 0, +0.1f);
    }

    if(getCore()->getKeymap()->setKeymap(SDLK_SPACE)) //  up and down
    {
      velocity += rend::vec3(0, 0.1f, 0);
    }
    else if(getCore()->getKeymap()->setKeymap(SDLK_LSHIFT))
    {
      velocity += rend::vec3(0, -0.1, 0);
    }

    if(getCore()->getKeymap()->setKeymap('a'))  //  left and right
    {
      velocity += rend::vec3(-0.1f, 0, 0);
    }
    else if(getCore()->getKeymap()->setKeymap('d'))
    {
      velocity += rend::vec3(+0.1f, 0, 0);
    }
    
    moveEntity(velocity);
  }

  void onTick()
  {
    move();

    if(getCore()->getKeymap()->setKeymap('q'))  //  left and right
    {
      getTransform()->rotate(0, +0.1, 0);
    }
    else if(getCore()->getKeymap()->setKeymap('e'))
    {
      getTransform()->rotate(0, -0.1, 0);
    }
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

  //  player
  std::shared_ptr<Entity> pe = core->addEntity();
  pe->getTransform()->setPosition(rend::vec3(0, 30, -10));
  pe->addComponent<Collider>();
  pe->getComponent<Collider>()->size = rend::vec3 (1,15,1);
  pe->addComponent<Collision>();
  pe->getTransform()->mass = 1.0f;
  std::shared_ptr<Player> p = pe->addComponent<Player>();

  //  Demo having a second model
  std::shared_ptr<Entity> among = core->addEntity();
  among->getTransform()->setPosition(rend::vec3(10, 0, -10));
  among->getTransform()->setScale(rend::vec3(0.03, 0.03, 0.03));
  std::shared_ptr<Test> e = among->addComponent<Test>();

  //  camera
  std::shared_ptr<Entity> camera = core->addEntity();
  camera->addComponent<Camera>();
  camera->addComponent<Controller>();
  camera->addComponent<Collider>();
  camera->addComponent<Collision>();

  // world
  std::shared_ptr<Entity> world = core->addEntity();
  world->getTransform()->setPosition(rend::vec3(0, -10, -10));
  world->getTransform()->setScale(rend::vec3(0.1, 0.1, 0.1));
  std::shared_ptr<Enviroment> envy = world->addComponent<Enviroment>();
  
  core->start();

  return 0;
}
