///
///  @file Transform.cpp
///  @brief Create and store transform information for assigned object

#include "Transform.h"  // using the header file
#include "Core.h"
#include <iostream>
#include "Collision.h"
#include "Entity.h"

namespace whyengine // namespace
{
  void Transform::onInitialize()  // initialize values ( scale is being used here )
  {
    scale = rend::vec3(1, 1, 1);  // scale from header is a vec3 now with 1, 1, 1 as its values
    mass = 0.0f;
    gravity = true;
  }

  void Transform::setPosition(rend::vec3 io_position) // io_ input and output 
  {
    this->position = io_position; // assign object position to new io_position using "this->""
  }

  void Transform::setScale(rend::vec3 io_scale) // io_ input and output 
  {
    this->scale = io_scale; // assign object scale to new io_scale using "this->""
  }

  void Transform::rotate(float io_x, float io_y, float io_z)
  {
    this->rotation += rend::vec3(io_x, io_y, io_z); // assign objects rotation to new rotation.
  }

  void Transform::translate(float io_x, float io_y, float io_z)
  {
    rend::vec4 fwd = getModel() * rend::vec4(io_x, io_y, io_z, 0); // assign a models translation 
    position += rend::vec3(fwd);  // move the model via translation from old position to new translation position
  }

  rend::mat4 Transform::getModel() // getting all of the model transform data to store in matrix
  {
    rend::mat4 rtn(1.0f); // matrix initialized here to be returned

    rtn = rend::translate(rtn, position); // adding a collection of values to matrix
    rtn = rend::rotate(rtn, rotation.x, rend::vec3(1, 0, 0));
    rtn = rend::rotate(rtn, rotation.y, rend::vec3(0, 1, 0));
    rtn = rend::rotate(rtn, rotation.z, rend::vec3(0, 0, 1));
    rtn = rend::scale(rtn, scale);

    return rtn;
  }

  void Transform::onTick()
  {
    if(gravity)
    {
      if(position.y > 0.01)
      {
        velocity.y = (mass / g) * getCore()->deltaTime;
        position.y += velocity.y;
      }
      else
      {
        velocity.y = 0;
      }
    }
  }
}