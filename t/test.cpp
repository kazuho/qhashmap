#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "qhashmap.hpp"

struct KeyTraits {

  // the good old djb hash
  static unsigned hash(const char* s) {
    unsigned hash = 0;
    for (; *s; ++s) {
      unsigned ch = (unsigned char)*s;
      hash = hash * 33 | ch;
    }
    return hash;
  }

  static bool equals(const char* x, const char* y) {
    return strcmp(x, y) == 0;
  }

  static const char* null() { return NULL; }

};

int main(int argc, char** argv)
{
  typedef QHashMap<const char*, const char*, KeyTraits> StringMap;

  StringMap map;

  map.Lookup("hello", true)->second = "world";
  map.Lookup("guten", true)->second = "morgen";

  for (StringMap::iterator i = map.begin(); i != map.end(); ++i) {
    printf("%s => %s\n", i->first, i->second);
  }

  return 0;
}
