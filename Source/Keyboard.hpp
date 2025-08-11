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

#define WHITE_NOTE_COLOR (juce::Colours::white)
#define BLACK_NOTE_COLOR (juce::Colours::darkblue)

#define NOTE_C_MOD12 0
#define NOTE_Db_MOD12 1
#define NOTE_D_MOD12 2
#define NOTE_Eb_MOD12 3
#define NOTE_E_MOD12 4
#define NOTE_F_MOD12 5
#define NOTE_Gb_MOD12 6
#define NOTE_G_MOD12 7
#define NOTE_Ab_MOD12 8
#define NOTE_A_MOD12 9
#define NOTE_Bb_MOD12 10
#define NOTE_B_MOD12 11

#define NOTE_LOWEST_A 21
#define NOTE_LOWEST_Bb 22
#define NOTE_LOWEST_B 23



// ============================================================================
// CLASS DEFINITION
// ============================================================================
class Keyboard : public juce::Component
{
  public:
    void paint(juce::Graphics& g) override;
    void setNotePlayed(int);
    void setMidiDeviceName(juce::String);

  private:
    void _renderNotes(juce::Graphics&);
    void _renderInput(juce::Graphics&);
    int midiCurrentNote = -1;
    juce::String midiDeviceName;
};

// 'Keyboard' or 'IvoryLines'?

