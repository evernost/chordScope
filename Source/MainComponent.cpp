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



// ----------------------------------------------------------------------------
// CLASS CONSTRUCTOR
// ----------------------------------------------------------------------------
MainComponent::MainComponent()
{
  addAndMakeVisible(keyboard);
  setSize(800, 600);
  setAudioChannels(0, 2);

  midi.setCallback([this](int midiNoteNumber, float velocity) {
    synth.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    keyboard.setNotePlayed(midiNoteNumber);
  });
}



// ----------------------------------------------------------------------------
// CLASS DESTRUCTOR
// ----------------------------------------------------------------------------
MainComponent::~MainComponent() 
{ 
  shutdownAudio();
}



// ----------------------------------------------------------------------------
// METHOD MainComponent::prepareToPlay()                            [INHERITED]
// ----------------------------------------------------------------------------
void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
  synth.setSampleRate(sampleRate);
}



// ----------------------------------------------------------------------------
// METHOD MainComponent::getNextAudioBlock()                        [INHERITED]
// ----------------------------------------------------------------------------
void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
  synth.renderNextBlock(*bufferToFill.buffer, bufferToFill.startSample, bufferToFill.numSamples);
}



// ----------------------------------------------------------------------------
// METHOD MainComponent::releaseResources()                         [INHERITED]
// ----------------------------------------------------------------------------
void MainComponent::releaseResources()
{

}



// ----------------------------------------------------------------------------
// METHOD MainComponent::resized()                                  [INHERITED]
// ----------------------------------------------------------------------------
void MainComponent::resized()
{
  keyboard.setBounds(getLocalBounds());
}
