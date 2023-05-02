#pragma once

#include "compiler_token.h"
#include "compile_process.h"
#include "lexer_process.h"

enum {
    COMPILER_FILE_COMPILED_SUCCESSFULLY,
    COMPILER_FAILED_WITH_ERRORS,
};

int compile_file(const char *filename, const char *output, int flags);
void compiler_error(struct compile_process *compile_process, const char *msg, ...);