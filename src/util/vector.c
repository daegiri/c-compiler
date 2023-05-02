#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>

#include "vector.h"

vector *vector_create_with(size_t capacity, size_t element_size) {
    vector *vector = malloc(sizeof(vector));
    vector->data = malloc(capacity * element_size);

    vector->element_size = element_size;
    vector->capacity = capacity;
    vector->read_index = 0;
    vector->size = 0;

    return vector;
}

vector *vector_create(size_t element_size) {
    vector *vector = malloc(sizeof(vector));
    vector->data = malloc(VECTOR_DEFAULT_CAPACITY * element_size);

    vector->element_size = element_size;
    vector->capacity = VECTOR_DEFAULT_CAPACITY;
    vector->read_index = 0;
    vector->size = 0;

    return vector;
}

void vector_push(vector *v, const void *element) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * v->element_size);
    }
    memcpy((char*)v->data + v->size * v->element_size, element, v->element_size);
    v->size++;
}

void* vector_peek(vector *v) {
    if (v->size == 0) return NULL;

    size_t last_index = (v->size - 1) * v->element_size;
    return (char*)v->data + last_index;
}

void vector_pop(vector *v) {
    if (v->size == 0) return;

    size_t last_index = (v->size - 1) * v->element_size;
    v->size--;
    memset((char*)v->data + last_index, 0, v->element_size);
}

void *vector_read(vector *v) {
    if (v->size == 0 || v->read_index == v->size) return NULL;

    void *element = (char*)v->data + v->read_index * v->element_size;
    v->read_index++;

    return element;
}

void *vector_read_at(vector *v, size_t index) {
    if (v->size == 0 || index >= v->size) return NULL;

    return (char*)v->data + index * v->element_size;
}

void *vector_back(vector *v) {
    if (v->size == 0) return NULL;

    return vector_read_at(v, v->read_index - 1);
}

void vector_rewind(vector *v) {
    v->read_index = 0;
}

void vector_destroy(vector *v) {
    free(v->data); v->data = NULL;
    free(v); v = NULL;
}