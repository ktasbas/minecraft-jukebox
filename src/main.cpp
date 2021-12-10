#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include "disk_reader.h"

#define DEBUG 1
#ifdef DEBUG
  #define DEBUG(x) x
#else
  #define DEBUG(x) ((void)0)
#endif

void fatalError(String err);

DiskReader disk;
SoftwareSerial DiskPlayerSerial(8, 9);
DFRobotDFPlayerMini DiskPlayer;
bool isPlaying;

void setup() {
  // Start with LED off. If on, there's error
  digitalWrite(LED_BUILTIN, LOW);

  // Enable serial only when we're in debug
  DEBUG(Serial.begin(9600));
  DEBUG(while(!Serial));
  DEBUG(Serial.println("Initalizing..."));

  // Connect mp3 player
  DiskPlayerSerial.begin(9600);
  while(!DiskPlayerSerial);
  isPlaying = false;
  if (!DiskPlayer.begin(DiskPlayerSerial))
    fatalError("Unable to initialize mp3 disk player.");

  // Connect to the light sensor
  if (!disk.begin())
    fatalError("Unable to initialize disk reader");

  //DiskPlayer.enableDAC();
  //DiskPlayer.EQ(DFPLAYER_EQ_POP);
  //DiskPlayer.outputSetting(true, 15);
  DiskPlayer.volume(20);
}

void loop() {
  disk_type d = disk.readDisk();
  DEBUG(Serial.print("Disk: "));
  DEBUG(Serial.println(toString(d)));
  DEBUG(Serial.print("DiskPlayer (state): "));
  DEBUG(Serial.println(DiskPlayer.readState()));

  if (d != Disk::unknown)
  {
    if (!isPlaying)
    {
      DEBUG(Serial.println("Playing song..."));
      DiskPlayer.play(d.file_id);
      isPlaying = true;
    }
  }
  else
  {
    if (isPlaying)
    {
      DEBUG(Serial.println("Pausing song..."));
      DiskPlayer.pause();
      isPlaying = false;
    }
  }
}

//////////// Helpers ////////////
void fatalError(String err) {
  // print to console if debug
  DEBUG(Serial.println(err));
  // turn on onboard LED
  digitalWrite(LED_BUILTIN, HIGH);
  // loop forever, we can't recover
  while(1);
}