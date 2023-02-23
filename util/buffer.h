#pragma once

#include <stddef.h>

#define BUFFER_INITIAL_SIZE 256

struct buffer {
    char *data;
    size_t read_index;
    size_t size;
    size_t max_size;
};

struct buffer *buffer_create();

void buffer_resize(struct buffer* buffer, size_t size);
void buffer_ensure_capacity(struct buffer* buffer, size_t size);

void buffer_write(struct buffer* buffer, char c);
void buffer_free(struct buffer* buffer);

char *buffer_get_data(struct buffer* buffer);
char buffer_read(struct buffer* buffer);
char buffer_peek(struct buffer* buffer);

void buffer_rewind(struct buffer* buffer);