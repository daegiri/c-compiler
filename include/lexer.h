#pragma once

#include "lexer_process.h"

enum {
    LEXICAL_ANALYSIS_SUCCESSFUL,
    LEXICAL_ANALYSIS_FAILED_WITH_ERRORS,
};

int lexer(struct lexer_process *lexer_process);