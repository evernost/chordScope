#include "MidiInterface.hpp"

MidiManager::MidiManager()
{
  auto devices = juce::MidiInput::getAvailableDevices();
  if (!devices.isEmpty())
  {
    auto device = devices[0];
    midiInput = juce::MidiInput::openDevice(device.identifier, this);
    if (midiInput)
        midiInput->start();
  }
}

MidiManager::~MidiManager()
{
  if (midiInput)
  {
    midiInput->stop();
  }
}

void MidiManager::setCallback(std::function<void(int, float)> cb)
{
  noteOnCallback = cb;
}

void MidiManager::handleIncomingMidiMessage(juce::MidiInput*, const juce::MidiMessage& msg)
{
  if (msg.isNoteOn() && noteOnCallback)
  {
    noteOnCallback(msg.getNoteNumber(), msg.getVelocity());
  }
}
