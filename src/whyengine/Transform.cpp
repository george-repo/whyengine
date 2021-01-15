///
///  @file Transform.cpp
///  @brief Create and store transform information for assigned object

#include "Transform.h"

namespace whyengine
{
  void Transform::onInitialize()
  {
    scale = rend::vec3(1, 1, 1);
  }

  rend::mat4 Transform::getModel()
  {
    rend::mat4 rtn(1.0f);

    rtn = rend::translate(rtn, position);
    rtn = rend::rotate(rtn, rotation.x, rend::vec3(1,0,0));
    rtn = rend::rotate(rtn, rotation.y, rend::vec3(0,1,0));
    rtn = rend::rotate(rtn, rotation.z, rend::vec3(0,0,1));
    rtn = rend::scale(rtn, scale);

    return rtn;
  }

  void Transform::setPosition(rend::vec3 io_position)
  {
    this->position = io_position;
  }
      
  void Transform::rotate(float io_x, float io_y, float io_z)
  {
    this->rotation += rend::vec3(io_x, io_y, io_z);
  }

  void Transform::translate(float io_x, float io_y, float io_z)
  {
    rend::vec4 fwd = getModel() * rend::vec4(io_x, io_y, io_z, 0);
    position += rend::vec3(fwd);
  }
}