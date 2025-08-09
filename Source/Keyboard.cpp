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
// METHOD Keyboard::paint()                                         [INHERITED]
// ----------------------------------------------------------------------------
void Keyboard::paint(juce::Graphics& g)
{
  // Render background
  g.fillAll(juce::Colours::black);

  // Render the keyboard
  _renderNotes(g);

  // Render the notes from the MIDI input
  // Optionally react to MIDI note
  _renderInput(g);
   
  if (currentNote != -1)
  {
    g.setColour(juce::Colours::red);
    float z = (float)((currentNote * 10) % getWidth());
    g.drawLine(z, 0, z, (float)getHeight(), 1.5f);
  }

  // Display the MIDI interface
  g.setFont(15.0f);
  g.setColour(juce::Colours::white);
  g.drawText("MIDI interface: " + deviceName, 10, 50, 200, 30, juce::Justification::left, true);

}



// ----------------------------------------------------------------------------
// METHOD Keyboard::_renderNotes()                                    [PRIVATE]
// ----------------------------------------------------------------------------
void Keyboard::_renderNotes(juce::Graphics& g)
{
  float x0 = 10;
  float y0 = 300;

  float x;
  float y;

  // Some shortcuts for readability
  float wnh = KEYBOARD_WHITE_NOTE_HEIGHT;
  float wnw = KEYBOARD_WHITE_NOTE_WIDTH;
  float bnh = KEYBOARD_BLACK_NOTE_HEIGHT; 
  float bnw = KEYBOARD_BLACK_NOTE_WIDTH;
  float nc = KEYBOARD_NOTE_CHANFER;
  float ns = KEYBOARD_NOTE_SPACING;
  
  for(uint32_t i = 0; i < 128; i++)
  {
    
    // Note: C
    {
      if (i == 108)
      {
        x = x0 + ns; y = y0;
        juce::Path keyPolygon;
        keyPolygon.startNewSubPath(x, y); 
        x += 0;                 y += wnh-nc;    keyPolygon.lineTo(x, y); 
        x += nc;                y += nc;        keyPolygon.lineTo(x, y); 
        x += wnw-(2*nc)-(2*ns); y += 0;         keyPolygon.lineTo(x, y); 
        x += nc;                y += -nc;       keyPolygon.lineTo(x, y); 
        x += 0;                 y += -(wnh-nc); keyPolygon.lineTo(x, y);
        keyPolygon.closeSubPath();
        g.setColour(WHITE_NOTE_COLOR);
        g.fillPath(keyPolygon);
      }
      else
      {
        x = x0 + ns; y = y0;
        juce::Path keyPolygon;
        keyPolygon.startNewSubPath(x, y); 
        x += 0;                 y += wnh-nc;            keyPolygon.lineTo(x, y);
        x += nc;                y += nc;                keyPolygon.lineTo(x, y);
        x += wnw-(2*nc)-(2*ns); y += 0;                 keyPolygon.lineTo(x, y);
        x += nc;                y += -nc;               keyPolygon.lineTo(x, y);
        x += 0;                 y += -(wnh-bnh-ns-nc);  keyPolygon.lineTo(x, y);
        x += -2*bnw/3;          y += 0;                 keyPolygon.lineTo(x, y);
        x += 0;                 y += -(bnh+ns);         keyPolygon.lineTo(x, y);
        keyPolygon.closeSubPath();
        g.setColour(WHITE_NOTE_COLOR);
        g.fillPath(keyPolygon);
      }
    }

    // Note Db
    {
      x = x0+wnw-(2*bnw/3)+ns; y = y0;
      juce::Path keyPolygon;
      keyPolygon.startNewSubPath(x, y);
      x += 0;           y += bnh-ns;    keyPolygon.lineTo(x, y);
      x += bnw-(2*ns);  y += 0;         keyPolygon.lineTo(x, y);
      x += 0;           y += -(bnh-ns); keyPolygon.lineTo(x, y);
      keyPolygon.closeSubPath();
      g.setColour(BLACK_NOTE_COLOR);
      g.fillPath(keyPolygon);
    }

    // Note D
    {
      x = x0+wnw+(bnw/3)+ns; y = y0;
      juce::Path keyPolygon;
      keyPolygon.startNewSubPath(x, y);
      x += 0;                 y += bnh+ns;            keyPolygon.lineTo(x, y);
      x += -bnw/3;            y += 0;                 keyPolygon.lineTo(x, y);
      x += 0;                 y += wnh-bnh-ns-nc;     keyPolygon.lineTo(x, y);
      x += nc;                y += nc;                keyPolygon.lineTo(x, y);
      x += wnw-(2*nc)-(2*ns); y += 0;                 keyPolygon.lineTo(x, y);
      x += nc;                y += -nc;               keyPolygon.lineTo(x, y);
      x += 0;                 y += -(wnh-bnh-ns-nc);  keyPolygon.lineTo(x, y);
      x += -bnw/3;            y += 0;                 keyPolygon.lineTo(x, y);
      x += 0;                 y += -(bnh+ns);         keyPolygon.lineTo(x, y);
      keyPolygon.closeSubPath();
      g.setColour(WHITE_NOTE_COLOR);
      g.fillPath(keyPolygon);
    }
    
    // Note Eb
    {
      x = x0+(2*wnw)-(bnw/3)+ns; y = y0;
      juce::Path keyPolygon;
      keyPolygon.startNewSubPath(x, y);
      x += 0;           y += bnh-ns;    keyPolygon.lineTo(x, y);
      x += bnw-(2*ns);  y += 0;         keyPolygon.lineTo(x, y);
      x += 0;           y += -(bnh-ns); keyPolygon.lineTo(x, y);
      keyPolygon.closeSubPath();
      g.setColour(BLACK_NOTE_COLOR);
      g.fillPath(keyPolygon);
    }

    // Note E
    {
      x = x0+(2*wnw)+(2*bnw/3)+ns; y = y0;
      juce::Path keyPolygon;
      keyPolygon.startNewSubPath(x, y);
      x += 0;                 y += bnh+ns;        keyPolygon.lineTo(x, y);
      x += -2*bnw/3;          y += 0;             keyPolygon.lineTo(x, y);
      x += 0;                 y += wnh-bnh-ns-nc; keyPolygon.lineTo(x, y);
      x += nc;                y += nc;            keyPolygon.lineTo(x, y);
      x += wnw-(2*nc)-(2*ns); y += 0;             keyPolygon.lineTo(x, y);
      x += nc;                y += -nc;           keyPolygon.lineTo(x, y);
      x += 0;                 y += -(wnh-nc);     keyPolygon.lineTo(x, y);
      keyPolygon.closeSubPath();
      g.setColour(WHITE_NOTE_COLOR);
      g.fillPath(keyPolygon);
    }

    // Note F
    {
      x = x0+(3*wnw)+ns; y = y0;
      juce::Path keyPolygon;
      keyPolygon.startNewSubPath(x, y);
      x += 0;                 y += wnh-nc;            keyPolygon.lineTo(x, y);
      x += nc;                y += nc;                keyPolygon.lineTo(x, y);
      x += wnw-(2*nc)-(2*ns); y += 0;                 keyPolygon.lineTo(x, y);
      x += nc;                y += -nc;               keyPolygon.lineTo(x, y);
      x += 0;                 y += -(wnh-bnh-ns-nc);  keyPolygon.lineTo(x, y);
      x += -2*bnw/3;          y += 0;                 keyPolygon.lineTo(x, y);
      x += 0;                 y += -(bnh+ns);         keyPolygon.lineTo(x, y);
      keyPolygon.closeSubPath();
      g.setColour(WHITE_NOTE_COLOR);
      g.fillPath(keyPolygon);
    }

    // Note Gb
    {
      x = x0+(4*wnw)-(2*bnw/3)+ns; y = y0;
      juce::Path keyPolygon;
      keyPolygon.startNewSubPath(x, y);
      x += 0;           y += bnh-ns;    keyPolygon.lineTo(x, y);
      x += bnw-(2*ns);  y += 0;         keyPolygon.lineTo(x, y);
      x += 0;           y += -(bnh-ns); keyPolygon.lineTo(x, y);
      keyPolygon.closeSubPath();
      g.setColour(BLACK_NOTE_COLOR);
      g.fillPath(keyPolygon);
    }

    // Note G
    {
      x = x0+(4*wnw)+(bnw/3)+ns; y = y0;
      juce::Path keyPolygon;
      keyPolygon.startNewSubPath(x, y);
      x += 0;                 y += bnh+ns;            keyPolygon.lineTo(x, y);
      x += -bnw/3;            y += 0;                 keyPolygon.lineTo(x, y);
      x += 0;                 y += wnh-bnh-ns-nc;     keyPolygon.lineTo(x, y);
      x += nc;                y += nc;                keyPolygon.lineTo(x, y);
      x += wnw-(2*nc)-(2*ns); y += 0;                 keyPolygon.lineTo(x, y);
      x += nc;                y += -nc;               keyPolygon.lineTo(x, y);
      x += 0;                 y += -(wnh-bnh-ns-nc);  keyPolygon.lineTo(x, y);
      x += -bnw/2;            y += 0;                 keyPolygon.lineTo(x, y);
      x += 0;                 y += -(bnh+ns);         keyPolygon.lineTo(x, y);
      keyPolygon.closeSubPath();
      g.setColour(WHITE_NOTE_COLOR);
      g.fillPath(keyPolygon);
    }

    if ((i+8) < 127)
    {
      // Note Ab
      {
        x = x0+(5*wnw)-(bnw/2)+ns; y = y0;
        juce::Path keyPolygon;
        keyPolygon.startNewSubPath(x, y);
        x += 0;           y += bnh-ns;    keyPolygon.lineTo(x, y);
        x += bnw-(2*ns);  y += 0;         keyPolygon.lineTo(x, y);
        x += 0;           y += -(bnh-ns); keyPolygon.lineTo(x, y);
        keyPolygon.closeSubPath();
        g.setColour(BLACK_NOTE_COLOR);
        g.fillPath(keyPolygon);
      }

      // Lowest A
      if ((i+9) == 21)
      {
        x = x0+(5*wnw)+ns; y = y0;
        juce::Path keyPolygon;
        keyPolygon.startNewSubPath(x, y);
        x += 0;                 y += wnh-nc;            keyPolygon.lineTo(x, y);
        x += nc;                y += nc;                keyPolygon.lineTo(x, y);
        x += wnw-(2*nc)-(2*ns); y += 0;                 keyPolygon.lineTo(x, y);
        x += nc;                y += -nc;               keyPolygon.lineTo(x, y);
        x += 0;                 y += -(wnh-bnh-ns-nc);  keyPolygon.lineTo(x, y);
        x += -bnw/3;            y += 0;                 keyPolygon.lineTo(x, y);
        x += 0;                 y += -(bnh+ns);         keyPolygon.lineTo(x, y);
        keyPolygon.closeSubPath();
        g.setColour(WHITE_NOTE_COLOR);
        g.fillPath(keyPolygon);
      }
      
      // Regular A
      else
      {
        x = x0+(5*wnw)+(bnw/2)+ns; y = y0;
        juce::Path keyPolygon;
        keyPolygon.startNewSubPath(x, y);
        x += 0;                 y += bnh+ns;            keyPolygon.lineTo(x, y);
        x += -bnw/2;          y += 0;                 keyPolygon.lineTo(x, y);
        x += 0;                 y += wnh-bnh-ns-nc; keyPolygon.lineTo(x, y);
        x += nc;                y += nc;                keyPolygon.lineTo(x, y);
        x += wnw-(2*nc)-(2*ns); y += 0;                 keyPolygon.lineTo(x, y);
        x += nc;                y += -nc;                keyPolygon.lineTo(x, y);
        x += 0;                 y += -(wnh-bnh-ns-nc);  keyPolygon.lineTo(x, y);
        x += -bnw/3;            y += 0;                 keyPolygon.lineTo(x, y);
        x += 0;                 y += -(bnh+ns);         keyPolygon.lineTo(x, y);
        keyPolygon.closeSubPath();
        g.setColour(WHITE_NOTE_COLOR);
        g.fillPath(keyPolygon);
      }
      
      // Note Bb
      {
        x = x0+(6*wnw)-(bnw/3)+ns; y = y0;
        juce::Path keyPolygon;
        keyPolygon.startNewSubPath(x, y);
        x += 0;           y += bnh-ns;    keyPolygon.lineTo(x, y);
        x += bnw-(2*ns);  y += 0;         keyPolygon.lineTo(x, y);
        x += 0;           y += -(bnh-ns); keyPolygon.lineTo(x, y);
        keyPolygon.closeSubPath();
        g.setColour(BLACK_NOTE_COLOR);
        g.fillPath(keyPolygon);
      }

      // Note Bb
      {
        x = x0+(6*wnw)+(2*bnw/3)+ns; y = y0;
        juce::Path keyPolygon;
        keyPolygon.startNewSubPath(x, y);
        x += 0;                 y += bnh+ns;            keyPolygon.lineTo(x, y);
        x += -2*bnw/3;          y += 0;                 keyPolygon.lineTo(x, y);
        x += 0;                 y += wnh-bnh-ns-nc;     keyPolygon.lineTo(x, y);
        x += nc;                y += nc;                keyPolygon.lineTo(x, y);
        x += wnw-(2*nc)-(2*ns); y += 0;                 keyPolygon.lineTo(x, y);
        x += nc;                y += -nc;               keyPolygon.lineTo(x, y);
        x += 0;                 y += -(wnh-nc);         keyPolygon.lineTo(x, y);
        keyPolygon.closeSubPath();
        g.setColour(WHITE_NOTE_COLOR);
        g.fillPath(keyPolygon);
      }
    }
    x0 += 7*wnw;
  }
}



// ----------------------------------------------------------------------------
// METHOD Keyboard::_renderInput()                                    [PRIVATE]
// ----------------------------------------------------------------------------
void Keyboard::_renderInput(juce::Graphics& g)
{
  if (currentNote != -1)
  {
    g.setColour(juce::Colours::red);
    float x = (float)((currentNote * 10) % getWidth());
    g.drawLine(x, 100, x, (float)getHeight(), 1.5f);
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



// ----------------------------------------------------------------------------
// METHOD Keyboard::setMidiDeviceName()
// ----------------------------------------------------------------------------
void Keyboard::setMidiDeviceName(juce::String dev)
{
  deviceName = dev;
}
