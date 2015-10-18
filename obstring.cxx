#include <iostream>
#include <cstdlib>
#include <cstring>
#include "obstring.h"

using namespace std;
using namespace main_savitch_4;

obstring::obstring(const char str[ ]){
  current_length = strlen(str);
  allocated = current_length + 1;
  sequence = new char[allocated];
  strcpy(sequence, str);
}

