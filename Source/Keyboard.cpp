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

  // Display the MIDI interface
  g.setFont(15.0f);
  g.setColour(juce::Colours::white);
  g.drawText("MIDI interface: <" + midiDeviceName + ">", 10, 50, 200, 30, juce::Justification::left, true);
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
  
  for(uint32_t i = 21; i <= 108; i++)
  {
    switch(i % 12)
    { 
      case NOTE_C_MOD12 :
        {
          // Highest C
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
          
          // Regular C
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
        break;

      case NOTE_Db_MOD12 :
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
        break;

      case NOTE_D_MOD12 :
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
        break;

      case NOTE_Eb_MOD12 :
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
        break;

      case NOTE_E_MOD12 :
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
        break;

      case NOTE_F_MOD12 :
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
        break;

      case NOTE_Gb_MOD12 :
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
        break;

      case NOTE_G_MOD12 :
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
        break;

      case NOTE_Ab_MOD12 :
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
        break;

      case NOTE_A_MOD12 :
        {
          // Lowest A on a piano keyboard
          if (i == NOTE_LOWEST_A)
          {
            x = x0; y = y0;
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
            x += -bnw/2;            y += 0;                 keyPolygon.lineTo(x, y);
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
        }
        break;
        
      case NOTE_Bb_MOD12 :
        {
          x = (i == NOTE_LOWEST_Bb) ? x0+(1*wnw)-(bnw/3) : x0+ns+(6*wnw)-(bnw/3);
          y = y0;
          juce::Path keyPolygon;
          keyPolygon.startNewSubPath(x, y);
          x += 0;           y += bnh-ns;    keyPolygon.lineTo(x, y);
          x += bnw-(2*ns);  y += 0;         keyPolygon.lineTo(x, y);
          x += 0;           y += -(bnh-ns); keyPolygon.lineTo(x, y);
          keyPolygon.closeSubPath();
          g.setColour(BLACK_NOTE_COLOR);
          g.fillPath(keyPolygon);
        }
        break;

      case NOTE_B_MOD12 :
        {
          x = (i == NOTE_LOWEST_B) ? x0+(1*wnw)+(2*bnw/3) : x0+ns+(6*wnw)+(2*bnw/3);
          y = y0;
          //x = x0+(6*wnw)+(2*bnw/3)+ns; y = y0;
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
        break;
      
      default:
        std::cout << "ERROR\n";
    }

    if ((i % 12) == NOTE_B_MOD12)
    {
      if (i == NOTE_LOWEST_B)
      {
        x0 += 2*wnw;
        x0 -= ns;
      }
      else
        x0 += 7*wnw;
    }
  }
}



// ----------------------------------------------------------------------------
// METHOD Keyboard::_renderInput()                                    [PRIVATE]
// ----------------------------------------------------------------------------
void Keyboard::_renderInput(juce::Graphics& g)
{
  if (midiCurrentNote != -1)
  {
    g.setColour(juce::Colours::red);
    float x = (float)((midiCurrentNote * 10) % getWidth());
    g.drawLine(x, 100, x, (float)getHeight(), 1.5f);
  }
}



// ----------------------------------------------------------------------------
// METHOD Keyboard::setNotePlayed()
// ----------------------------------------------------------------------------
void Keyboard::setNotePlayed(int midiNote)
{
  midiCurrentNote = midiNote;
  repaint();
}



// ----------------------------------------------------------------------------
// METHOD Keyboard::setMidiDeviceName()
// ----------------------------------------------------------------------------
void Keyboard::setMidiDeviceName(juce::String deviceName)
{
  midiDeviceName = deviceName;
}
