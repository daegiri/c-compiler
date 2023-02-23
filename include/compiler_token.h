#pragma once

#include <stdbool.h>
#include <stdint.h>

enum {
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_SYMBOL,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_COMMENT,
    TOKEN_TYPE_NEWLINE,
};

struct position {
    uint64_t line;
    uint64_t column;
};

struct token {
    int type;
    int flags;

    union {
        char c_val;
        const char *s_val;
        unsigned int i_num;
        unsigned long l_num;
        unsigned long long ll_num;
        void *any;
    };

    bool whitespace;
    const char *between_brackets;
    const char *filename;
};