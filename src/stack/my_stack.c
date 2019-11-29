#include "my_stack.h"
#include <stdio.h>

Stack Stack_create(int capacity){
    Stack stack;
    stack.capacity = capacity;
    stack.size = 0;
    stack.top = NULL;

    return stack;
}

void Stack_clear(Stack* stack){
    if(stack->size != 0){
        StackNode* current = stack->top;
        StackNode* prev;

        do{
            prev = current;
            current = current->next;
            free(prev);
        } while(current);
    }
    stack->size = 0;
}

int Stack_push(Stack* stack, int el){
    if(stack->size == stack->capacity)
        return 0;

    StackNode* node = (StackNode*) malloc(sizeof(StackNode));
    node->data = el;
    node->next = NULL;
    
    StackNode* top = stack->top;
    if(!top)
        stack->top = node;
    
    else{
        while(top->next)
            top = top->next;
        
        top->next = node;
    }

    ++stack->size;
    return 1;
}

int Stack_top(Stack* stack, int* top){
    if(!stack->top)
        return 0;

    else{
        *top = stack->top->data;
        return 1;
    }
}

int Stack_pop(Stack* stack, int* pop){
    if(stack->size == 0)
        return 0;
    
    else if(stack->size == 1){
        *pop = stack->top->data;
        free(stack->top);
        stack->top = NULL;
        stack->size = 0;
        return 1;
    } else{
        StackNode* beforeBottom = stack->top;
        StackNode* bottom = beforeBottom->next;

        while(bottom->next){
            beforeBottom = bottom;
            bottom = bottom->next;
        }

        *pop = bottom->data;
        free(bottom);
        beforeBottom->next = NULL;
        --stack->size;

        return 1;
    }
}