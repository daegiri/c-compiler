#pragma once

enum {
    COMPILER_FILE_COMPILED_SUCCESSFULLY,
    COMPILER_FAILED_WITH_ERRORS,
};

int compile_file(const char *filename, const char *output, int flags);