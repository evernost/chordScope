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
class Keyboard : public juce::Component
{
  public:
    void paint(juce::Graphics& g) override;
    void setNotePlayed(int midiNote);

  private:
    int currentNote = -1;
};

// 'Keyboard' or 'IvoryLines'?

