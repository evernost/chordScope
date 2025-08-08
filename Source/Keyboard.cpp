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
  float x0 = 100;
  float y0 = 200;

  float x;
  float y;

  // Some shortcuts for readability
  float wnh = KEYBOARD_WHITE_NOTE_HEIGHT;
  float wnw = KEYBOARD_WHITE_NOTE_WIDTH;
  float bnh = KEYBOARD_BLACK_NOTE_HEIGHT; 
  float bnw = KEYBOARD_BLACK_NOTE_WIDTH;
  float nc = KEYBOARD_NOTE_CHANFER;
  float ns = KEYBOARD_NOTE_SPACING;


  g.fillAll(juce::Colours::black);
  g.setColour(juce::Colours::white);

  for(uint32_t i = 0; i < 128; i++)
  {
    juce::Path keyPolygon;
    
    // Note: C
    if (i == 108)
    {
      x = x0 + ns; y = y0;
      keyPolygon.startNewSubPath(x, y); 
      x += 0;                 y += wnh-nc;    keyPolygon.lineTo(x, y); 
      x += nc;                y += nc;        keyPolygon.lineTo(x, y); 
      x += wnw-(2*nc)-(2*ns); y += 0;         keyPolygon.lineTo(x, y); 
      x += nc;                y += -nc;       keyPolygon.lineTo(x, y); 
      x += 0;                 y += -(wnh-nc); keyPolygon.lineTo(x, y);
      keyPolygon.closeSubPath();
      g.setColour(juce::Colours::white);
      g.fillPath(keyPolygon);
    }
    else
    {
      x = x0 + ns; y = y0;
      keyPolygon.startNewSubPath(x, y); 
      x += 0;                 y += wnh-nc;            keyPolygon.lineTo(x, y);
      x += nc;                y += nc;                keyPolygon.lineTo(x, y);
      x += wnw-(2*nc)-(2*ns); y += 0;                 keyPolygon.lineTo(x, y);
      x += nc;                y += -nc;               keyPolygon.lineTo(x, y);
      x += 0;                 y += -(wnh-bnh-ns-nc);  keyPolygon.lineTo(x, y);
      x += -2*bnw/3;          y += 0;                 keyPolygon.lineTo(x, y);
      x += 0;                 y += -(bnh+ns);         keyPolygon.lineTo(x, y);
      keyPolygon.closeSubPath();
      g.setColour(juce::Colours::white);
      g.fillPath(keyPolygon);
    }


    // Note Db
    x = x0+wnw-(2*bnw/3)+ns; y = y0;
    keyPolygon.startNewSubPath(x, y);
    x += 0;           y += bnh-ns;    keyPolygon.lineTo(x, y);
    x += bnw-(2*ns);  y += 0;         keyPolygon.lineTo(x, y);
    x += 0;           y += -(bnh-ns); keyPolygon.lineTo(x, y);
    keyPolygon.closeSubPath();
    g.setColour(juce::Colours::black);
    g.fillPath(keyPolygon);
    

    // g.setColour(juce::Colours::black);
    // g.fillPath(keyPolygon);
    // g.setColour(juce::Colours::darkblue);
    // g.strokePath(keyPolygon, juce::PathStrokeType(2.0f));


    // Note D
    x = x0+wnw+(bnw/3)+ns; y = y0;
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
    g.setColour(juce::Colours::white);
    g.fillPath(keyPolygon);
    

    // Note Eb
    x = x0+(2*wnw)-(bnw/3)+ns; y = y0;
    keyPolygon.startNewSubPath(x, y);
    x += 0;           y += bnh-ns;    keyPolygon.lineTo(x, y);
    x += bnw-(2*ns);  y += 0;         keyPolygon.lineTo(x, y);
    x += 0;           y += -(bnh-ns); keyPolygon.lineTo(x, y);
    keyPolygon.closeSubPath();
    g.setColour(juce::Colours::white);
    g.fillPath(keyPolygon);


    // # Note Eb
    // self.polygons[i+3] = [(x0+(2*wnw)-(bnw//3)+ns, y0)]
    // self.polygons[i+3] += utils.Vector2D(0,bnh-ns)
    // self.polygons[i+3] += utils.Vector2D(bnw-(2*ns),0)
    // self.polygons[i+3] += utils.Vector2D(0,-(bnh-ns))








    // # Note Eb
    // self.polygons[i+4] = [(x0+(2*wnw)+(2*bnw//3)+ns, y0)]
    // self.polygons[i+4] += utils.Vector2D(0,bnh+ns)
    // self.polygons[i+4] += utils.Vector2D(-2*bnw//3,0)
    // self.polygons[i+4] += utils.Vector2D(0,wnh-bnh-ns-nc)
    // self.polygons[i+4] += utils.Vector2D(nc,nc)
    // self.polygons[i+4] += utils.Vector2D(wnw-(2*nc)-(2*ns),0)
    // self.polygons[i+4] += utils.Vector2D(nc,-nc)
    // self.polygons[i+4] += utils.Vector2D(0,-(wnh-nc))

    // # Note F
    // self.polygons[i+5] = [(x0+(3*wnw)+ns, y0)]
    // self.polygons[i+5] += utils.Vector2D(0,wnh-nc)
    // self.polygons[i+5] += utils.Vector2D(nc,nc)
    // self.polygons[i+5] += utils.Vector2D(wnw-(2*nc)-(2*ns),0)
    // self.polygons[i+5] += utils.Vector2D(nc,-nc)
    // self.polygons[i+5] += utils.Vector2D(0,-(wnh-bnh-ns-nc))
    // self.polygons[i+5] += utils.Vector2D(-2*bnw//3,0)
    // self.polygons[i+5] += utils.Vector2D(0,-(bnh+ns))

    // # Note Gb
    // self.polygons[i+6] = [(x0+(4*wnw)-(2*bnw//3)+ns, y0)]
    // self.polygons[i+6] += utils.Vector2D(0,bnh-ns)
    // self.polygons[i+6] += utils.Vector2D(bnw-(2*ns),0)
    // self.polygons[i+6] += utils.Vector2D(0,-(bnh-ns))

    // # Note G
    // self.polygons[i+7] = [(x0+(4*wnw)+(bnw//3)+ns, y0)]
    // self.polygons[i+7] += utils.Vector2D(0,bnh+ns)
    // self.polygons[i+7] += utils.Vector2D(-bnw//3,0)
    // self.polygons[i+7] += utils.Vector2D(0,wnh-bnh-ns-nc)
    // self.polygons[i+7] += utils.Vector2D(nc,nc)
    // self.polygons[i+7] += utils.Vector2D(wnw-(2*nc)-(2*ns),0)
    // self.polygons[i+7] += utils.Vector2D(nc,-nc)
    // self.polygons[i+7] += utils.Vector2D(0,-(wnh-bnh-ns-nc))
    // self.polygons[i+7] += utils.Vector2D(-bnw//2,0)
    // self.polygons[i+7] += utils.Vector2D(0,-(bnh+ns))

    // if ((i+8) < 127) :

    //   # Note Ab
    //   self.polygons[i+8] = [(x0+(5*wnw)-(bnw//2)+ns, y0)]
    //   self.polygons[i+8] += utils.Vector2D(0,bnh-ns)
    //   self.polygons[i+8] += utils.Vector2D(bnw-(2*ns),0)
    //   self.polygons[i+8] += utils.Vector2D(0,-(bnh-ns))

    //   # Note A
    //   if (grandPianoMode and ((i+9) == 21)) :
    //     self.polygons[i+9] = [(x0+(5*wnw)+ns, y0)]
    //     self.polygons[i+9] += utils.Vector2D(0,wnh-nc)
    //     self.polygons[i+9] += utils.Vector2D(nc,nc)
    //     self.polygons[i+9] += utils.Vector2D(wnw-(2*nc)-(2*ns),0)
    //     self.polygons[i+9] += utils.Vector2D(nc,-nc)
    //     self.polygons[i+9] += utils.Vector2D(0,-(wnh-bnh-ns-nc))
    //     self.polygons[i+9] += utils.Vector2D(-bnw//3,0)
    //     self.polygons[i+9] += utils.Vector2D(0,-(bnh+ns))
    //   else :
    //     self.polygons[i+9] = [(x0+(5*wnw)+(bnw//2)+ns, y0)]
    //     self.polygons[i+9] += utils.Vector2D(0, bnh+ns)
    //     self.polygons[i+9] += utils.Vector2D(-bnw//2, 0)
    //     self.polygons[i+9] += utils.Vector2D(0, wnh-bnh-ns-nc)
    //     self.polygons[i+9] += utils.Vector2D(nc,nc)
    //     self.polygons[i+9] += utils.Vector2D(wnw-(2*nc)-(2*ns), 0)
    //     self.polygons[i+9] += utils.Vector2D(nc, -nc)
    //     self.polygons[i+9] += utils.Vector2D(0, -(wnh-bnh-ns-nc))
    //     self.polygons[i+9] += utils.Vector2D(-bnw//3, 0)
    //     self.polygons[i+9] += utils.Vector2D(0,-(bnh+ns))

    //   # Note Bb
    //   self.polygons[i+10] = [(x0+(6*wnw)-(bnw//3)+ns, y0)]
    //   self.polygons[i+10] += utils.Vector2D(0,bnh-ns)
    //   self.polygons[i+10] += utils.Vector2D(bnw-(2*ns),0)
    //   self.polygons[i+10] += utils.Vector2D(0,-(bnh-ns))

    //   # Note B
    //   self.polygons[i+11] = [(x0+(6*wnw)+(2*bnw//3)+ns, y0)]
    //   self.polygons[i+11] += utils.Vector2D(0,bnh+ns)
    //   self.polygons[i+11] += utils.Vector2D(-2*bnw//3,0)
    //   self.polygons[i+11] += utils.Vector2D(0,wnh-bnh-ns-nc)
    //   self.polygons[i+11] += utils.Vector2D(nc,nc)
    //   self.polygons[i+11] += utils.Vector2D(wnw-(2*nc)-(2*ns),0)
    //   self.polygons[i+11] += utils.Vector2D(nc,-nc)
    //   self.polygons[i+11] += utils.Vector2D(0,-(wnh-nc))

    x0 += 7*wnw;

 
  }





  g.setFont(20.0f);
  g.setColour(juce::Colours::white);
  g.drawText("bloop bloop", 10, 50, 200, 30, juce::Justification::left, true);



  // Optionally react to MIDI note
  if (currentNote != -1)
  {
    g.setColour(juce::Colours::red);
    float z = (float)((currentNote * 10) % getWidth());
    g.drawLine(z, 0, z, (float)getHeight(), 1.5f);
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
