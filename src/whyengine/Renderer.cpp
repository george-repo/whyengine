///
///  @file Renderer.cpp
///  @brief contains the shader program, takes from rend and camera to render a grahical scene

// syystem include
#include <fstream>
#include <string>
#include <iostream>

// header include
#include "Renderer.h"
#include "Core.h"
#include "Transform.h"
#include "Entity.h"
#include "Camera.h"
#include "Model.h"

namespace whyengine // namespace
{
  void Renderer::onInitialize() // the values are initialized here (  values include the shader program )
  {
    std::cout << "Initializing" << std::endl;

    const char* src = // this is the start of the shader program starts with the vertex and then fragment shader
      "\n#ifdef VERTEX\n                       " \
      "attribute vec3 a_Position;              " \
      "attribute vec2 a_TexCoord;              " \
      "attribute vec3 a_Normal;                " \
      "uniform mat4 u_Projection;              " \
      "uniform mat4 u_View;                    " \
      "uniform mat4 u_Model;                   " \
      "varying vec2 v_TexCoord;                " \
      "                                        " \
      "void main()                             " \
      "{                                       " \
      "  gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1); " \
      "  v_TexCoord = a_TexCoord;              " \
      "  if(a_Normal.x == 9) gl_Position.x = 7;" \
      "}                                       " \
      "                                        " \
      "\n#endif\n                              " \
      "\n#ifdef FRAGMENT\n                     " \
      "uniform sampler2D u_Texture;            " \
      "varying vec2 v_TexCoord;                " \
      "                                        " \
      "void main()                             " \
      "{                                       " \
      "  gl_FragColor = vec4(v_TexCoord, 0, 1);" \
      "}                                       " \
      "                                        " \
      "\n#endif\n                              ";

    shader = getCore()->context->createShader();  // shader program gets passed into the rend librarby
    shader->parse(src); // parse the shader program to be use-able
  }

  void Renderer::onRender() // this dictates what happens when the render happens
  {
    if(!model) return; // if no model is present then render stops 
    
    shader->setMesh(model->mesh); // Model is how we use access from the Model.cpp, updating the mesh in Model.cpp/.h

    // the next 3 ->setUniforms is all about passing the camera, view, and model into the shader program
    shader->setUniform("u_Projection", rend::perspective(rend::radians(45.0f),
     1.0f, 0.1f, 100.0f));
    shader->setUniform("u_View", getCore()->getCamera()->getView());
    shader->setUniform("u_Model", getEntity()->getTransform()->getModel());

    std::shared_ptr<Camera> c = getCore()->getCamera(); // the initial camera to exist in scene 

    if(c->getRenderTexture()) // to determine the state of a render
    {
      shader->render(c->getRenderTexture());
    }
    else
    {
      shader->render();
    }
  }

  void Renderer::setModel(std::shared_ptr<Model> io_model)  // setting the io_model to the local model value
  {
    this->model = io_model; // setting the io_model to the local model value
  {
}