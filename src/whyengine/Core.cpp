#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Transform.h"
#include "Keyboard.h"

#include <iostream>

namespace whyengine
{
  std::shared_ptr<Core> Core::initialize()
  {
    std::shared_ptr<Core> rtn = std::make_shared<Core>();
    rtn->self = rtn;

    rtn->window = SDL_CreateWindow("whyengine",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      800, 600,
      SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if(!rtn->window)
    {
      throw Exception("Failed to create window");
    }

    rtn->glContext = SDL_GL_CreateContext(rtn->window);

    if(!rtn->glContext)
    {
      throw Exception("Failed to create OpenGL context");
    }

    rtn->context = rend::Context::initialize();

    return rtn;
  }
  
  std::shared_ptr<Entity> Core::addEntity()
  {
    std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
    rtn->core = self;
    rtn->self = rtn;
    rtn->alive = true;
    
    rtn->addComponent<Transform>();
    entities.push_back(rtn);

    return rtn;
  }

  void Core::start()
  {
    bool running = true;
    bool t = true;
    SDL_Event e = {0};

    while(running)
    {
      while(SDL_PollEvent(&e) != 0)
      {

        if(e.type == SDL_QUIT)
        {
          running = false;
        }
        else if (e.type == SDL_KEYDOWN)
        {
          if (e.key.keysym.sym == fetchKey->directionUp) fetchKey->rtnKey(t, NULL, NULL, NULL);
          if (e.key.keysym.sym == fetchKey->directionDown) fetchKey->rtnKey(NULL, t, NULL, NULL);
          if (e.key.keysym.sym == fetchKey->directionLeft) fetchKey->rtnKey(NULL, NULL, t, NULL); 
          if (e.key.keysym.sym == fetchKey->directionRight) fetchKey->rtnKey(NULL, NULL, NULL, t);
        }
      }
      
      for(size_t ei = 0; ei < entities.size(); ei++)
      {
        entities.at(ei)->tick();
      }

      for(size_t ei = 0; ei < entities.size(); ei++)
      {
        if(entities.at(ei)->alive == false)
        {
          entities.erase(entities.begin() + ei);
          ei--;
        }
      }
      glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      for(size_t ei = 0; ei < entities.size(); ei++)
      {
        entities.at(ei)->render();
      }

      SDL_GL_SwapWindow(window);
    }
  }
}

