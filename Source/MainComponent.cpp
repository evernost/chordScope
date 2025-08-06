// ============================================================================
// Project        : chordScope
// Module name    : MainComponent
// File name      : MainComponent.cpp
// File type      : C++ 17
// Purpose        : 
// Author         : QuBi (nitrogenium@outlook.fr)
// Creation date  : August 5th, 2025
// ----------------------------------------------------------------------------
// Best viewed with space indentation (2 spaces)
// ============================================================================

// ============================================================================
// EXTERNALS
// ============================================================================


#include "MainComponent.hpp"

MainComponent::MainComponent()
{
  addAndMakeVisible(keyboard);
  setSize(800, 600);
  setAudioChannels(0, 2); // No audio input, stereo output

  midiManager.setCallback([this](int midiNoteNumber, float velocity) {
    synth.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    keyboard.setNotePlayed(midiNoteNumber);
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
  keyboard.setBounds(getLocalBounds());
}
