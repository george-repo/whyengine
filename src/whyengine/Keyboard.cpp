// lots to change about this file so it may not have many comments
#include <iostream>

#include "Keyboard.h"
#include "Core.h"
#include "Transform.h"
#include "Entity.h"

namespace whyengine
{
    // this is essentially an initilize function
    void Keyboard::directionalMovement(char up, char down, char left, char right, float speed)
    {
        directionUp = up; directionDown = down; 
        directionLeft = left; directionRight = right;    
        rtnSpeed = speed;
    }

    void Keyboard::rtnKey(bool up, bool down, bool left, bool right)
    {
        rend::vec3 velocity(0.0f,0.0f, 0.0f); // changing the values based on input
        if(up)    velocity.y += rtnSpeed;
        if(down)  velocity.y -= rtnSpeed;
        if(left)  velocity.x -= rtnSpeed;
        if(right) velocity.x += rtnSpeed;
        getTransform()->position += velocity; // setting new position
    }
}

/// THIS WILL BE REWORKED INTO A NEW FILE FOR PHYSICS...