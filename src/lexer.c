#include <stdlib.h>
#include <memory.h>

#include "lexer.h"
#include "vector.h"
#include "buffer.h"
#include "compiler.h"
#include "constants.h"
#include "compiler_token.h"

struct token *read_next_token();

static struct lexer_process *lex_process;
static struct token tmp_token;

static char peek_char() {
    return lex_process->functions->peek_char(lex_process);
}

static void push_char(char c) {
    lex_process->functions->push_char(lex_process, c);
}

static char next_char() {
    char c = lex_process->functions->next_char(lex_process);
    lex_process->position.column++;

    if (c == NEW_LINE) {
        lex_process->position.line++;
        lex_process->position.column = 1;
    } 

    return c;
}

static struct position lexer_file_position() {
    return lex_process->position;
}

#define LEXER_GET_CHAR_IF(buffer, conditional)                   \
    for (char c = peek_char(); conditional; c = peek_char()) {   \
        buffer_write(buffer, c);                                 \
        next_char();                                             \
    }

struct token *lexer_last_token() {
    return vector_back(lex_process->token_vector);
}

struct token *handle_whitespace() {
    struct token *last_token = lexer_last_token();

    if (last_token) {
        last_token->whitespace = true;
    }

    next_char(); // skipping the whitespace

    return read_next_token();
}

struct token *token_create(struct token *_token) {
    struct token *token = malloc(sizeof(struct token));

    memcpy(token, _token, sizeof(struct token));
    token->position = lexer_file_position();

    return token;
}

unsigned long long read_number() {
    struct buffer *buffer = buffer_create();
    LEXER_GET_CHAR_IF(buffer, (c >= '0' && c <= '9'));

    buffer_write(buffer, 0x00);

    return atoll(buffer->data);
}

struct token *token_make_number_for_value(unsigned long number) {
    return token_create(&(struct token){
        .type = TOKEN_TYPE_NUMBER,
        .ll_num = number,
    });
}

struct token *token_make_number() {
    return token_make_number_for_value(read_number());
}


struct token *read_next_token() {
    struct token *token = NULL;
    char c = peek_char();

    switch (c) {
        NUMERIC_CASE:
            token = token_make_number();
            break;
        WHITESPACE_CASE:
            token = handle_whitespace();
            break;
        case EOF:
            break;
        default:
            compiler_error(lex_process->compile_process, "Unexpected character: %c\n", c);
    }

    return token;
}

int lexer(struct lexer_process *lexer_process) {
    lexer_process->current_expression_count = 0;
    lexer_process->parenthesis_buffer = NULL;
    lexer_process->position.filename = lexer_process->compile_process->c_file.abs_path;

    lex_process = lexer_process;

    struct token *token = read_next_token();

    while(token) {
        vector_push(lexer_process->token_vector, token);
        token = read_next_token();
    }

    return LEXICAL_ANALYSIS_SUCCESSFUL;
}