#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

void push(int);
void pop();
void print();
int get();

typedef struct stack{

    int values[STACK_SIZE];
    int cv;

} bufferStack;

bufferStack stack;
bufferStack* pstack = &stack;

int main(){
    pstack->cv = 0;

    print();

    for(int i = 0; i < STACK_SIZE; i++){
        push(i);
        // print();

        printf("%d\n", get());
    }

    for(int i = 0; i < STACK_SIZE; i++){
        // print();
        pop();
        printf("%d\n", get());
    }
}

void push(int v){

    if(pstack->cv < STACK_SIZE && pstack->cv >= 0){
        pstack->values[pstack->cv] = v;
        pstack->cv++;
        // if(pstack->cv >= STACK_SIZE) pstack->cv--;
    }
}

void pop(){
    if(pstack->cv >= 0){
        pstack->cv--;
        pstack->values[pstack->cv] = 0;
    }
}

int get(){
    return pstack->values[pstack->cv-1];
}

void print(){
    for(int i = 0; i < pstack->cv; i++){
        printf("%d\t", pstack->values[i]);
    }
    printf("\n");
}

