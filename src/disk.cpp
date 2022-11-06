#include "disk.h"

const disk_type Disk::unknown = {"unknown", .r = {55,60}, .g = {85,90}, .b = {85,90}, .file_id = -1};
const disk_type Disk::blueWait = {"blueWait", .r = {43,47}, .g = {77,82}, .b = {115,119}, .file_id = 1};
const disk_type Disk::greenCat = {"greenCat", .r = {65,70}, .g = {104,111}, .b = {57,65}, .file_id = 2};
const disk_type Disk::purpleMall = {"purpleMall", .r = {51, 57}, .g = {70,75}, .b = {112, 117}, .file_id = 3};
const disk_type Disk::purpleMellohi = {"purpleMellohi", .r = {66, 71}, .g = {65, 69}, .b = {103, 108}, .file_id = 4};
const disk_type Disk::redBlocks = {"redBlocks", .r = {133, 139}, .g = {56, 61}, .b = {49, 53}, .file_id = 5};
const disk_type Disk::redChirp = {"redChirp", .r = {117, 145}, .g = {50, 64}, .b = {52, 62}, .file_id = 6};

const disk_type Disk::disks[] = {
  Disk::unknown,
  Disk::blueWait,
  Disk::greenCat,
  Disk::purpleMall,
  Disk::purpleMellohi,
  Disk::redBlocks,
  Disk::redChirp,
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