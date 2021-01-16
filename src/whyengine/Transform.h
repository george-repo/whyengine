/// \brief layouts baseline functions used in main to change the transform of an object.
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_TRANSFORM_H
#define WHYENGINE_TRANSFORM_H

// system includes
#include <rend/rend.h>

// header include
#include "Component.h"  // so transform struct is related to component struct

namespace whyengine // whyengine is the namespace used throughout
{
  struct Transform : public Component // transform struct casted from component struct
  {
  public:
    void onInitialize();  // initialize values in here
    void setPosition(rend::vec3 io_position); // io_ input and output parameter. Allows the position of object to be changed
    void translate(float io_x,  float io_y, float io_z);  // allows an object to be translated 
    void rotate(float io_x, float io_y, float io_z);  // allows an object to be rotated
    rend::mat4 getModel();  // fetches all transform data for a model

    rend::vec3 position;  // these three different vec3 store the transform data
    rend::vec3 rotation;
    rend::vec3 scale;
  };
}

#endif // _TRANSFORM_H_