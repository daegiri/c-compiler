#include <stdlib.h>

#include "compiler.h"
#include "lexer.h"

struct lexer_process_functions compiler_lexer_functions = {
    .next_char = compile_process_next_char,
    .peek_char = compile_process_peek_char,
    .push_char = compile_process_push_char
};

int compile_file(const char *filename, const char *output, int flags) {
    struct compile_process *compile_process = compile_process_create(filename, output, flags);
    if (!compile_process) {
        return COMPILER_FAILED_WITH_ERRORS;
    }

    struct lexer_process *lexer_process = lexer_process_create(compile_process, &compiler_lexer_functions, NULL);
    
    if (!lexer_process) {
        compile_process_destroy(compile_process);
        return COMPILER_FAILED_WITH_ERRORS;
    }

    if (lexer(lexer_process) != LEXICAL_ANALYSIS_SUCCESSFUL) {
        compile_process_destroy(compile_process);
        return COMPILER_FAILED_WITH_ERRORS;
    }

    return COMPILER_FILE_COMPILED_SUCCESSFULLY;
}