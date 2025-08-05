#include "Synth.hpp"

void SineSynth::prepare(double sampleRate)
{
    currentSampleRate = sampleRate;
}

void SineSynth::setFrequency(double frequency)
{
    angleDelta = juce::MathConstants<double>::twoPi * frequency / currentSampleRate;
}

void SineSynth::renderNextBlock(juce::AudioBuffer<float>& buffer, int startSample, int numSamples)
{
    auto* left = buffer.getWritePointer(0);
    auto* right = buffer.getNumChannels() > 1 ? buffer.getWritePointer(1) : nullptr;

    for (int i = 0; i < numSamples; ++i)
    {
        float sample = (float)std::sin(currentAngle);
        currentAngle += angleDelta;

        left[startSample + i] = sample * 0.1f;
        if (right)
            right[startSample + i] = sample * 0.1f;
    }
}
