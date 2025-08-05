#pragma once

#include <JuceHeader.h>
#include "MidiInterface.hpp"
#include "Synth.hpp"
#include "Custom.hpp"

class MainComponent : public juce::AudioAppComponent
{
public:
    MainComponent();
    ~MainComponent() override;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo&) override;
    void releaseResources() override;

    void resized() override;

private:
    MidiManager midiManager;
    SineSynth synth;
    CustomComponent gui;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};