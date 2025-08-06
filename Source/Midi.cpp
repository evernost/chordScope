// ============================================================================
// Project        : chordScope
// Module name    : Midi
// File name      : Midi.cpp
// File type      : C++ 17
// Purpose        : MIDI interface
// Author         : QuBi (nitrogenium@outlook.fr)
// Creation date  : August 6th, 2025
// ----------------------------------------------------------------------------
// Best viewed with space indentation (2 spaces)
// ============================================================================

// ============================================================================
// EXTERNALS
// ============================================================================
#include "Midi.hpp"



// ----------------------------------------------------------------------------
// CLASS CONSTRUCTOR
// ----------------------------------------------------------------------------
Midi::Midi()
{
  auto devices = juce::MidiInput::getAvailableDevices();
  if (!devices.isEmpty())
  {
    auto device = devices[0];
    midiInput = juce::MidiInput::openDevice(device.identifier, this);
    
    if (midiInput)
    {
      midiInput->start();
    }
  }
  else
  {
    std::cout << "[WARNING] No MIDI interface was found.";
  }
}



// ----------------------------------------------------------------------------
// CLASS DESTRUCTOR
// ----------------------------------------------------------------------------
Midi::~Midi()
{
  if (midiInput)
  {
    midiInput->stop();
  }
}



// ----------------------------------------------------------------------------
// METHOD Midi::setCallback()
// ----------------------------------------------------------------------------
void Midi::setCallback(std::function<void(int, float)> cb)
{
  noteOnCallback = cb;
}



// ----------------------------------------------------------------------------
// METHOD Midi::handleIncomingMidiMessage()
// ----------------------------------------------------------------------------
void Midi::handleIncomingMidiMessage(juce::MidiInput*, const juce::MidiMessage& msg)
{
  if (msg.isNoteOn() && noteOnCallback)
  {
    noteOnCallback(msg.getNoteNumber(), msg.getVelocity());
  }
}
