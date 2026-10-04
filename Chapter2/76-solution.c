#include <stdio.h>

void* malloc (size_t size);
void* memset (void* s, int c, size_t n);

void* calloc (size_t nmemb, size_t size) {
    unsigned is_overflow = ~0u >> size ;
    void* ptr = malloc (size * nmemb);
    memset(ptr, 0, size * nmemb);
    return ptr;

}

int main () {

}