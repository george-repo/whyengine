///
///  @file  Keymapping.cpp
///  @brief itterates through the stored keymaps. 

// header includes
#include "Keymapping.h"

namespace whyengine // namspace 
{
  bool Keymap::setKeymap(int _keymap) // the start of the function _keymap is an input
  {
    for(size_t ki = 0; ki < keys.size(); ki++)  // for the range being smaller then the keys vector size
    {
      if(keys.at(ki) == _keymap)  // if the keys are equal to those on the keymap return true
      {                           // checks whether keys is within the bounds of valid elements
        return true;  // output if conditions are true
      }
    }
  return false; // output if conditions are false
  }
}