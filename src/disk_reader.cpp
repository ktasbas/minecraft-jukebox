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

long DiskReader::readRawDisk()
{
  if (!init) return -1;
  
  float r, g, b;
  long rgb;
  
  sensor.setInterrupt(false);
  delay(30);
  sensor.getRGB(&r, &g, &b);
  rgb = ((long)r << 16L) | ((long)g << 8L) | ((long)b);
  sensor.setInterrupt(true);

  return rgb;
}

disk_type DiskReader::readDisk()
{
  long rgb = readRawDisk();
  return rgbToDisk(rgb);
}

disk_type DiskReader::rgbToDisk(long rgb)
{
  for (const auto & d : Disk::disks) {
    if (d.range_min > rgb && d.range_max < rgb)
      return d;
  }
}
