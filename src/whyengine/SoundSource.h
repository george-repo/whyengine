/// \brief manages the buffers for the sounds
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// Final version 2/02/20
/// \todo ...

#ifndef WHYENGINE_SOUNDSOURCE_H
#define WHYENGINE_SOUNDSOURCE_H

#include <memory>
#include "Sound.h"
#include "Component.h"

namespace whyengine
{
  struct Sound;
  struct SoundSource : public Component
  {
    void onInitialize(std::shared_ptr<Sound> sound);
    void onTick();
    void onDestroy();
  private:
    ALuint sid;
  };
}

#endif  //  _SOUNDSOURCE_H_