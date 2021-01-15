/// \brief creates a friend to Renderer and loads the model.obj file
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENINGE_MODEL_H
#define WHYENGINE_MODEL_H

#include <rend/rend.h>
#include <string>
#include <memory>

#include "Asset.h"
#include "Exception.h"

namespace whyengine
{
  struct Renderer;

  struct Model : public Asset
  {
  public:
    void onLoad();

  private:
    friend struct whyengine::Renderer;

    std::shared_ptr<rend::Mesh> mesh;
  };
} 

#endif // _MODEL_H_