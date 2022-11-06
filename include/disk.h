#ifndef __DISK_H__
#define __DISK_H__

#include <Arduino.h>

struct range_type {
  uint8_t min, max;
};

/**
 * Defines an individual disk
 */
struct disk_type {
    const char * name;
    range_type r, g, b;
    int file_id;

    bool operator==(const disk_type &rhs) const;
    bool operator!=(const disk_type &rhs) const;
};

/**
 * Holds all possible disks
 */
class Disk {
public:
  static const disk_type unknown;
  static const disk_type blueWait;
  static const disk_type greenCat;
  static const disk_type purpleMall;
  static const disk_type purpleMellohi;
  static const disk_type redBlocks;
  static const disk_type redChirp;

  static const disk_type disks[7];
};

/**
 * Returns the string associated with a Disk type
 */
String toString(disk_type disk);

#endif