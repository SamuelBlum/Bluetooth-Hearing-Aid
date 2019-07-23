#include <iostream>
#include <fstream>
#include <string>
#include "MatlabFFT.hpp"
#include "ReadAudio.hpp"

using namespace std;

int main () {

  ///// Inputs /////
  double Fs;
  double T;
  double freq;
  int bits;
  double amp;
  string Fname;
  double PeriodsToPlot;
  int Mute;
  const char * audioFile;
  //////////////////

  // Define input/output files
  ifstream infile ("parameters.txt");

  MatlabFFT matlab;
  matlab.type = MatlabFFT::HANNING;
  ReadAudio audio;

  //Read parameters and set their values
  string value;
  if (infile.is_open())
  {
    while ( getline (infile,value) )
    {
      string delimiter = " = ";
      size_t pos = 0;
      string parameter;
      while ((pos = value.find(delimiter)) != string::npos) 
      {
        parameter = value.substr(0, pos);
        if (parameter == "Fs")
        {
          Fs = stod(value.erase(0, pos + delimiter.length()));
          cout << Fs << endl;
        }
        else if (parameter == "T") 
        {
          T = stod(value.erase(0, pos + delimiter.length()));
          cout << T << endl;
        }
        else if (parameter == "freq") 
        {
          freq = stod(value.erase(0, pos + delimiter.length()));
          cout << freq << endl;
        }
        else if (parameter == "bits") 
        {
          bits = stoi(value.erase(0, pos + delimiter.length()));
          cout << bits << endl;
        }
        else if (parameter == "amp") 
        {
          amp = stod(value.erase(0, pos + delimiter.length()));
          cout << amp << endl;
        }
        else if (parameter == "Fname") 
        {
          Fname = value.erase(0, pos + delimiter.length());
          cout << Fname << endl;
        }
        else if (parameter == "PeriodsToPlot") 
        {
          PeriodsToPlot = stod(value.erase(0, pos + delimiter.length()));
          cout << PeriodsToPlot << endl;
        }
        else if (parameter == "Mute") 
        {
          Mute = stoi(value.erase(0, pos + delimiter.length()));
          cout << Mute << endl;
        }
        else if (parameter == "audioFile") 
        {
          audioFile = "audio.wav";//value.erase(0, pos + delimiter.length());
          cout << audioFile << endl;
        }
        else
        {
          cout << "misnamed parameter: " << parameter << endl;
          break;
        }
      }
    }
    infile.close();
  }
  else
  {
     cout << "Unable to open file" << endl;
  }
  ////////////////////////////////////////

  // FFT routine
  audio.WavToFFT(audioFile);
  matlab.CalculateFFT(matlab.type, freq, amp);
  //////////////

  return 0;
}