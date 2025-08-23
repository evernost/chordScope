// ============================================================================
// Project        : chordScope
// Module name    : Synth
// File name      : Synth.cpp
// File type      : C++ 17
// Purpose        : synthesizer class for sinewave generation
// Author         : QuBi (nitrogenium@outlook.fr)
// Creation date  : August 5th, 2025
// ----------------------------------------------------------------------------
// Best viewed with space indentation (2 spaces)
// ============================================================================

// ============================================================================
// EXTERNALS
// ============================================================================
// Project libraries
#include "Synth.hpp"

// Standard libraries
// None.



// ----------------------------------------------------------------------------
// CLASS CONSTRUCTOR
// ----------------------------------------------------------------------------
Synth::Synth()
{
  std::memcpy(ratios, OVERTONE_PRESET_BELL, sizeof(ratios));
  amplitude[0] = 0.2;
  amplitude[1] = 0.1;
  amplitude[2] = 0.1;
  amplitude[3] = 0.1;
  amplitude[4] = 0.1;
  frequency = 440.0;
}



// ----------------------------------------------------------------------------
// METHOD Synth::setSampleRate()
// ----------------------------------------------------------------------------
void Synth::setSampleRate(double newSampleRate)
{
  sampleRate = newSampleRate;
}



// ----------------------------------------------------------------------------
// METHOD Synth::setFrequency()
// ----------------------------------------------------------------------------
void Synth::setFrequency(double f)
{
  frequency = f;
  // deltaPhase0 = juce::MathConstants<double>::twoPi * frequency / currentSampleRate;
  // deltaPhase1 = juce::MathConstants<double>::twoPi * 2.0 * frequency / currentSampleRate;
}



// ----------------------------------------------------------------------------
// METHOD Synth::renderNextBlock()
// ----------------------------------------------------------------------------
void Synth::renderNextBlock(juce::AudioBuffer<float>& buffer, int startSample, int nSamples)
{
  auto* left  = buffer.getWritePointer(0);
  auto* right = buffer.getWritePointer(1);

  

  //vca.getState()

  // Loop on the samples 
  for (int i = 0; i < nSamples; ++i)
  {    
    left[startSample+i]   = 0.0;
    right[startSample+i]  = 0.0;
    
    // Loop on the overtones
    for (int n = 0; n < N_OVERTONES; n++)
    {
      float sampleLeft  = (float)(amplitude[n]*std::sin(phase[n]));
      float sampleRight = (float)(amplitude[n]*std::sin(phase[n]));
      
      left[startSample + i]   += sampleLeft;
      right[startSample + i]  += sampleRight;

      // Increment the phase of this overtone
      phase[n] += juce::MathConstants<double>::twoPi*frequency*ratios[n]/sampleRate;
      if (phase[n] > juce::MathConstants<double>::twoPi)
        phase[n] -= juce::MathConstants<double>::twoPi;
    }
  }
}
