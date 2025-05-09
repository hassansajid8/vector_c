#include <stdio.h>
#include <string.h>
#include "vector.h"

int main(){
    printf("Testing int vector\n");
    
    Vector list;
    vec_init(&list, STRING);
    
    printf("append 13 elements to vector:\n");
    for(int i = 0; i<13;i++){
        char a[100];
        scanf("%99s", a);
        vec_append(&list, a);
    }

    vec_show(&list);

    char a[] = "change";
    vec_set(&list, a, 4);

    printf("size of list = %d\n", vec_getsize(&list));
    printf("element at index 9 = %s\n", (char*)vec_get(&list, 9));

    vec_delete(&list, 5);

    vec_show(&list);

    for(int i=0; i<10;i++){
        vec_delete(&list, i);
    }

    vec_show(&list);

    vec_free(&list);

    printf("exiting program\n");
    return 0;
}