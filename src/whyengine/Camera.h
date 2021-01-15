/// \brief The outlining of the camera system with a child struct of the CES (Component struct)
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_CAMERA_H
#define WHYENGINE_CAMERA_H

#include "Component.h"
#include <rend/rend.h>

namespace whyengine
{
  struct Camera : public Component
  {
  public:
    void onInitialize();
    rend::mat4 getView();
    std::shared_ptr<rend::RenderTexture> getRenderTexture();
    std::shared_ptr<rend::RenderTexture> addRenderTexture();

  private:
    std::shared_ptr<rend::RenderTexture> renderTexture;
  };
}

#endif // _CAMERA_H_