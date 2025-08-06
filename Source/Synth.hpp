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



// ============================================================================
// CLASS DEFINITION
// ============================================================================
class Synth
{
  public:
    void setFrequency(double frequency);  
    void setSampleRate(double sampleRate);
    void renderNextBlock(juce::AudioBuffer<float>& buffer, int startSample, int numSamples);
  
  private:
    double currentAngle = 0.0;
    double angleDelta = 0.0;
    double currentSampleRate = 44100.0;
};

