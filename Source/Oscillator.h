/*
 ==============================================================================
 
 Oscillator.h
 Created: 11 Jan 2018 1:41:05pm
 Author:  Joshua Hodge
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "../Common/LabeledKnob.h"
#include "SliderLookAndFeel.h"
#include "CustomLookAndFeel.h"


//==============================================================================
/*
 */
class Oscillator   : public Component, public Slider::Listener
{
public:
    Oscillator(JuceSynthFrameworkAudioProcessor&);
    ~Oscillator();
    
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider*) override;
    
private:
    
    JuceSynthFrameworkAudioProcessor& processor;
    
    SharedResourcePointer<BasicLookAndFeel> lookAndFeel;
    ComboBox oscMenu;
    GroupComponent mainGroup;
    BasicKnob osc1FreqKnob; LabeledKnob labeledoscAFreqKnob;
    BasicKnob osc1OctKnob; LabeledKnob labeledoscAOctKnob;
    BasicKnob osc1PulseWidthKnob; LabeledKnob labeledoscAPulseWidthKnob;
    Slider osc1SawShapeToggle;
    Slider osc1SquareShapeToggle;
    Slider osc1SyncToggle;
    
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1SawShapeVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1SquareShapeVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1SyncVal;
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1FreqVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1OctVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> osc1PulseWidthVal;
    
    GroupLookAndFeel groupLookAndFeel;
    SliderToggleLookAndFeel sliderToggleLookAndFeel;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
