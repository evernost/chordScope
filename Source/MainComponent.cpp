#include "MainComponent.hpp"

MainComponent::MainComponent()
{
  addAndMakeVisible(gui);
  setSize(800, 600);
  setAudioChannels(0, 2); // No audio input, stereo output

  midiManager.setCallback([this](int midiNoteNumber, float velocity) {
    synth.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    gui.setNotePlayed(midiNoteNumber); // pass note to GUI if needed
  });
}

MainComponent::~MainComponent() { shutdownAudio(); }

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
  synth.prepare(sampleRate);
}

void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
  synth.renderNextBlock(*bufferToFill.buffer, bufferToFill.startSample, bufferToFill.numSamples);
}

void MainComponent::releaseResources() {}

void MainComponent::resized()
{
  gui.setBounds(getLocalBounds());
}
