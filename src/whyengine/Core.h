/// \brief this core file esentailly encapsulates all other files into one place
/// \author George Jennings
/// \version 0.9
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// Added keyboard sections in main loop 22/12/20
/// commented out keyboard sections in main loop 2/01/20
/// \todo rework the Keyboard to not be so inaccessible


#ifndef WHYENGINE_CORE_H
#define WHYENGINE_CORE_H

#include <SDL2/SDL.h>
#include <rend/rend.h>
#include <memory>
#include <vector>

namespace whyengine
{
  struct Renderer;
  struct Entity;
  struct Keyboard;
  struct Keymap;
  struct Camera;
  struct Assets;
  struct Model;

  struct Core
  {
  public:
    friend struct whyengine::Renderer;
    friend struct whyengine::Model;
    friend struct whyengine::Camera;

    static std::shared_ptr<Core> initialize();
    
    std::shared_ptr<Entity> addEntity();
    std::shared_ptr<Keymap> getKeymap();
    std::shared_ptr<Camera> getCamera();
    std::shared_ptr<Assets> getAssets();

    void start();
    
    std::shared_ptr<Keyboard> fetchKey;

  private:
    SDL_Window* window;
    SDL_GLContext glContext;

    std::shared_ptr<rend::Context> context;
    std::shared_ptr<Keymap> keymapping;
    std::shared_ptr<Assets> assets;

    std::weak_ptr<Camera> currentCamera;
    std::weak_ptr<Core> self;

    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::weak_ptr<Camera>> cameras;
  };

}
#endif // _CORE_H_