// ============================================================================
// Project        : chordScope
// Module name    : MainComponent
// File name      : MainComponent.hpp
// File type      : C++ 17
// Purpose        : 
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
#include <functional>



// ============================================================================
// CLASS DEFINITION
// ============================================================================
class Midi : public juce::MidiInputCallback
{
  public:
    Midi();
    ~Midi();

    void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override;
    void setCallback(std::function<void(int note, float velocity)> cb);

  private:
    std::function<void(int, float)> noteOnCallback;
    std::unique_ptr<juce::MidiInput> midiInput;
};

