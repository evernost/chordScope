#pragma once

#include <JuceHeader.h>

class SineSynth
{
public:
    void prepare(double sampleRate);
    void renderNextBlock(juce::AudioBuffer<float>& buffer, int startSample, int numSamples);
    void setFrequency(double frequency);

private:
    double currentAngle = 0.0;
    double angleDelta = 0.0;
    double currentSampleRate = 44100.0;
};
#pragma once
