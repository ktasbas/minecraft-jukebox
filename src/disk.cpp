#include "disk.h"

const disk_type Disk::unknown = {"unknown", .r = {55,60}, .g = {85,90}, .b = {85,90}, .file_id = -1};
const disk_type Disk::blue = {"blue", .r = {27,40}, .g = {82,90}, .b = {110,125}, .file_id = 1};
const disk_type Disk::green = {"green", .r = {51,63}, .g = {104,116}, .b = {54,75}, .file_id = 2};
const disk_type Disk::purple = {"purple", .r = {42, 55}, .g = {73,76}, .b = {107, 122}, .file_id = 3};

const disk_type Disk::disks[] = {
  Disk::unknown,
  Disk::blue,
  Disk::green,
  Disk::purple,
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