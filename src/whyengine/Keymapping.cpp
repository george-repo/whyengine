#include "Keymapping.h"

namespace whyengine
{
  bool Keymap::setKeymap(int keymap)
  {
    for(size_t ki = 0; ki < keys.size(); ki++)
    {
      if(keys.at(ki) == keymap)
      {
        return true;
      }
    }
  return false;
  }
}