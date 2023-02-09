#include "include/luky_audio_stream/luky_audio_stream_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "luky_audio_stream_plugin.h"

void LukyAudioStreamPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  luky_audio_stream::LukyAudioStreamPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
