#ifndef WHYENGINE_KEYBOARD_H
#define WHYENGINE_KEYBOARD_H

#include "Component.h"

namespace whyengine
{       
    struct Keyboard : public Component 
    {
        char directionUp; char directionDown; char directionLeft; char directionRight;
        float rtnSpeed; 
        void directionalMovement(char up, char down, char left, char right, float speed);
        void rtnKey(bool up, bool down, bool left, bool right);
    };
}

#endif