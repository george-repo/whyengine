///
///  @file Model.cpp
///  @brief Reads and cleans .obj files for use in scenes 


#include <rend/rend.h>
#include <iostream>
#include <fstream> 

#include "Core.h"
#include "Model.h"

namespace whyengine
{
  void Model::onLoad()
  {
    mesh = getCore()->context->createMesh();
    std::ifstream file(getPath() + ".obj");

    if(!file.is_open())
    {
      throw Exception("Failed to open model file");
    }

    std::string content;
    std::string line;

    while(!file.eof())
    {
      getline(file, line);
      content += line + "\n";
    }

    mesh->parse(content);
  }
}