#include "MatlabFFT.hpp"

MatlabFFT::MatlabFFT()
{
   //constructor
}

MatlabFFT::~MatlabFFT()
{
   //destructor
}

void MatlabFFT::CalculateFFT(WindowType type, double freq, double amp)
{
  std::ofstream outfile ("fft.csv");

  /////////////// OUTPUTS /////////////////
  //Header for output CSV
  outfile << "Random Output" << std::endl;  
  //Values for output CSV
  outfile << amp * freq << std::endl;  
  outfile.close();
  /////////////////////////////////////////
}
