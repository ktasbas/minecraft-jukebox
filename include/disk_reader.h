#ifndef __DISK_READER_H__
#define __DISK_READER_H__

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_TCS34725.h>
#include "disk.h"

struct rgb_type {
  rgb_type(uint8_t _r = 0, uint8_t _g = 0, uint8_t _b = 0) :
    r(_r), g(_g), b(_b) {}
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

class DiskReader {
  public:
  /**
   * DiskReader abstracts the disk information for the jukebox
   */
  DiskReader();

  /**
   * Must be called before DiskReader is usable. Init's everything
   * 
   * @return true if init successful, else false
   */
  bool begin();

  /**
   * Returns the raw 24-bit RGB of the inserted disk. This value is
   * helpful when calibrating the values associated with Disk enumerators.
   * 
   * @return Decimal representation of the inserted disk
   */
  rgb_type readRawDisk();

  /**
   * Reads the color of the inserted disk and retrieves the instance of
   * disk_type that represents the disk
   * 
   * @return disk_type
   */
  disk_type readDisk();

  protected:
  /**
   * Determins the instance of disk_type associated with given RGB code
   * 
   * @param rgb_type The RGB value
   * @return disk_type
   */
  disk_type rgbToDisk(rgb_type rgb);
  
  private:
  Adafruit_TCS34725 sensor;
  bool init;
};

#endif
