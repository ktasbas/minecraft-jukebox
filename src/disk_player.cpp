#include "disk_player.h"

DiskPlayer::DiskPlayer() 
    : serial(DISKPLAYER_RX_PIN, DISKPLAYER_TX_PIN),
    init(false)
{}

bool DiskPlayer::begin() {
    serial.begin(9600);
    if (!player.begin(serial))
        return false;

    player.volume(15);
    
    init = true;
    return true;
}

bool DiskPlayer::play(Disk disk) {
    return true;
}