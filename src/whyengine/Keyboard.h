/// \brief One movement function.
/// \author George Jennings
/// \version 0.1 alpha version 
/// \date 15/1/21 added coding standards
/// Revision History :
/// Initial Version ../12/20
/// \todo a complete rework this to be more private AND accessible within main to cut down on complexity

#ifndef WHYENGINE_KEYBOARD_H
#define WHYENGINE_KEYBOARD_H

// header includes
#include "Component.h"  // need to make use of the Component struct

namespace whyengine
{   
    struct Keyboard : public Component  // inherits from component
    {
        char directionUp; char directionDown; char directionLeft; char directionRight;  // values
        float rtnSpeed; 
        void directionalMovement(char up, char down, char left, char right, float speed); // function for user in main to pass keys and speed
        void rtnKey(bool up, bool down, bool left, bool right); // this is to be used in the core file
    };
}

#endif // _KEYBOARD_H_