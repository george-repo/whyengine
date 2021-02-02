/// \brief this core file esentailly encapsulates all other files into one place
/// \author George Jennings
/// \version 0.9
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// Added keyboard sections in main loop 22/12/20
/// commented out keyboard sections in main loop 2/01/20
/// added audio initialize  2/02/20
/// \todo rework the Keyboard to not be so inaccessible

#ifndef WHYENGINE_CORE_H
#define WHYENGINE_CORE_H

// system includes
#include <SDL2/SDL.h>
#include <rend/rend.h>
#include <memory>
#include <vector>
#include <iostream>
#include <AL/al.h>
#include <AL/alc.h>

namespace whyengine // namespace
{
  // core being the centre of attention means it needs to attract allot of different structs
  struct Renderer;
  struct Entity;
  struct Keyboard;
  struct Keymap;
  struct Camera;
  struct Assets;
  struct Model;
  struct Collision;
  
  struct Core // main struct of core
  {
  public:
    friend struct whyengine::Renderer;  // core has many friends to improve accessiblity and encapsulation
    friend struct whyengine::Model;
    friend struct whyengine::Camera;
    friend struct whyengine::Collision;

    static std::shared_ptr<Core> initialize(int windowWidth, int windowHeight);  // static initialize (  think of it as the god initlize function of the engine)
    
    std::shared_ptr<Entity> addEntity();  // basic functions that allow the differnt getting or adding of different components
    std::shared_ptr<Keymap> getKeymap();  
    std::shared_ptr<Camera> getCamera();
    std::shared_ptr<Assets> getAssets();

    void start(); // this is the main game loop
    
    std::shared_ptr<Keyboard> fetchKey; // used for keyboard (  maybe redundent )
    
    //  added a delta time very simplier using SDL feature
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    //  used for the IDs of entity
    int current_id = -100;
    int GetID() { current_id++; return current_id - 1; }
      
    std::vector<std::shared_ptr<Entity>> entities;  // vector with a shared ptr parameter
    std::vector<std::shared_ptr<Collision>> colliderList;  // vector with a shared ptr parameter


  private:
    // basic SDL varibles 
    SDL_Window* window;
    SDL_GLContext glContext;

    // basic openAL varibles
    ALCdevice* device;
    ALCcontext* alContext;

    std::shared_ptr<rend::Context> context; // context used from the rend library
    std::shared_ptr<Keymap> keymapping; // a local shared ptr to be used in core
    std::shared_ptr<Assets> assets;

    std::weak_ptr<Camera> currentCamera;  // weak_ptr so that they can break
    std::weak_ptr<Core> self;

    std::vector<std::weak_ptr<Camera>> cameras; // vector with a weak ptr parameter
  };

}
#endif // _CORE_H_