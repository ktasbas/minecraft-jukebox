#include "disk.h"

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