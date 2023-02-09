#ifndef FLUTTER_PLUGIN_LUKY_AUDIO_STREAM_PLUGIN_H_
#define FLUTTER_PLUGIN_LUKY_AUDIO_STREAM_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace luky_audio_stream {

class LukyAudioStreamPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  LukyAudioStreamPlugin();

  virtual ~LukyAudioStreamPlugin();

  // Disallow copy and assign.
  LukyAudioStreamPlugin(const LukyAudioStreamPlugin&) = delete;
  LukyAudioStreamPlugin& operator=(const LukyAudioStreamPlugin&) = delete;

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace luky_audio_stream

#endif  // FLUTTER_PLUGIN_LUKY_AUDIO_STREAM_PLUGIN_H_
