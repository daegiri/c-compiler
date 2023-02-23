#include <stdlib.h>

#include "compiler.h"
#include "compile_process.h"

int compile_file(const char *filename, const char *output, int flags) {
    struct compile_process *compile_process = compile_process_create(filename, output, flags);
    if (!compile_process) {
        return COMPILER_FAILED_WITH_ERRORS;
    }
    


    return COMPILER_FILE_COMPILED_SUCCESSFULLY;
}