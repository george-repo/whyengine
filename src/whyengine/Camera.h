/// \brief The outlining of the camera system with a child struct of the CES (Component struct)
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_CAMERA_H
#define WHYENGINE_CAMERA_H

// system include
#include <rend/rend.h>

// header include
#include "Component.h"

namespace whyengine // namespace
{
  struct Camera : public Component // encapsulation and inhertience of component
  {
  public:
    void onInitialize();  // initialize the camera values
    rend::mat4 getView(); // the mat4 is the view matrix
    std::shared_ptr<rend::RenderTexture> getRenderTexture();  // gets the texture for render
    std::shared_ptr<rend::RenderTexture> addRenderTexture();  // adds said texture

  private:
    std::shared_ptr<rend::RenderTexture> renderTexture; // local value
  };
}

#endif // _CAMERA_H_