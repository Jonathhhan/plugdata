#include "Config.h"
#include <juce_audio_devices/juce_audio_devices.h>
#include "Standalone/PlugDataWindow.h"

#if PLUGDATA_FX
char const* ProjectInfo::projectName = "plugdata-fx";
#elif PLUGDATA_MIDI
char const* ProjectInfo::projectName = "plugdata-midi";
#else
char const* ProjectInfo::projectName = "plugdata";
#endif

#if PLUGDATA_STANDALONE
bool ProjectInfo::isStandalone = true;
#else
bool ProjectInfo::isStandalone = false;
#endif

juce::AudioDeviceManager* ProjectInfo::getDeviceManager()
{
#if PLUGDATA_STANDALONE
    if (auto* standalone = StandalonePluginHolder::getInstance())
        return &standalone->deviceManager;

    return nullptr;
#else
    return nullptr;
#endif
}
