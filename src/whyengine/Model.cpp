///
///  @file Model.cpp
///  @brief Reads and cleans .obj files for use in scenes 

// system include
#include <rend/rend.h>
#include <iostream>
#include <fstream> 

//header include
#include "Core.h" // core is needed here to allow the use of getCore() function
#include "Model.h"

namespace whyengine // namespace
{
  void Model::onLoad() // the function to load and read the file
  {
    mesh = getCore()->context->createMesh();
    std::ifstream file(getPath() + ".obj"); // this gets the model path

    if(!file.is_open()) // exception if model could not be opened
    {
      throw Exception("Failed to open model file"); // the exception message
    }

    std::string content;  // local values to manipulate the file data
    std::string line;

    while(!file.eof())  // the manipulation takes place here by reading through each line 
    {
      getline(file, line);  // the file and the plae to store the lines using fstream
      content += line + "\n";
    }

    mesh->parse(content); // parse the data from this to reconstruct it, same parse as the one in renderer
  }
}