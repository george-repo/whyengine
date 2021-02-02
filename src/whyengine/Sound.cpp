///
///  @file  Sound.cpp
///  @brief This is the medium to load a sound and its type of sound .ogg format being used for project

//  header includes
#include "Sound.h"
#include "stb_vorbisg.h"  //  added a G on the end of this because the original header didnt
#include "Exception.h"

namespace whyengine
{
  void Sound::onLoad()  //  this function is used to handle the loading of the file its selfs
  {
    alGenBuffers(1, &id); //  generates the sound bufferss
    ALenum format = 0;
    ALsizei freq = 0;
    std::vector<char> bufferData;
    loadOgg(getPath() + ".ogg", bufferData, format, freq);  //  calls the function for loading the path
    alBufferData(id, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq); //  assign the data into the buffer
    bufferData.resize(bufferData.size() - bufferData.size() % 4); //  used to clamp the size of the buffer 
  }

  //  this function is used for handling the 
  void Sound::loadOgg(const std::string& fileName, std::vector<char> &buffer, ALenum &format, ALsizei &freq)
  {
    int channels = 0;
    int sampleRate = 0;

    short *output = NULL;

    size_t samples = stb_vorbis_decode_filename(fileName.c_str(), &channels, &sampleRate, &output);

    //  if the file can not be opened a exception is thrown
    if(samples == -1)
    {
      throw Exception("Failed to open file '" + fileName + "'");
    }

    //  record format
    if(channels == 1)
    {
      format = AL_FORMAT_MONO16;
    }
    else
    {
      format = AL_FORMAT_STEREO16;
    }
    
    //  record the sample rate
    freq = sampleRate;
    buffer.resize(samples * 2);
    memcpy(&buffer.at(0), output, buffer.size());

    //  clean up
    free(output);
  }
}