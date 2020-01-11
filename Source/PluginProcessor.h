/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthVoice.h"
#include "SynthSound.h"
#include "AudioBufferQueue.h"
#include "ScopeDataCollector.h"
#include "ScopeComponent.h"

//==============================================================================
/**
 */
class JuceSynthFrameworkAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    JuceSynthFrameworkAudioProcessor();
    ~JuceSynthFrameworkAudioProcessor();
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    
#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
#endif
    
    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;
    
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    
    //==============================================================================
    const String getName() const override;
    
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect () const override;
    double getTailLengthSeconds() const override{ return 0.0;} ;
    
    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;
    
    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void updateFilter();
    
    AudioProcessorValueTreeState tree;
    MidiKeyboardState keyboardState;
    //
 
    AudioBufferQueue<float>& getAudioBufferQueue() noexcept  { return audioBufferQueue; }
    
    
private:
    Synthesiser mySynth;
    SynthVoice* myVoice;
    
    float lfoPhase;
    
    //    dsp::ProcessorDuplicator<dsp::StateVariableFilter::Filter<float> , dsp::StateVariableFilter::Parameters<float>> stateVariableFilter;
    
    double lastSampleRate;
    
    AudioBufferQueue<float> audioBufferQueue;
    ScopeDataCollector<float> scopeDataCollector { audioBufferQueue };
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceSynthFrameworkAudioProcessor)
};
