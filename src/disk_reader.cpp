#include "disk_reader.h"

DiskReader::DiskReader() 
  : sensor(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X),
    init(false)
{}

bool DiskReader::begin()
{
  if (!sensor.begin())
    return false;

  init = true;
  return init;
}

rgb_type DiskReader::readRawDisk()
{
  if (!init) return -1;
  
  float r, g, b;
  
  sensor.setInterrupt(false);
  delay(30);
  sensor.getRGB(&r, &g, &b);
  sensor.setInterrupt(true);

  return {
    static_cast<uint8_t>(r),
    static_cast<uint8_t>(g),
    static_cast<uint8_t>(b)
  };
}

disk_type DiskReader::readDisk()
{
  rgb_type rgb = readRawDisk();
  return rgbToDisk(rgb);
}

disk_type DiskReader::rgbToDisk(rgb_type rgb)
{
  for (const auto & d : Disk::disks) {
    if (d.r.min <= rgb.r && d.r.max >= rgb.r) {
      if (d.g.min <= rgb.g && d.g.max >= rgb.g) {
        if (d.b.min <= rgb.b && d.b.max >= rgb.b) {
          return d;
        }
      }
    }
  }
  return Disk::unknown;
}
