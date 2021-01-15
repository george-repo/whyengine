/// \brief layouts baseline functions used in main to change the transform of an object.
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...


#ifndef WHYENGINE_TRANSFORM_H
#define WHYENGINE_TRANSFORM_H

#include <rend/rend.h>
#include "Component.h"

namespace whyengine
{
  struct Transform : public Component
  {
  public:
    void onInitialize();
    void setPosition(rend::vec3 io_position);
    void translate(float io_x, float io_y, float io_z);
    void rotate(float io_x, float io_y, float io_z);
    rend::mat4 getModel();

    rend::vec3 position;
    rend::vec3 rotation;
    rend::vec3 scale;
  };
}

#endif // _TRANSFORM_H_