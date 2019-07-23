#ifndef WINDOW_FUNCTION_HPP
#define WINDOW_FUNCTION_HPP

#include <iostream>
#include <fstream>
#include <string>

class WindowFunction
{
public:
   
   WindowFunction();
   
   virtual ~WindowFunction();

   double NormConst;
   void Hanning(double freq, double amp);
   void Boxcar(double freq, double amp);
   void Rectangular(double freq, double amp);

};

#endif
