#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "compile_process.h"
#include "lexer_process.h"

struct compile_process *compile_process_create(const char *input_filename, const char *output_filename, int flags) {
    FILE *file = fopen(input_filename, "r");
    if (!file) {
        return NULL;
    }

    FILE *output = fopen(output_filename, "w");
    if (!output) {
        fclose(file);
        return NULL;
    }

    struct compile_process *process = malloc(sizeof(struct compile_process));

    process->flags = flags;
    process->c_file.file_ptr = file;
    process->o_file.file_ptr = output;

    return process;
}

void compile_process_destroy(struct compile_process *compile_process) {
    fclose(compile_process->c_file.file_ptr);
    fclose(compile_process->o_file.file_ptr);
    free(compile_process); compile_process = NULL;
}

char compile_process_next_char(struct lexer_process *lexer_process) {
    struct compile_process *compile_process = lexer_process->compile_process;
    compile_process->position.column++;

    char c = getc(compile_process->c_file.file_ptr);

    if (c == NEW_LINE) {
        compile_process->position.line++;
        compile_process->position.column = 1;
    }

    return c;
}

char compile_process_peek_char(struct lexer_process *lexer_process) {
    struct compile_process *compile_process = lexer_process->compile_process;

    char c = getc(compile_process->c_file.file_ptr);
    ungetc(c, compile_process->c_file.file_ptr);

    return c;
}

void compile_process_push_char(struct lexer_process *lexer_process, char c) {
    struct compile_process *compile_process = lexer_process->compile_process;
    ungetc(c, compile_process->c_file.file_ptr);
}