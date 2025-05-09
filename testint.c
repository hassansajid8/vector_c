#include <stdio.h>
#include "vector.h"

int main(){
    printf("Testing int vector");
    int a;

    Vector list;
    vec_init(&list, INT);

    printf("append 13 numbers to vector:\n");
    for(int i = 0; i<13;i++){
        scanf("%d", &a);
        vec_append(&list, &a);
    }

    vec_show(&list);

    a = 27;
    vec_set(&list, &a, 4);

    printf("size of list = %d\n", vec_getsize(&list));
    printf("element at index 9 = %d\n", *(int*)vec_get(&list, 9));

    vec_show(&list);

    vec_free(&list);

    printf("exiting program\n");
    return 0;
}