#include <JuceHeader.h>
#include "BitDepthReducer.h"

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BitDepthReducer();
}
