#include <stdio.h>
#include <stdlib.h>

#include "linkedlists.h"

//Init the linked list. Basically you are creating only the first element
lli list;
lli* plist = &list;

int main(){
    //Here's the real init
    initLLI(plist, 5);
    
    //Add a bunch of values
    pushToLLI(plist, 312);
    pushToLLI(plist, 3142);
    pushToLLI(plist, 3115);
    pushToLLI(plist, 762);
    pushToLLI(plist, 99);
    pushToLLI(plist, 544);
    pushToLLI(plist, 66);

    //Print
    printf("List created and values pushed\n");
    printLLI(plist, true);

    //Pop last value
    popFromLLI(plist);

    //Print Again
    printf("\nPopped last value\n");
    printLLI(plist, true);

    //Remove and index 3
    removeAtIndexLLI(plist, 3);

    //Remove and inexistent index
    removeAtIndexLLI(plist, 8);

    //Print Again
    printf("\nRemoved element at index 3. Tried to remove element at index 8 but list was too small\n");
    printLLI(plist, true);

    //Add but with error
    addAtIndexLLI(plist, 7, 75);

    //Add like if pushing
    addAtIndexLLI(plist, 6, 74);

    //Add in the middle
    addAtIndexLLI(plist, 3, 32);
    
    //Print Again
    printf("\nAdded values at defined indeces. First one was threated like if it was pushed at the end of the list. Second one couldn't be added because the list is too small and last one was added ad defind index\n");
    printLLI(plist, true);

    //Reverse
    reverseLLI(plist);

    //Print Again
    printf("\nReversed the list\n");
    printLLI(plist, true);


}