#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mem.h>
#include "Functions.h"

int main() {
    char c;
    int repeat = 0;
    DEALERSHIP *first = NULL;

    while((c = (char) getchar()) != 'k'){
        if(c == 'n'){
            first = functionN(&repeat);
        }
        if(c == 'v'){
            functionV(first);
        }
    }
    //if no dealership data exists, no need to free
    if(first != NULL){
        free(first);
    }

    return 0;
}

