/// \brief loads the sound buffers and the sound file its self 
/// \author George Jennings
/// \version 1.0
/// \date 15/1/21 Updated to include NCCA standards
/// Revision History :
/// Initial Version pre 01/12/20
/// Final version 2/02/20
/// \todo ...

#ifndef WHYENGINE_SOUND_H
#define WHYENGINE_SOUND_H

//  system includes
#include <AL/al.h>

//  header includes
#include "Asset.h"

namespace whyengine //  namespace
{

  struct SoundSource; //  struct for the source of the sound

  struct Sound : public Asset
  {
    friend struct ::whyengine::SoundSource; //  making varibles usable from the SoundSource files

    void onLoad();  //  load function
    
    void loadOgg(const std::string& fileName, std::vector<char> &buffer, ALenum &format, ALsizei &freq);  //  load sound function

  private:
    ALuint id;  //  id of sound
  };
}

#endif  //  _SOUND_H_