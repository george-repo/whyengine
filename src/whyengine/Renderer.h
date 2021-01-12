#ifndef WHYENINGE_RENDERER_H
#define WHYENGINE_RENDERER_H

#include "Component.h"

#include <rend/rend.h>

#include <memory>

namespace whyengine
{
  struct Model;

  struct Renderer : public Component
  {
    void onInitialize();
    void onRender();
    void setModel(std::shared_ptr<Model> model);

  private:
    std::shared_ptr<rend::Shader> shader;
    std::shared_ptr<Model> model;
  };
}
#endif