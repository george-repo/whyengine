#ifndef WHYENGINE_SOUND_H
#define WHYENGINE_SOUND_H

#include "Asset.h"
#include <AL/al.h>

namespace whyengine 
{

  struct SoundSource;

  struct Sound : public Asset
  {
    friend struct ::whyengine::SoundSource;

    void onLoad();
    
    void loadOgg(const std::string& fileName, std::vector<char> &buffer, ALenum &format, ALsizei &freq);

  private:
    ALuint id;
  };
}


#endif