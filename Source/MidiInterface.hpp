#pragma once

#include <JuceHeader.h>
#include <functional>

class MidiManager : public juce::MidiInputCallback
{
public:
    MidiManager();
    ~MidiManager();

    void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override;
    void setCallback(std::function<void(int note, float velocity)> cb);

private:
    std::function<void(int, float)> noteOnCallback;
    std::unique_ptr<juce::MidiInput> midiInput;
};
#pragma once
