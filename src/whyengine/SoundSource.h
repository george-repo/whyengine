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

#endif