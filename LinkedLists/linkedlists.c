#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedlists.h"

//Add value and index to the first value
void initLLI(lli* l, int v) {
    l->index = 0;
    l->value = v;
    l->next = NULL;
    l->prev = NULL;
    // printf("Puzzette\n");
}

//Appends new value as last one in the list
void pushToLLI(lli* l, int v){

    lli* l1 = l;
    //get to the last "index", although we can't really speak about indeces
    while(l1->next != NULL){
        l1 = l1->next;        
    }

    //now create new struct and "append" to the others
    lli* lnew = malloc(sizeof(lli));
    l1->next = lnew;
    lnew->prev = l1;
    lnew->next = NULL;
    lnew->value = v;
    lnew->index = l1->index +1;
}

//Deletes last value
void popFromLLI(lli* l){
    lli* l1 = l;
    //get to the last "index", although we can't really speak about indeces
    while(l1->next != NULL){
        l1 = l1->next;        
    }

    lli* l2 = l1->prev;
    l2->next = NULL;
    free(l1);
   
}

//Adds the value at a certain index, pushing the other values towards the end
void addAtIndexLLI(lli* l, int i, int v){
    
    if(i > sizeOfLLI(l)){
        printf("Index %d too high for list with size %d\n", i, sizeOfLLI(l));
        return;
    }
    if(i == sizeOfLLI(l)){
        pushToLLI(l, v);
        return;
    }
        
    //get to the index
    lli* l1 = l;

    while(l1->next->index != i){
        l1 = l1->next;
    }

    lli* l0 = l1->prev;
    lli* lnew = malloc(sizeof(lli));
    lnew->index = i;
    lnew->prev = l0;
    lnew->next = l1;
    lnew->value=v;

    l0->next = lnew;
    l1->prev = lnew;

    //now fix the indices or there will be problems with size
    while(l1 != NULL){
        l1->index = l1->prev->index +1;
        l1 = l1->next;
    }

}


//Remove the value at a certain index
void removeAtIndexLLI(lli* l, int i){

    if(i >= sizeOfLLI(l)){
        printf("Index %d too high for list with size %d\n", i, sizeOfLLI(l));
        return;
    }

    //get to the index
    lli* l1 = l;

    while(l1->index != i){
        l1 = l1->next;
    }

    lli* l0 = l1->prev;
    lli* l2 = l1->next;

    free(l1);
    l0->next = l2;
    l2->prev = l0;

    //now fix the indices or there will be problems with size
    while(l2 != NULL){
        l2->index = l2->prev->index +1;
        l2 = l2->next;
    }


}

//Prints whole list
void printLLI(lli* l, bool b){
    lli* l1 = l;
    printf("(index)value\n");
    while(l1 != NULL){
        printf("(%d)%d\t", l1->index, l1->value);
        l1 = l1->next;        
    }
    printf("\n");
    if(b) printf("Size: %d\n", sizeOfLLI(l));
}

int sizeOfLLI(lli* l){    

    lli* l1 = l;
    //get to the last "index", although we can't really speak about indeces
    while(l1->next != NULL){
        l1 = l1->next;        
    }

    return l1->index + 1;
}

int valueAtIndexLLI(lli* l, int i){
    if(i >= sizeOfLLI(l)){
        printf("Index %d too high for list with size %d\n", i, sizeOfLLI(l));
        return NULL;
    }
    
    //get to the index
    lli* l1 = l;
    while(l1->index != i){
        l1 = l1->next;
    }
    return l1->value;

}

void reverseLLI(lli* l){

    lli* ll = l;
    //get to the last "index", although we can't really speak about indeces
    while(ll->next != NULL){
        ll = ll->next;        
    }

    lli* lp = ll->prev;
    lli* ln = ll;
    ln->prev = NULL;

    initLLI(ln, ll->value);

    while(lp != NULL){
        pushToLLI(ln, lp->value);

        lp=lp->prev;
    }
    free(lp);
    *l = *ln;

}