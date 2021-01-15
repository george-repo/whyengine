/// \brief Gathering of graphical objects to render into a scene.
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...


#ifndef WHYENINGE_RENDERER_H
#define WHYENGINE_RENDERER_H

#include <rend/rend.h>
#include <memory>

#include "Component.h"

namespace whyengine
{
  struct Model;

  struct Renderer : public Component
  {
  public:
    void onInitialize();
    void onRender();
    void setModel(std::shared_ptr<Model> io_model);

  private:
    std::shared_ptr<rend::Shader> shader;
    std::shared_ptr<Model> model;
  };
}

#endif // _RENDERER_H_