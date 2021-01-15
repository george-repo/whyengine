///
///  @file  Camera.cpp
///  @brief Ties in a few of the other files and functions to create the camera system.

#include "Camera.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

namespace whyengine
{
  void Camera::onInitialize()
  {
    std::shared_ptr<Camera> self = getEntity()->getComponent<Camera>();
    getCore()->cameras.push_back(self);
  }

  rend::mat4 Camera::getView()
  {
    return rend::inverse(getTransform()->getModel());
  }

  std::shared_ptr<rend::RenderTexture> Camera::getRenderTexture()
  {
    return renderTexture;
  }

  std::shared_ptr<rend::RenderTexture> Camera::addRenderTexture()
  {
    renderTexture = getCore()->context->createRenderTexture();

    return renderTexture;
  }
}