/// \brief creates a friend to Core and it stores set keys to be used in core.
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// \todo ...

#ifndef WHYENGINE_KEYMAPPING_H
#define WHYENGINE_KEYMAPPING_H

#include <vector>

namespace whyengine
{
  struct Core;

  struct Keymap   
  {
  public:
    bool setKeymap(int _keymap);

  private:
    friend struct whyengine::Core;

    std::vector<int> keys;
    std::vector<int> downKey;
    std::vector<int> upKey;
  };
}

#endif // _KEYMAPPING_H_