#ifndef MATLAB_FFT_HPP
#define MATLAB_FFT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "WindowFunction.hpp"

class MatlabFFT
{
public:

   std::string Fname; // file name of the wav file. 
   int SliceSamples; // run FFT every x samples. 

   enum WindowType
      {
         HANNING,
         NONE,
         RECTANGULAR,
         BOXCAR
      };

   WindowType type;

   int FFTsize; // FFT length
   double fillValue; // dB fill value in matrix

   MatlabFFT();
   
   virtual ~MatlabFFT();

   void CalculateFFT(WindowType type, double freq, double amp);

};

#endif
