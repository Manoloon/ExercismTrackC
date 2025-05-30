#include "circular_buffer.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

circular_buffer_t *new_circular_buffer(size_t capacity)
{
    if(capacity < 1) return NULL;
    circular_buffer_t* new_buffer = malloc(sizeof(circular_buffer_t));
    if(new_buffer == NULL) return NULL;
    new_buffer->values = calloc(capacity,sizeof(buffer_value_t));
    if(new_buffer->values == NULL)
    {
        free(new_buffer);
        return NULL;
    }

    new_buffer->capacity = capacity;
    new_buffer->head = 0;
    new_buffer->tail = 0;
    new_buffer->size = 0;
    new_buffer->num_items = 0;
    return new_buffer;
}

void delete_buffer(circular_buffer_t *buffer)
{
    if(buffer)
    {
        free(buffer->values);
        free(buffer);
    }
}

void clear_buffer(circular_buffer_t *buffer)
{
    if(buffer == NULL) return;
    for(size_t i = 0; i < buffer->capacity;++i)
    {
       buffer->values[i] = 0;
    }
    buffer->head = 0;
    buffer->tail = 0;
    buffer->size = 0;
    buffer->num_items = 0;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t* OutValue)
{
    if(buffer == NULL)
    {
        fprintf(stderr,"Read from an empty buffer is WRONG");
        return 1;
    }
    if(buffer->num_items == 0) return 1;
    *OutValue = buffer->values[buffer->head];
    buffer->num_items--;
    buffer->head = (buffer->head + 1) % buffer->size;
    return 0;
    
}

int16_t write(circular_buffer_t *buffer, buffer_value_t values)
{
    if(buffer == NULL)
    {
        return 1;
    }
    // is full
    if(buffer->capacity == buffer->num_items)
    {
        overwrite(buffer,values);
    }
    else
    {
        buffer->tail = (buffer->tail + 1) % buffer->size;
        buffer->values[buffer->tail] = values;
        buffer->num_items++;
    }
    return 0;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t values)
{
    if(buffer == NULL || values == 0)
    {
        return 1;
    }
    buffer->values[0] = values;
    buffer->tail = 0;
    return 0;
}
