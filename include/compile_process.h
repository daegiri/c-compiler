#pragma once

#include <stdio.h>

struct compile_process {
    int flags;

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