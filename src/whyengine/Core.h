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
    friend struct whyengine::Renderer;
    friend struct whyengine::Model;
    friend struct whyengine::Camera;

    static std::shared_ptr<Core> initialize();
    
    std::shared_ptr<Entity> addEntity();
    std::shared_ptr<Keymap> getKeymap();
    std::shared_ptr<Camera> getCamera();
    std::shared_ptr<Assets> getAssets();

    void start();
    
  public:
    std::shared_ptr<Keyboard> fetchKey;
  private:
    std::vector<std::shared_ptr<Entity>> entities;

    std::weak_ptr<Core> self;
    SDL_Window* window;
    SDL_GLContext glContext;
    std::shared_ptr<rend::Context> context;
    std::shared_ptr<Keymap> keymapping;
    std::shared_ptr<Assets> assets;
    std::weak_ptr<Camera> currentCamera;
    std::vector<std::weak_ptr<Camera>> cameras;
  };

}
#endif