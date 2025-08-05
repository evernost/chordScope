#include "Custom.hpp"

void CustomComponent::paint(juce::Graphics& g)
{
  g.fillAll(juce::Colours::black);
  g.setColour(juce::Colours::white);

  // Just draw some lines
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

void CustomComponent::setNotePlayed(int midiNote)
{
  currentNote = midiNote;
  repaint();
}
