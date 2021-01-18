///
///  @file  Core.cpp
///  @brief The main game loop towards the end of file as well as all the initializtion needed
///  for the program to run. In essence a collection of all other files.

// systme includes
#include <iostream>

// header includes
#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Keymapping.h"
#include "Assets.h"

namespace whyengine // namespace
{
  std::shared_ptr<Core> Core::initialize()  // the main initialize function
  {
    std::shared_ptr<Core> rtn = std::make_shared<Core>(); // making of core
    rtn->self = rtn;  // making rtn = its self

    rtn->window = SDL_CreateWindow("whyengine", // this is the start of the window that we see
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      1000, 1000, // size of window
      SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE); //  SDL parameters

    if(!rtn->window)  // if window failed then we an through exception 
    {
      throw Exception("Failed to create window"); // message 
    }

    rtn->glContext = SDL_GL_CreateContext(rtn->window); // create the context with the window

    if(!rtn->glContext) // if the context failed we can through an exception
    {
      throw Exception("Failed to create OpenGL context"); // message 
    }

    rtn->context = rend::Context::initialize(); //  context is initialized with the rend library 
    rtn->keymapping = std::make_shared<Keymap>(); // keymapping is now a make_shared ptr locally used

    rtn->assets = std::make_shared<Assets>(); // same as above but for assets
    rtn->assets->core = rtn;
    return rtn; // return rtn
  }

  std::shared_ptr<Keymap> Core::getKeymap() // next two functions return the local value 
  {
    return keymapping;  // the local value manipulated above and used below
  }
  
  std::shared_ptr<Assets> Core::getAssets() // same as above different output
  {
    return assets;  // local value manipulated above
  }
  
  std::shared_ptr<Camera> Core::getCamera() // gets the camera
  {
    return currentCamera.lock();  // locks all objects that are passed as arguments
  }

  std::shared_ptr<Entity> Core::addEntity() // add an entity to the entities list
  {
    std::shared_ptr<Entity> rtn = std::make_shared<Entity>(); // local ptr using entity struct
    rtn->core = self; // core = self of entities
    rtn->self = rtn;
    rtn->alive = true;  //  knows the value of being alive
    
    rtn->addComponent<Transform>(); // returns the use of the add component function
    entities.push_back(rtn);  // adds to the back of the the entites vector

    return rtn; // return rtn
  }

  void Core::start()  // main gameloop
  {
    bool running = true;  // used to keep while loop open
    bool t = true;  // used to return a value to keyboard ( may be reworked )
    SDL_Event e = {0};
    
    while(running)  // main game loop
    {

      LAST = NOW;
      NOW = SDL_GetPerformanceCounter();
      deltaTime = ((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );
          
      while(SDL_PollEvent(&e) != 0) // polling sdl events
      {
        if(e.type == SDL_QUIT)  // if the event flags quit then it will  
        {
          running = false;  //  if running is false then game loop breaks
        }
        else if (e.type == SDL_KEYDOWN) //  if the key is down
        {
          //insert function for this 4 way if statement for this 4dir function?
          //  the bellow commented section needs to be reworked
          //if (e.key.keysym.sym == fetchKey->directionUp) fetchKey->rtnKey(t, NULL, NULL, NULL);
          //if (e.key.keysym.sym == fetchKey->directionDown) fetchKey->rtnKey(NULL, t, NULL, NULL);
          //if (e.key.keysym.sym == fetchKey->directionLeft) fetchKey->rtnKey(NULL, NULL, t, NULL); 
          //if (e.key.keysym.sym == fetchKey->directionRight) fetchKey->rtnKey(NULL, NULL, NULL, t);
        
          keymapping->keys.push_back(e.key.keysym.sym); //  testing if the key down is the same as that in the vector within keymapping.cpp
          keymapping->downKey.push_back(e.key.keysym.sym);  
        }
        else if(e.type == SDL_KEYUP)  // if the key is up
        {
          for(std::vector<int>::iterator it = keymapping->keys.begin(); it != keymapping->keys.end();)  // iterates through the vector
          {                                                                                             // from start till end of the vector
            if (*it == e.key.keysym.sym) it = keymapping->keys.erase(it); //  removes matching keys to the iterator
            else it++;  // if does not match then it continues through iteration
          }
          keymapping->upKey.push_back(e.key.keysym.sym);  //  adds the key to the list of up keys
        }         
      }
      
      for(size_t ei = 0; ei < entities.size(); ei++)
      {
        entities.at(ei)->tick();  // test bounds of ei in tick
      }

      for(size_t ei = 0; ei < entities.size(); ei++)
      {
        if(entities.at(ei)->alive == false) // if the entities is false
        {
          entities.erase(entities.begin() + ei);  // then it erases it
          ei--; // continues through testing
        }
      }

      glClearColor(0.39f, 0.58f, 0.93f, 1.0f);  //  clearing colour screens
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //  clear buffers

      for(size_t ci = 0; ci < cameras.size(); ci++) // goes through the cameras
      {
        currentCamera = cameras.at(ci); // current camera is taken from cameras list
        glClear(GL_DEPTH_BUFFER_BIT); // clear buffer

        for(size_t ei = 0; ei < entities.size(); ei++)
        {
          entities.at(ei)->render();  // renders entities into camera ( so we can see them  ) 
        }
      }

      SDL_GL_SwapWindow(window);  // make window THE window

      keymapping->downKey.clear();  // clear vectors for keyboard
      keymapping->upKey.clear();
    }
  }
}