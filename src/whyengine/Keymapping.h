#ifndef WHYENGINE_KEYMAPPING_H
#define WHYENGINE_KEYMAPPING_H

#include <vector>

namespace whyengine
{
  struct Core;

  struct Keymap   
  {
    bool getKeymap(int keymap);

    private:
      friend struct whyengine::Core;

      std::vector<int> keys;
      std::vector<int> downKey;
      std::vector<int> upKey;
  };
}

#endif