#include <stdlib.h>

#include "vector.h"
#include "lexer_process.h"

struct lexer_process *lexer_process_create(struct compile_process *compile_process, struct lexer_process_functions *functions, void *private) {
    struct lexer_process *lexer_process = malloc(sizeof(struct lexer_process));
    lexer_process->token_vector = vector_create(sizeof(struct token));

    lexer_process->compile_process = compile_process;
    lexer_process->functions = functions;
    lexer_process->private = private;
    lexer_process->position.column = 1;
    lexer_process->position.line = 1;

    return lexer_process;
}

void lexer_process_destroy(struct lexer_process *lexer_process) {
    vector_destroy(lexer_process->token_vector);
    free(lexer_process);
}

void *lexer_process_get_private_data(struct lexer_process *lexer_process) {
    return lexer_process->private;
}

struct vector *lexer_process_get_token_vector(struct lexer_process *lexer_process) {
    return lexer_process->token_vector;
}