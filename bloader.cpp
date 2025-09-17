#include <iostream>
#include <entries.h>
// Ext4 parser
int fsParser() {
  // Setup SD card interface
  *(volatile unsigned int*)0xFE2B0024 = 0;
  *(volatile unsigned int*)0xFE2B002C = 0x1AA;
  *(volatile unsigned int*)0xFE2B0008 = 0;
  *(volatile unsigned int*)0xFE2B000E = 0;
  *(volatile unsigned int*)0xFE2B000E = 8;
  unsigned int response = *(volatile unsigned int*)0xFE2B0034;
  if ((response & 0xFFF) != 0x1AA) {
    return 1;
  }
}

int main() {
}