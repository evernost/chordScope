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
  juce::Colour WHITE_NOTE_COLOR = juce::Colours::white;
  juce::Colour BLACK_NOTE_COLOR = juce::Colours::darkblue;
  
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


  g.fillAll(juce::Colours::black);
  
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
    // # Note Eb
    // self.polygons[i+3] = [(x0+(2*wnw)-(bnw//3)+ns, y0)]
    // self.polygons[i+3] += utils.Vector2D(0,bnh-ns)
    // self.polygons[i+3] += utils.Vector2D(bnw-(2*ns),0)
    // self.polygons[i+3] += utils.Vector2D(0,-(bnh-ns))





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
    // # Note E
    // self.polygons[i+4] = [(x0+(2*wnw)+(2*bnw//3)+ns, y0)]
    // self.polygons[i+4] += utils.Vector2D(0,bnh+ns)
    // self.polygons[i+4] += utils.Vector2D(-2*bnw//3,0)
    // self.polygons[i+4] += utils.Vector2D(0,wnh-bnh-ns-nc)
    // self.polygons[i+4] += utils.Vector2D(nc,nc)
    // self.polygons[i+4] += utils.Vector2D(wnw-(2*nc)-(2*ns),0)
    // self.polygons[i+4] += utils.Vector2D(nc,-nc)
    // self.polygons[i+4] += utils.Vector2D(0,-(wnh-nc))




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
    // # Note F
    // self.polygons[i+5] = [(x0+(3*wnw)+ns, y0)]
    // self.polygons[i+5] += utils.Vector2D(0,wnh-nc)
    // self.polygons[i+5] += utils.Vector2D(nc,nc)
    // self.polygons[i+5] += utils.Vector2D(wnw-(2*nc)-(2*ns),0)
    // self.polygons[i+5] += utils.Vector2D(nc,-nc)
    // self.polygons[i+5] += utils.Vector2D(0,-(wnh-bnh-ns-nc))
    // self.polygons[i+5] += utils.Vector2D(-2*bnw//3,0)
    // self.polygons[i+5] += utils.Vector2D(0,-(bnh+ns))



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
    // # Note Gb
    // self.polygons[i+6] = [(x0+(4*wnw)-(2*bnw//3)+ns, y0)]
    // self.polygons[i+6] += utils.Vector2D(0,bnh-ns)
    // self.polygons[i+6] += utils.Vector2D(bnw-(2*ns),0)
    // self.polygons[i+6] += utils.Vector2D(0,-(bnh-ns))



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
      //   # Note Ab
      //   self.polygons[i+8] = [(x0+(5*wnw)-(bnw//2)+ns, y0)]
      //   self.polygons[i+8] += utils.Vector2D(0,bnh-ns)
      //   self.polygons[i+8] += utils.Vector2D(bnw-(2*ns),0)
      //   self.polygons[i+8] += utils.Vector2D(0,-(bnh-ns))



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
      
      //   self.polygons[i+10] = [(x0+(6*wnw)-(bnw//3)+ns, y0)]
      //   self.polygons[i+10] += utils.Vector2D(0,bnh-ns)
      //   self.polygons[i+10] += utils.Vector2D(bnw-(2*ns),0)
      //   self.polygons[i+10] += utils.Vector2D(0,-(bnh-ns))

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
      //   # Note B
      //   self.polygons[i+11] = [(x0+(6*wnw)+(2*bnw//3)+ns, y0)]
      //   self.polygons[i+11] += utils.Vector2D(0,bnh+ns)
      //   self.polygons[i+11] += utils.Vector2D(-2*bnw//3,0)
      //   self.polygons[i+11] += utils.Vector2D(0,wnh-bnh-ns-nc)
      //   self.polygons[i+11] += utils.Vector2D(nc,nc)
      //   self.polygons[i+11] += utils.Vector2D(wnw-(2*nc)-(2*ns),0)
      //   self.polygons[i+11] += utils.Vector2D(nc,-nc)
      //   self.polygons[i+11] += utils.Vector2D(0,-(wnh-nc))
    }
    x0 += 7*wnw;

 
  }





  g.setFont(15.0f);
  g.setColour(juce::Colours::white);
  g.drawText("MIDI interface: ", 10, 50, 200, 30, juce::Justification::left, true);



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
