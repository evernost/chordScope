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
  float x0 = 400;
  float y0 = 100;

  // Some shortcuts for readability
  float wnh = KEYBOARD_WHITE_NOTE_HEIGHT;
  float wnw = KEYBOARD_WHITE_NOTE_WIDTH;
  float bnh = KEYBOARD_BLACK_NOTE_HEIGHT; 
  float bnw = KEYBOARD_BLACK_NOTE_WIDTH;
  float nc = KEYBOARD_NOTE_CHANFER;
  float ns = KEYBOARD_NOTE_SPACING;


  g.fillAll(juce::Colours::black);
  g.setColour(juce::Colours::white);

  // Some random lines to showcase the 'drawLine' method
  g.drawLine(100.0f, 100.0f, 200.0f, 200.0f, 2.0f);
  g.drawLine(200.0f, 100.0f, 100.0f, 200.0f, 2.0f);

  


  // self.polygons[i] += utils.Vector2D(0, -(wnh-nc))

  juce::Path keybPolygon;
  keybPolygon.startNewSubPath(x0, y0); x0 += 0; y0 += wnh-nc;
  keybPolygon.lineTo(x0, y0); x0 += nc; y0 += nc;
  keybPolygon.lineTo(x0, y0); x0 += wnw-(2*nc)-(2*ns); y0 += 0;
  keybPolygon.lineTo(x0, y0); x0 += nc; y0 += -nc;
  keybPolygon.lineTo(x0, y0); x0 += 0; y0 += -(wnh-nc);
  keybPolygon.closeSubPath();

  g.setColour(juce::Colours::white);
  g.fillPath(keybPolygon);

  g.setFont(20.0f);
  g.drawText("bloop bloop", 10, 50, 200, 30, juce::Justification::left, true);



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
