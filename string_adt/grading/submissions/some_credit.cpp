#include <stdint.h>
#include "String.h"

UTString* utstrdup(const char* src) {
    static UTString str;
    str.length = 0;
    str.capacity = 0;
    str.string = "Hello World";
    return &str;
}
uint32_t utstrlen(const UTString* s) { return 0; }
UTString* utstrcat(UTString* s, const char* suffix) { return 0; }
UTString* utstrcpy(UTString* dst, const char* src) { return 0; }
void utstrfree(UTString* self) { return ; }
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) { return 0; }
