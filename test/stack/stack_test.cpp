#include <math.h>
#include "CppUTest/TestHarness.h"
#include "my_stack.h"

#define HALF_CAPACITY floor(stack.capacity/2)

TEST_GROUP(StackTestGroup){
    Stack stack;

    TEST_SETUP(){
        stack = Stack_create(10);
    }

    TEST_TEARDOWN(){
        Stack_clear(&stack);
    }
};

TEST(StackTestGroup, testSizeAfterPush){
    int oldSize = stack.size;

    for(int i = 1; i <= HALF_CAPACITY; ++i)
        CHECK_EQUAL(1, Stack_push(&stack, i));
    
    CHECK_EQUAL(oldSize+HALF_CAPACITY, stack.size);
    
}

TEST(StackTestGroup, testTopOnUnemptyStack){
    int top;
    int valToPush = 10;

    if(Stack_push(&stack, valToPush)){
        Stack_top(&stack, &top);
        CHECK_EQUAL(valToPush, top);
    }
    else 
        FAIL("Pushing on a full stack");
}

TEST(StackTestGroup, testTopOnEmptyStack){
    int top;
    CHECK_EQUAL(0, Stack_top(&stack, &top));
}

TEST(StackTestGroup, testPushOnFullStack){
    int valToPush = 10;

    for(int i = 0; i < stack.capacity; ++i)
        CHECK_EQUAL(1, Stack_push(&stack, valToPush));

    CHECK_EQUAL(0, Stack_push(&stack, valToPush));
}

TEST(StackTestGroup, testPopOnEmptyStack){
    int pop;
    CHECK_EQUAL(0, Stack_pop(&stack, &pop));
}

TEST(StackTestGroup, testPopOnStackWithOneElement){
    int valToPush = 10;
    int pop;

    CHECK_EQUAL(1, Stack_push(&stack, valToPush));
    CHECK_EQUAL(1, Stack_pop(&stack, &pop));
    CHECK_EQUAL(valToPush, pop);
}

TEST(StackTestGroup, testPopOnStackWithMoreThanOneElement){
    for(int valToPush = 1; valToPush <= HALF_CAPACITY; ++valToPush)
        CHECK_EQUAL(1, Stack_push(&stack, valToPush));

    int pop;
    CHECK_EQUAL(1, Stack_pop(&stack, &pop));
    CHECK_EQUAL(HALF_CAPACITY, pop);
}