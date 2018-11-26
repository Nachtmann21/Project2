#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mem.h>

typedef struct DEALERSHIP{
    char *category;
    char *brand;
    char *carDealer;
    int price;
    int year;
    char *condition;
    struct DEALERSHIP *next;
}DEALERSHIP;

struct node *temp = NULL;

#define MAXCHAR 201

DEALERSHIP *functionN(int *repeat);
void *functionV(int *repeat);

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

DEALERSHIP *functionN(int *repeat){
    char *word = malloc(sizeof(char) * MAXCHAR);
    int number = 0;
    int count = 0;

    FILE *fptr;
    fptr = fopen("..\\auta.txt", "r");

    if(fptr == NULL) {
        printf("Zaznamy neboli nacitane");
        return NULL;
    } else{
        //counts the number of data
        while(fgets (word, MAXCHAR, fptr)!= NULL) {
            if(word[0] == '$'){
                count++;
            }
        }

        rewind(fptr);
        DEALERSHIP *p_s = NULL;
        DEALERSHIP *first = (DEALERSHIP *) malloc(sizeof(DEALERSHIP));

        for(int i = 0; i < count; i++){
            p_s = (DEALERSHIP *) malloc(sizeof(DEALERSHIP));
            fgetc(fptr);
            fgetc(fptr);

            fgets(word, MAXCHAR, fptr);
            word[strlen(word) - 1] = '\0';
            p_s->category = word;
            printf("%s\n", p_s->category);

            fgets(word, MAXCHAR, fptr);
            word[strlen(word) - 1] = '\0';
            p_s->brand = word;
            printf("%s\n", p_s->brand);

            fgets(word, MAXCHAR, fptr);
            word[strlen(word) - 1] = '\0';
            p_s->carDealer = word;
            printf("%s\n", p_s->carDealer);

            fscanf(fptr, "%d", &number);
            p_s->year = number;
            fgetc(fptr);
            printf("%d\n", p_s->year);

            fscanf(fptr, "%d", &number);
            p_s->price = number;
            fgetc(fptr);
            printf("%d\n", p_s->price);

            fgets(word, MAXCHAR, fptr);
            word[strlen(word) - 1] = '\0';
            p_s->condition = word;
            printf("%s\n", p_s->condition);

            if(i == 0){
                first = p_s;
            }
        }
        printf("Nacitalo sa %d zaznamov", count);

        *repeat = count;
        return first;
    }
}

void *functionV(int *repeat){

}