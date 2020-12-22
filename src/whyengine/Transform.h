#ifndef WHYENGINE_TRANSFORM_H
#define WHYENGINE_TRANSFORM_H

#include "Component.h"

#include <rend/rend.h>

namespace whyengine
{
    struct Transform : public Component
    {
        void onInitialize();

        rend::mat4 getModel();
        void setPosition(rend::vec3 position);

    public:
        rend::vec3 position;
        rend::vec3 rotation;
        rend::vec3 scale;
    };
}

#endif