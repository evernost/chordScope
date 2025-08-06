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
// METHOD Synth::prepare()
// ----------------------------------------------------------------------------
void Synth::prepare(double sampleRate)
{
  currentSampleRate = sampleRate;
}



// ----------------------------------------------------------------------------
// METHOD Synth::setFrequency()
// ----------------------------------------------------------------------------
void Synth::setFrequency(double frequency)
{
  angleDelta = juce::MathConstants<double>::twoPi * frequency / currentSampleRate;
}



// ----------------------------------------------------------------------------
// METHOD Synth::renderNextBlock()
// ----------------------------------------------------------------------------
void Synth::renderNextBlock(juce::AudioBuffer<float>& buffer, int startSample, int numSamples)
{
  auto* left  = buffer.getWritePointer(0);
  auto* right = buffer.getWritePointer(1);

  for (int i = 0; i < numSamples; ++i)
  {
    float sample = (float)std::sin(currentAngle);
    currentAngle += angleDelta;

    left[startSample + i] = sample * 0.1f;
    right[startSample + i] = sample * 0.1f;
  }
}
