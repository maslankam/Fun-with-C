#include <stdio.h>
#include <stdlib.h>	

struct linkedStack{
    struct node *lastNode;
    int size;
};


struct node{
    int Item;
    struct node *predecessor;
};

void push(struct linkedStack *linked, int value){
    struct node *n = malloc(sizeof(struct node));
    n -> predecessor = linked -> lastNode;
    n -> Item = value;
   
    linked -> lastNode = n;
    linked -> size++;
}

int pop(struct linkedStack *linked){
    if(linked -> size == 0){
        printf("Stack is empty");
        return -1;
    }
    
    struct node *n = linked -> lastNode;
    
    int result = n -> Item;
    
    if(linked -> size == 1){
        linked -> lastNode = NULL;
    }
    else{
        linked -> lastNode = n -> predecessor;
    }
    linked -> size--;
    
    free(n);
    
    return result;
}

void init(struct linkedStack *linked){
    linked -> lastNode = NULL;
    linked -> size = 0;
}

void dispose(struct linkedStack *linked){
    while(linked -> size > 0){
        pop(linked);
    }
}




