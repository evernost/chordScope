// ============================================================================
// Project        : chordScope
// Module name    : Synth
// File name      : Synth.hpp
// File type      : C++ 17
// Purpose        : synthesizer class for sinewave generation
// Author         : QuBi (nitrogenium@outlook.fr)
// Creation date  : August 5th, 2025
// ----------------------------------------------------------------------------
// Best viewed with space indentation (2 spaces)
// ============================================================================
#pragma once

// ============================================================================
// EXTERNALS
// ============================================================================
#include <JuceHeader.h>

#define N_OVERTONES 12

const double OVERTONE_PRESET_HARM[N_OVERTONES] = {1.000, 2.000, 3.000, 4.000, 5.000, 6.000, 7.000, 8.000, 9.000, 10.000, 11.000, 12.000};
const double OVERTONE_PRESET_BELL[N_OVERTONES] = {1.000, 0.500, 1.183, 1.506, 2.000, 2.514, 2.662, 3.011, 4.166, 5.433, 6.796, 8.215};




// ============================================================================
// CLASS DEFINITION
// ============================================================================
class Synth
{
  public:
    Synth();
    void setFrequency(double frequency);  
    void setSampleRate(double sampleRate);
    void renderNextBlock(juce::AudioBuffer<float>& buffer, int startSample, int numSamples);
    double volume;
  
  private:
    double frequency;
    double phase[N_OVERTONES] = {0.0};
    double ratios[N_OVERTONES] = {0.0};
    double amplitude[N_OVERTONES] = {0.0};
    double sampleRate = 44100.0;
};

