/// \brief One movement function.
/// \author George Jennings
/// \version 0.1 alpha version 
/// \date 15/1/21 added coding standards
/// Revision History :
/// Initial Version ../12/20
/// \todo a complete rework this to be more private AND accessible within main to cut down on complexity


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

#endif // _KEYBOARD_H_