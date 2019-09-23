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

void Push(struct linkedStack *linked, int value){
    struct node *n = malloc(sizeof(struct node));
    n -> predecessor = linked -> lastNode;
    n -> Item = value;
   
    linked -> lastNode = n;
    linked -> size++;
}

int Pop(struct linkedStack *linked){
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

int main(int argc, char *argv[])
{
  // struct linkedStack linked;
   struct linkedStack linked;
   linked.lastNode = NULL;
   linked.size = 0;
   
   struct linkedStack *linkptr = &linked;
   
    Push(linkptr, 1);
    Push(linkptr, 2);
    Push(linkptr, 3);
    Push(linkptr, 4);
    Push(linkptr, 5);
    Push(linkptr, 6);
    
    int a = Pop(linkptr);
    printf("%d\n", a);
    a = Pop(linkptr);
    printf("%d\n", a);
    a = Pop(linkptr);
    printf("%d\n", a);
    a = Pop(linkptr);
    printf("%d\n", a);
    a = Pop(linkptr);
    printf("%d\n", a);
    a = Pop(linkptr);
    printf("%d\n", a);
    a = Pop(linkptr);
    printf("%d\n", a);
    
    
    return 0;
}





