#include "Transform.h"

namespace whyengine
{
    void Transform::onInitialize()
    {
        scale = rend::vec3(1,1,1);
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

    void Transform::setPosition(rend::vec3 position)
    {
        this->position = position;
    }
}