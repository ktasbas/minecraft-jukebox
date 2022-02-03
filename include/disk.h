#ifndef __DISK_H__
#define __DISK_H__

#include <Arduino.h>

/**
 * Defines an individual disk
 */
struct disk_type {
    const char * name;
    long range_min, range_max;
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
  static const disk_type blue;

  static const disk_type disks[2];
};

/**
 * Returns the string associated with a Disk type
 */
String toString(disk_type disk);

#endif