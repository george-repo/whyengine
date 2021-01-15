///
///  @file  Keymapping.cpp
///  @brief itterates through the stored keymaps. 

#include "Keymapping.h"

namespace whyengine
{
  bool Keymap::setKeymap(int _keymap)
  {
    for(size_t ki = 0; ki < keys.size(); ki++)
    {
      if(keys.at(ki) == _keymap)
      {
        return true;
      }
    }
  return false;
  }
}