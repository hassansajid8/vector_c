#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 10

// implementation of vector functions

// declarations for internal functions

static void __appendint(Vector*, int*);
static void __appendfloat(Vector*, float*);
static void __appendchar(Vector*, char*);
static void __appendstr(Vector*, char*);
static void __resize(Vector*);

void vec_init(Vector* vec, enum VectorType type){
    switch (type) {
    case INT:
        int* intarr = malloc(sizeof(int) * BUFSIZE);
        vec->__arr = intarr;
        break;
    
    case FLOAT:
        float* floatarr = malloc(sizeof(float) * BUFSIZE);
        vec->__arr = floatarr;
        break;

    case CHAR:
        char* chararr = malloc(sizeof(char) * BUFSIZE);
        vec->__arr = chararr;
        break;

    case STRING:
        char** strarr = malloc(sizeof(char*) * BUFSIZE);
        vec->__arr = strarr;
        break;

    default:
        printf("$> Wrong vector type. Try again.\n");
        return;
    }    

    vec->__type = type;
    vec->__size = 0;
    vec->__mem = BUFSIZE;
}

void vec_append(Vector* vec, void* value) {
    if(vec->__size >= vec->__mem) {
        __resize(vec);
    }

    switch (vec->__type) {
    case INT:
        __appendint(vec, (int*) value);
        break;

    case FLOAT:
        __appendfloat(vec, (float*) value);
        break;

    case CHAR:
        __appendchar(vec, (char*) value);
        break;
    
    case STRING:
        __appendstr(vec, (char*) value);
        break;
    default:
        break;
    }
}

static void __appendint(Vector* vec, int* value) {
    if(vec->__type != INT){
        return;
    }

    ((int*)vec->__arr)[vec->__size] = *value;
    int size = vec->__size;
    vec->__size = size + 1;

}

static void __appendfloat(Vector* vec, float* value) {
    if(vec->__type != FLOAT) {
        return;
    }

    ((float*)vec->__arr)[vec->__size] = *value;
    vec->__size = vec->__size + 1;
}

static void __appendchar(Vector* vec, char* value) {
    if(vec->__type != CHAR) {
        return;
    }

    ((char*)vec->__arr)[vec->__size] = *value;
    vec->__size = vec->__size + 1;
}

static void __appendstr(Vector* vec, char* value) {
    if(vec->__type != STRING) return;

    char* newstr = malloc(strlen(value) + 1);
    if(!newstr){
        printf("$> Error allocating memory for new string");
        return;
    }

    strcpy(newstr, value);
    ((char**)vec->__arr)[vec->__size++] = newstr;
}

void vec_show(Vector* vec){
    if(vec->__size == 0){
        printf("$> The list is empty\n");
        return;
    }

    int i;

    switch (vec->__type) {
    case INT:
        printf("{ ");
        for(i=0;i<vec->__size;i++) printf("%d, ", ((int*)vec->__arr)[i]);
        printf("}\n");
        break;
    
    case FLOAT:
        printf("{ ");
        for(i=0;i<vec->__size;i++) printf("%.3f, ", ((float*)vec->__arr)[i]);
        printf("}\n");
        break;

    case CHAR:
        printf("{ ");
        for(i=0;i<vec->__size;i++) printf("%c, ", ((char*)vec->__arr)[i]);
        printf("}\n");
        break;

    case STRING:
        printf("{ ");
        for(i=0;i<vec->__size;i++) printf("%s, ", ((char**)vec->__arr)[i]);
        printf("}\n");
        break;
    
    default:
        break;
    }
}

void* vec_get(Vector* vec, int index) {
    if(index < 0 || index >= vec->__size) return NULL;

    switch (vec->__type) {
    case INT:
        return &((int*) vec->__arr)[index];
        break;

    case FLOAT:
        return &((float*) vec->__arr)[index];
        break;

    case CHAR:
        return &((char*)vec->__arr)[index];
        break;

    case STRING:
        return ((char**)vec->__arr)[index];
        break;
    
    default:
        printf("$> type not set correctly(probably)\n");
    }
}

int vec_getsize(Vector* vec) {
    return vec->__size;
}

void vec_set(Vector* vec, void* value, int index){
    if(index >= vec->__size){
        printf("$> Error: invalid index\n");
        return;
    }

    switch (vec->__type) {
    case INT:
        ((int*)vec->__arr)[index] = *(int*)value;
        break;

    case FLOAT:
        ((float*)vec->__arr)[index] = *(float*)value;
        break;

    case CHAR:
        ((char*)vec->__arr)[index] = *(char*)value;
        break;

    case STRING:
        char* mem = realloc(((char**)vec->__arr)[index], strlen((char*)value) + 1);
        if(!mem) {
            printf("$> Error reallocating memory\n");
            return;
        }
        strcpy(mem, value);
        ((char**)vec->__arr)[index] = mem;
        break;
    
    default:
        printf("$> Type not set correctly (probably) \n");
        break;
    }
    return;
}

static void __resize(Vector* vec){
    printf("$> Resizing vector\n");

    size_t type_size;
    switch(vec->__type) {
        case INT: type_size = sizeof(int); break;
        case FLOAT: type_size = sizeof(float); break;
        case CHAR: type_size = sizeof(char); break;
        case STRING: type_size = sizeof(char*); break;
        default: return;
    }

    vec->__mem += BUFSIZE;
    void* temp = realloc(vec->__arr, vec->__mem * type_size);
    if (!temp) {
        printf("Error: realloc failed during resize\n");
        return;
    }

    vec->__arr = temp;
}

void vec_free(Vector *vec) {
    if(vec == NULL){
        printf("$> Vector is null\n");
        return;
    }
    if(vec->__arr != NULL){
        printf("\tvec->_arr not null\nFreeing _arr...\n");
        if(vec->__type == STRING) {
            for(int i=0;i<vec->__size;i++){
                printf("\t\tFreeing string %s...\n", ((char**)vec->__arr)[i]);
                free(((char**)vec->__arr)[i]);
            }
        }
        free(vec->__arr);
    }
    printf("\tFreeing vec...\n");
}