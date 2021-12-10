#ifndef __DISK_PLAYER_H__
#define __DISK_PLAYER_H__

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include "disk.h"

/// SoftwareSerial recieve pin
#ifndef DISKPLAYER_RX_PIN
#define DISKPLAYER_RX_PIN 8
#endif
/// SoftwareSerial transmit pin
#ifndef DISKPLAYER_TX_PIN
#define DISKPLAYER_TX_PIN 9
#endif

class DiskPlayer 
{
public:
    /**
     * DiskPlayer abstracts the music player information
     */
    DiskPlayer();

    /**
     * Initializes internal sensor connections. Must be called before
     * a DiskPlayer instance is useable.
     * 
     * @return true if init successful, else false
     */
    bool begin();

    /**
     * Plays the file associated with the @param disk object
     * 
     * @return true if disk is valid and playable, else false
     */
    bool play(Disk disk);

private:
    SoftwareSerial serial;
    DFRobotDFPlayerMini player;

    bool init;
};

#endif