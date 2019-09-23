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


int main()
{
    printf("Hello World\n");
    struct arrayStack stk;
    init(&stk, 64);
    
    push(&stk, 1);
    push(&stk, 2);
    
    int a = pop(&stk);
    printf("%d, expected: 2\n",a);
    a = pop(&stk);
    printf("%d, expected: 1\n",a);
    a = pop(&stk);
    printf("%d, expected: Empty Stack\n",a);
    
    dispose(&stk);
    printf("New stack\n");
    init(&stk, 3);
    
    push(&stk, 1);
    push(&stk, 2);
    push(&stk, 3);
    push(&stk, 4);
    printf("expected: Stack overflow\n");
    
    a = pop(&stk);
    printf("%d, expected: 3\n",a);
    a = pop(&stk);
    printf("%d, expected: 2\n",a);
    a = pop(&stk);
    printf("%d, expected: 1\n",a);
    a = pop(&stk);
    printf("%d, expected: Empty Stack\n",a);
    
    return 0;
}
