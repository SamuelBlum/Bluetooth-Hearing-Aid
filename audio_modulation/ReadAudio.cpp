#include "ReadAudio.hpp"

#include    <cstdio>
#include    <cstring>

ReadAudio::ReadAudio()
{
   //constructor
}

ReadAudio::~ReadAudio()
{
   //destructor
}

void ReadAudio::WavToFFT(const char * audioFile)
{
 
    SndfileHandle file;

    file = SndfileHandle(audioFile);

    //printf ("Opened file '%s'\n", audioFile) ;
    //printf ("    Sample rate : %d\n", file.samplerate ()) ;
    //printf ("    Channels    : %d\n", file.channels ()) ;

    //file.read (buffer, BUFFER_LEN) ;

}
