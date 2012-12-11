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

struct Allocator {
  void* New(size_t sz) { return malloc(sz); }
  static void Delete(void* p) { free(p); }
};

int main(int argc, char** argv)
{
  QHashMap<const char*, const char*, KeyTraits, Allocator> map;

  map.Lookup("hello", true)->value = "world";
  printf("%s\n", map.Lookup("hello", false)->value);

  return 0;
}
