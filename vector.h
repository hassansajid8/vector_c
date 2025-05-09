#ifndef VECTOR_H
#define VECTOR_H


// list of vector types allowed
enum VectorType {
    INT,
    FLOAT,
    CHAR,
    STRING
};

// type definition for vector
typedef struct Vector {
    void* __arr;
    int __size;
    enum VectorType __type;
    int __mem;
} Vector;

//global functions
void vec_init(Vector*, enum VectorType);
void vec_append(Vector*, void*);
void vec_delete(Vector*, int);
void vec_show(Vector*);
void* vec_get(Vector*, int);
int vec_getsize(Vector*);
void vec_set(Vector*, void*, int);
void vec_free(Vector*);

#endif