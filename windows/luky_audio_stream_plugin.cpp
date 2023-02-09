#include "luky_audio_stream_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

#import "dll\mic_stream_windows.tlb" raw_interfaces_only
using namespace mic_stream_windows;

namespace luky_audio_stream {

// static
void LukyAudioStreamPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "luky_audio_stream",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<LukyAudioStreamPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

LukyAudioStreamPlugin::LukyAudioStreamPlugin() {}

LukyAudioStreamPlugin::~LukyAudioStreamPlugin() {}

void LukyAudioStreamPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare("getPlatformVersion") == 0) {

    
  //Create the interface pointer
      IMicStreamPtr pMicStream(__uuidof(MicStreamClass));


      pMicStream->ReadAudioStreamFromMicrophone(0);


    std::ostringstream version_stream;
    version_stream << "Windows ";
    if (IsWindows10OrGreater()) {
      version_stream << "10+";
    } else if (IsWindows8OrGreater()) {
      version_stream << "8";
    } else if (IsWindows7OrGreater()) {
      version_stream << "7";
    }
    result->Success(flutter::EncodableValue(version_stream.str()));
  } else if(method_call.method_name().compare("readAudioStreamFromMic") == 0){

     //Create the interface pointer
      IMicStreamPtr pMicStream(__uuidof(MicStreamClass));
      pMicStream->ReadAudioStreamFromMicrophone(0);

    
      printf("WOW NOW Wi Are Talking!!");
      std::ostringstream version_stream;
      version_stream << "LUK OS";
      
      result->Success(flutter::EncodableValue(version_stream.str()));
  } else {
    
    result->NotImplemented();
  }
}

}  // namespace luky_audio_stream
