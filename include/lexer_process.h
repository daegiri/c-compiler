#pragma once 

#include "compiler_token.h"
#include "compile_process.h"
#include "vector.h"
#include "buffer.h"

struct lexer_process_functions {
    char (*next_char)(struct lexer_process *lexer_process);
    char (*peek_char)(struct lexer_process *lexer_process);
    void (*push_char)(struct lexer_process *lexer_process, char c);
};

struct lexer_process {
    struct position position;
    struct compile_process *compile_process;
    
    struct vector *token_vector;
    struct buffer *parenthesis_buffer;

    struct lexer_process_functions *functions;

    int current_expression_count;

    void *private;
};