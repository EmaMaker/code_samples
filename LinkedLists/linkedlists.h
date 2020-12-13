#include <stdbool.h>

typedef struct linkedlistI{

    struct linkedlistI *next;
    struct linkedlistI *prev;
    int index;    
    int value;
} lli;

void initLLI(lli*, int v);
void pushToLLI(lli*, int v);
void popFromLLI(lli*);
void printLLI(lli*, bool);
void addAtIndexLLI(lli*, int i, int v);
void removeAtIndexLLI(lli*, int i);
void reverseLLI(lli*);
int valueAtIndexLLI(lli*, int i);
int sizeOfLLI(lli*);
