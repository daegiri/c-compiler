#include <stdio.h>

#include "compiler.h"

int main(int argc, char **argv) {
    int compile_response = compile_file("./test.c", "./test", 0);

    if (compile_response == COMPILER_FILE_COMPILED_SUCCESSFULLY) {
        printf("Compiled successfully!\n");
    } else if (compile_response == COMPILER_FAILED_WITH_ERRORS) {
        printf("Failed to compile!\n");
    } else {
        printf("Unknown error!\n");
    }

    return 0;
}