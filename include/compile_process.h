#pragma once

#include <stdio.h>

#include "compiler_token.h"
#include "lexer_process.h"

struct lexer_process;

struct compile_process {
    int flags;

    struct position position;

    struct compile_process_input_file {
        const char *abs_path;
        FILE *file_ptr;
    } c_file;

    struct compile_process_output_file {
        const char *abs_path;
        FILE *file_ptr;
    } o_file;
};

struct compile_process *compile_process_create(const char *input_filename, const char *output_filename, int flags);
void compile_process_destroy(struct compile_process *compile_process);

char compile_process_next_char(struct lexer_process *lexer_process);
char compile_process_peek_char(struct lexer_process *lexer_process);
void compile_process_push_char(struct lexer_process *lexer_process, char c);