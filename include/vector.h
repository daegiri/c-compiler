#pragma once

#include <stddef.h>

typedef struct vector {
    void *data;          // Pointer to the data

    size_t size;         // Number of elements in the vector
    size_t capacity;     // Number of elements the vector can hold
    size_t element_size; // Size of each element in bytes
    size_t read_index;   // index of the element to read (left to right)
} vector;

#define VECTOR_DEFAULT_CAPACITY 42

vector *vector_create_with(size_t capacity, size_t element_size);
vector *vector_create(size_t element_size);
void vector_destroy(vector *v);

void vector_push(vector *v, const void *element);

void vector_pop(vector *v);
void *vector_peek(vector *v);
void *vector_read(vector *v);
void *vector_read_at(vector *v, size_t index);
void *vector_back(vector *v);

void vector_rewind(vector *v);