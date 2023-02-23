#include <stdio.h>
#include <stdlib.h>

#include "compile_process.h"

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