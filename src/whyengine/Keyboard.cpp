#include "Keyboard.h"
#include "Core.h"
#include "Transform.h"
#include <iostream>

namespace whyengine
{

    void Keyboard::directionalMovement(char up, char down, char left, char right, float speed)
    {
        directionUp = up; directionDown = down; 
        directionLeft = left; directionRight = right;    
        rtnSpeed = speed;   
    }

    void Keyboard::rtnKey(bool up, bool down, bool left, bool right)
    {
        rend::vec3 velocity(0.0f,0.0f, 0.0f);
        if(up)    velocity.y += rtnSpeed;
        if(down)  velocity.y -= rtnSpeed;
        if(left)  velocity.x -= rtnSpeed;
        if(right) velocity.x += rtnSpeed;
        getTransform()->position += velocity;
    }
}