#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mem.h>
#include "Functions.h"

int main() {
    char c;
    int repeat = 0;
    DEALERSHIP *dealership = NULL;

    while((c = (char) getchar()) != 'k'){
        if(c == 'n'){
            dealership = functionN(&repeat);
        }
        if(c == 'v'){
            functionV(&repeat);
        }
    }

    printf("end of while 2\n");
    free(dealership);

    return 0;
}

