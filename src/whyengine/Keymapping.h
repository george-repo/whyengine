/// \brief creates a friend to Core and it stores set keys to be used in core.
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_KEYMAPPING_H
#define WHYENGINE_KEYMAPPING_H

// system includes
#include <vector>

namespace whyengine // namespace 
{
  struct Core;  // allows access to core functions and varibles

  struct Keymap   
  {
  public:
    bool setKeymap(int _keymap);  // _keymap is a input only function parameter

  private:
    friend struct whyengine::Core;  // friend of core

    std::vector<int> keys;    // the keymap as a collective stored in a vector
    std::vector<int> downKey; // what keys are down
    std::vector<int> upKey;   // what keys are up
  };
}

#endif // _KEYMAPPING_H_