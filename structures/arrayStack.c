#include <stdio.h>
#include <stdlib.h>

struct arrayStack{
    int *array;
    int maxSize;
    int size;
};

void init(struct arrayStack *stk, int size){
    stk -> maxSize = size;
    stk -> size = 0;
    stk -> array = malloc(sizeof(int) * size);
}

void dispose(struct arrayStack *stk){
    stk -> maxSize = 0;
    stk -> size = 0;
    free(stk -> array);
}

void push(struct arrayStack *stk, int value){
    if(stk -> size == stk -> maxSize){
       printf("Stack overflow\n");
       return;
    }
    
    stk -> size++;
    stk -> array[stk -> size] = value; 
}

int pop(struct arrayStack *stk){
   if(stk -> size == 0){
       printf("Empty stack\n");
       return -1;
   } 
   return stk -> array[stk -> size--];
}


