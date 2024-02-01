#include "emul.hpp"
#include <stdio.h>

int main(int argc, const char *argv[]) {
  bool issues = false;
  if (sizeof(uint32) != 4) {
    printf("There's a problem with your system: type `uint32` must be a 32-bit unsigned integer; on your system, it's %d bits.\nPlease edit `emul.hpp` and ensure type `uint32` is defined to be a 32-bit unsigned integer.\n", sizeof(uint32)*8);
    issues = true;
  }
  if (!issues) {
    printf("No issues found.\n");
  }
  return 0;
}
