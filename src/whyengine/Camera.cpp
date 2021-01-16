///
///  @file  Camera.cpp
///  @brief Ties in a few of the other files and functions to create the camera system.

// camera is the eye requires more header includes then most
#include "Camera.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

namespace whyengine // namespace
{
  void Camera::onInitialize() // initialize the camera values
  {
    std::shared_ptr<Camera> self = getEntity()->getComponent<Camera>(); //  adding the camera shared ptr to now be a component
    getCore()->cameras.push_back(self); // adds cameara to its own vector
  }

  rend::mat4 Camera::getView()  // this gets the view
  {
    return rend::inverse(getTransform()->getModel()); // the camera is the inverse of the model
  }

  std::shared_ptr<rend::RenderTexture> Camera::getRenderTexture() //  makes use of the rend library for texture
  {
    return renderTexture; // returns that local varible
  }

  std::shared_ptr<rend::RenderTexture> Camera::addRenderTexture()
  {
    renderTexture = getCore()->context->createRenderTexture();  // gets the core context to render the newly assigned texture

    return renderTexture; // returns that local varible
  }
}