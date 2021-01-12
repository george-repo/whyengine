#include "Core.h"
#include "Model.h"

#include <rend/rend.h>
#include <iostream>
#include <fstream>

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