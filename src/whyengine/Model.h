/// \brief creates a friend to Renderer and loads the model.obj file
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENINGE_MODEL_H
#define WHYENGINE_MODEL_H

// system includes
#include <rend/rend.h>
#include <string>
#include <memory>

// header includes
#include "Asset.h"
#include "Exception.h"

namespace whyengine // namespace
{
  struct Renderer; // struct to allow access to the renderer structs

  struct Model : public Asset // inherhits from assets
  {
  public:
    void onLoad();  // load the model

  private:
    friend struct whyengine::Renderer;  // friend to allow access to varibles in the rendere .cpp.h files

    std::shared_ptr<rend::Mesh> mesh; // local value from the rend folder
  };
} 

#endif // _MODEL_H_