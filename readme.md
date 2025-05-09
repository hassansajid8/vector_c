# Vectors
dynamic, one-dimensional arrays that can store elements of the same data type

## How to use
- clone repo
- include "vector.h" in your c file
- compile the vector.c file along with your program, or create a static library.
- see test files for example implementation
- *Do not forget to free the array after use using vec_free()*

## Documentation

### Usage

- Initialization
    - declare a variable of type Vector
    - initialize the vector using vec_init function with one of four types: int, float, char or string
    - void vec_init(Vector* vec, VectorType type)
    - usage

    ```bash
        Vector vector;
        vec_init(&vector, INT);
    ```

- Append item
    *only append functionality is available as of now*
    - void vec_append(Vector* vec, void* value)
    - the function expects the address (pointer) of the value. Strings can be passed within double quotes, but other types have to be stored in a variable and their address is to be passed to the function.
    - example usage

    ```bash
        // have to store value in a variable and pass its address
        int num = 27;
        vec_append(&int_vector, &num);

        // strings can be passed within double quotes
        vec_append(&string_vector, "some string");
    ```

- Get value of item at specific index
    - void* vec_get(Vector *vec, int index);
    - returns a void pointer pointing to the value.
    - returned value has to be explicitly typecasted and dereferenced accordingly.
    - example usage

    ```bash
        printf("Integer value at index 16 = %d", \*(int*)vec_get(&vector, 16));
        printf("Value at index 24 = %s", (char*)vec_get(&vector, 24));
    ```

- Update value at specific index (set)
    - void vec_set(Vector* vec, void* new_value, int index)
    - Updates value at specific index.
    - In case of string, it reallocates memory everytime (as of now), which can affect performance on frequent updates.
    - example usage

    ```bash 
        int a = 27;
        vec_set(&vector, &a, 8);
    ```

- Print all elements of the list
    - void vec_show(Vector *vec)
    - displays all elements present in the vector
    - print format: { item1, item2, item3, }
    - example usage

    ```bash
        vec_show(&vector);
    ```

- Get length of array
    - int vec_getsize(Vector *vec);
    - returns an integer, the number of items present in the vector.
    - example usage

    ```bash
        int len = vec_getsize(&vector);
    ```

- Cleanup: Free the vector
    - void vec_free(Vector *vec)
    - frees all memory allocated within the vector
    - call this function when you no longer need the vector, or before terminating the program for proper cleanup
    - Modern operating systems will cleanup any memory after program ends, but it's good style to manually free any memory you allocated.
    - example usage

    ```bash
        vec_free(&vector);
    ```


### Contact the dev
- email: hassansajid.dev@gmail.com  
- linkedin: https://www.linkedin.com/in/hassansajid008/
        


