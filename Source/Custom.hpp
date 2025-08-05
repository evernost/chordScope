#pragma once

#include <JuceHeader.h>

class CustomComponent : public juce::Component
{
public:
    void paint(juce::Graphics& g) override;
    void setNotePlayed(int midiNote);

private:
    int currentNote = -1;
};
#pragma once
