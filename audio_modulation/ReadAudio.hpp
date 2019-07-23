#ifndef READ_AUDIO_HPP
#define READ_AUDIO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sndfile.h>
#include <sndfile.hh>

class ReadAudio
{
public:
   
   ReadAudio();
   
   virtual ~ReadAudio();

   void WavToFFT(const char * audioFile);

};

#endif
