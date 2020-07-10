#include <gba_input.h>
#include "keyapi.h"

short getKey(){
  scanKeys();
  unsigned short key = keysDown();
  switch (key)
  {
  case 1:
    return 'A';
  case 2:
    return 'B';
  case 512:
    return 'L';
  case 256:
    return 'R';
  case 64:
    return 'A'+'U';
  case 32:
    return 'A'+'L';
  case 128:
    return 'A'+'D';
  case 16:
    return 'A'+'R';
  case 8:
    return 'S'+'T';
  case 4:
    return 'S'+'L';
  case 3:
    return 'A'+'B';
  case 768:
    return 'L'+'R';
  case 12:
    return 'S'+'S';
  default:
    return 0x00;
  }
}