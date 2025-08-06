// ============================================================================
// Project        : chordScope
// Module name    : Keyboard
// File name      : Keyboard.cpp
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
#include "Keyboard.hpp"



// ----------------------------------------------------------------------------
// METHOD Keyboard::paint()
// ----------------------------------------------------------------------------
void Keyboard::paint(juce::Graphics& g)
{
  g.fillAll(juce::Colours::black);
  g.setColour(juce::Colours::white);

  // Some random lines to showcase the 'drawLine' method
  g.drawLine(100.0f, 100.0f, 200.0f, 200.0f, 2.0f);
  g.drawLine(200.0f, 100.0f, 100.0f, 200.0f, 2.0f);

  // Optionally react to MIDI note
  if (currentNote != -1)
  {
    g.setColour(juce::Colours::red);
    float x = (float)((currentNote * 10) % getWidth());
    g.drawLine(x, 0, x, (float)getHeight(), 1.5f);
  }
}



// ----------------------------------------------------------------------------
// METHOD Keyboard::setNotePlayed()
// ----------------------------------------------------------------------------
void Keyboard::setNotePlayed(int midiNote)
{
  currentNote = midiNote;
  repaint();
}
