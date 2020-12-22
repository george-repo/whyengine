#ifndef WHYENINGE_RENDERER_H
#define WHYENGINE_RENDERER_H

#include "Component.h"

#include <rend/rend.h>

#include <memory>

namespace whyengine
{
  struct Renderer : public Component
  {
    void onInitialize();
    void onRender();

  private:
    std::shared_ptr<rend::Shader> shader;
    std::shared_ptr<rend::Buffer> shape;
  };
}
#endif