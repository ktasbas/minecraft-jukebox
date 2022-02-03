#include "disk.h"

const disk_type Disk::unknown = {"unknown", -1, -1, -1};
const disk_type Disk::blue = {"blue", 1650000, 2060000, 1};

const disk_type Disk::disks[] = {
  Disk::unknown,
  Disk::blue,
};

bool disk_type::operator==(const disk_type &rhs) const
{
  if (strcmp(this->name, rhs.name))
    return true;
}

bool disk_type::operator!=(const disk_type &rhs) const
{
  return !(*this == rhs);
}

String toString(disk_type disk)
{
  return disk.name;
}