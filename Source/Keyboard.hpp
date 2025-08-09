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
// CONSTANTS
// ============================================================================
#define KEYBOARD_WHITE_NOTE_HEIGHT 150
#define KEYBOARD_WHITE_NOTE_WIDTH 25
#define KEYBOARD_BLACK_NOTE_HEIGHT 100
#define KEYBOARD_BLACK_NOTE_WIDTH 12    // Use a multiple of 6 to avoid 'un-eveness' in the display (rounding effect) 
#define KEYBOARD_NOTE_CHANFER 2
#define KEYBOARD_NOTE_SPACING 1



// ============================================================================
// CLASS DEFINITION
// ============================================================================
class Keyboard : public juce::Component
{
  public:
    void paint(juce::Graphics& g) override;
    void setNotePlayed(int midiNote);
    void setMidiDeviceName(juce::String dev);

  private:
    int currentNote = -1;
    juce::String deviceName;
};

// 'Keyboard' or 'IvoryLines'?

