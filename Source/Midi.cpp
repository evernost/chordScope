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
    deviceName = device.name;
    
    if (midiInput)
    {
      midiInput->start();
    }
  }
  else
  {
    DBG("[WARNING] No MIDI interface was found.");
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
// METHOD Midi::setCallbacks()
// ----------------------------------------------------------------------------
void Midi::setCallbacks(std::function<void(int, float)> noteEvent, std::function<void(int, int)> ctrlEvent)
{
  clbk_noteEvent = noteEvent;
  clbk_ctrlEvent = ctrlEvent;
}



// ----------------------------------------------------------------------------
// METHOD Midi::handleIncomingMidiMessage()
// ----------------------------------------------------------------------------
void Midi::handleIncomingMidiMessage(juce::MidiInput*, const juce::MidiMessage& msg)
{
  if (msg.isNoteOn() && clbk_noteEvent)
  {
    clbk_noteEvent(msg.getNoteNumber(), msg.getVelocity());
  }

  if (msg.isNoteOff() && clbk_noteEvent)
  {
    clbk_noteEvent(msg.getNoteNumber(), 0);
  }

  if (msg.isController() && clbk_ctrlEvent)
  {
    clbk_ctrlEvent(msg.getControllerNumber(), msg.getControllerValue());
  }

  if (msg.isPitchWheel() && clbk_ctrlEvent)
  {
    //clbk_ctrlEvent(getPitchWheelValue());
  }
}
