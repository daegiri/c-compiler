#include "buffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

struct buffer *buffer_create() {
    struct buffer *buffer = malloc(sizeof(struct buffer));
    buffer->data = malloc(BUFFER_INITIAL_SIZE);

    buffer->max_size = BUFFER_INITIAL_SIZE;
    buffer->read_index = 0;
    buffer->size = 0;

    return buffer;
}

void buffer_resize(struct buffer *buffer, size_t size) {
    size_t new_size = buffer->max_size + size;

    buffer->data = realloc(buffer->data, new_size);
    buffer->max_size = new_size;
}

void buffer_ensure_capacity(struct buffer *buffer, size_t size) {
    if (buffer->max_size <= (buffer->size + size)) {
        buffer_resize(buffer, size);
    }
}

void buffer_write(struct buffer *buffer, char c) {
    buffer_ensure_capacity(buffer, sizeof(char));

    buffer->data[buffer->size] = c;
    buffer->size++;
}

void buffer_rewind(struct buffer* buffer) {
    buffer->read_index = 0;
    buffer->size = 0;
}

char *buffer_get_data(struct buffer *buffer) {
    return buffer->data;
}

char buffer_read(struct buffer *buffer) {
    if (buffer->read_index >= buffer->size) {
        return -1;
    }

    char c = buffer->data[buffer->read_index];
    buffer->read_index++;
    return c;
}

char buffer_peek(struct buffer *buffer) {
    if (buffer->read_index >= buffer->size) {
        return -1;
    }

    char c = buffer->data[buffer->read_index];
    return c;
}

void buffer_free(struct buffer *buffer) {
    free(buffer->data); buffer->data = NULL;
    free(buffer); buffer = NULL;
}