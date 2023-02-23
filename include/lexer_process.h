#pragma once 

#include "compiler_token.h"
#include "compile_process.h"
#include "vector.h"
#include "buffer.h"

struct lexer_process;

struct lexer_process_functions {
    char (*next_char)(struct lexer_process *process);
    char (*peek_char)(struct lexer_process *process);
    void (*push_char)(struct lexer_process *process, char c);
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

struct lexer_process *lexer_process_create(struct compile_process *compile_process, struct lexer_process_functions *functions, void *private);
void lexer_process_destroy(struct lexer_process *lexer_process);
void *lexer_process_get_private_data(struct lexer_process *lexer_process);
struct vector *lexer_process_get_token_vector(struct lexer_process *lexer_process);