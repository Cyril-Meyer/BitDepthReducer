/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BitDepthReducerAudioProcessorEditor::BitDepthReducerAudioProcessorEditor (BitDepthReducerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);

    // these define the parameters of our slider object
    bit_depth.setSliderStyle(juce::Slider::LinearBarVertical);
    bit_depth.setRange(1.0, 32.0, 1.0);
    bit_depth.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    bit_depth.setPopupDisplayEnabled(true, false, this);
    bit_depth.setTextValueSuffix(" bits");
    bit_depth.setValue(24.0);

    // this function adds the slider to the editor
    addAndMakeVisible(&bit_depth);

    bit_depth.addListener(this);
}

BitDepthReducerAudioProcessorEditor::~BitDepthReducerAudioProcessorEditor()
{
}

//==============================================================================
void BitDepthReducerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText("BitDepthReducer", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void BitDepthReducerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    bit_depth.setBounds(getWidth()/2-10, 30, 20, getHeight() - 60);

}

void BitDepthReducerAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    audioProcessor.bit_depth = bit_depth.getValue();
}
