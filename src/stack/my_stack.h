#ifndef MY_STACK_H
#define MY_STACK_H

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    int capacity;
    int size;
    StackNode* top;
} Stack;

#ifdef __cplusplus
extern "C"{
#endif

Stack Stack_create(int capacity);
void Stack_clear(Stack* stack);
int Stack_push(Stack* stack, int el);
int Stack_top(Stack* stack, int* top);
int Stack_pop(Stack* stack, int* pop);

#ifdef __cplusplus
}
#endif


#endif /* MY_STACK_H */