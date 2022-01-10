#include <stdio.h>

int main(int argc, const char* const* argv) {
    --argc, ++argv;
    if (!argc) {
        printf("Usage: corium <source file>\n");
        return 0;
    }

    return 0;
}
