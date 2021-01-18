/// \brief Gathering of graphical objects to render into a scene.
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo add texture


#ifndef WHYENINGE_RENDERER_H
#define WHYENGINE_RENDERER_H

// system include
#include <rend/rend.h>
#include <memory>

// header include
#include "Component.h"

namespace whyengine // namspace
{
  struct Model; // to allow the use of the model struct

  struct Renderer : public Component // Renderer inherits from component
  {
  public:
    void onInitialize(); // values are initialized here
    void onRender();  // the start of the render
    void setModel(std::shared_ptr<Model> io_model); // sets the model in the shader program

  private:
    std::shared_ptr<rend::Shader> shader; // local values
    std::shared_ptr<Model> model;
  };
}

#endif // _RENDERER_H_