## Microphone

To be able to use voice commands, we need to be able to record audio. This is done using a microphone. The KY-037 sensor will not work, because it's not a real microphone but a "sound sensor". We can use the [MAX9814](https://www.tinytronics.nl/nl/sensoren/geluid/max9814-microfoon-versterker-module-met-microfoon-automatische-gain) instead. However, to record sound we need to store it which is not possible on our ESP32. Furthermore, recognizing voice commands is very complex and not possible within our time limit. 
