import 'luky_audio_stream_platform_interface.dart';

class LukyAudioStream {
  Future<String?> getPlatformVersion() {
    return LukyAudioStreamPlatform.instance.getPlatformVersion();
  }

  Future<String?> readAudioStreamFromMic() {
    return LukyAudioStreamPlatform.instance.readAudioStreamFromMic();
  }

  Future<String?> readAudioStreamFromSpeackers() {
    return LukyAudioStreamPlatform.instance.readAudioStreamFromSpeackers();
  }
}
