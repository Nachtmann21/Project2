#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mem.h>
#include "Functions.h"

#define MAXCHAR 201

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
        DEALERSHIP *previous = (DEALERSHIP *) malloc(sizeof(DEALERSHIP));

        for(int i = 0; i < count; i++){
            if(count == 1){
                p_s = (DEALERSHIP *) malloc(sizeof(DEALERSHIP));

                fgetc(fptr);
                fgetc(fptr);

                fgets(word, MAXCHAR, fptr);
                word[strlen(word) - 1] = '\0';
                p_s->category = word;

                fgets(word, MAXCHAR, fptr);
                word[strlen(word) - 1] = '\0';
                p_s->brand = word;

                fgets(word, MAXCHAR, fptr);
                word[strlen(word) - 1] = '\0';
                p_s->carDealer = word;

                fscanf(fptr, "%d", &number);
                p_s->year = number;
                fgetc(fptr);

                fscanf(fptr, "%d", &number);
                p_s->price = number;
                fgetc(fptr);

                fgets(word, MAXCHAR, fptr);
                word[strlen(word) - 1] = '\0';
                p_s->condition = word;

                p_s->next = NULL;
                first = p_s;
            }




//            p_s = (DEALERSHIP *) malloc(sizeof(DEALERSHIP));
//            p_s->next = NULL;
//
//            fgetc(fptr);
//            fgetc(fptr);
//
//            fgets(word, MAXCHAR, fptr);
//            word[strlen(word) - 1] = '\0';
//            p_s->category = word;
//            printf("%s\n", p_s->category);
//
//            fgets(word, MAXCHAR, fptr);
//            word[strlen(word) - 1] = '\0';
//            p_s->brand = word;
//            printf("%s\n", p_s->brand);
//
//            fgets(word, MAXCHAR, fptr);
//            word[strlen(word) - 1] = '\0';
//            p_s->carDealer = word;
//            printf("%s\n", p_s->carDealer);
//
//            fscanf(fptr, "%d", &number);
//            p_s->year = number;
//            fgetc(fptr);
//            printf("%d\n", p_s->year);
//
//            fscanf(fptr, "%d", &number);
//            p_s->price = number;
//            fgetc(fptr);
//            printf("%d\n", p_s->price);
//
//            fgets(word, MAXCHAR, fptr);
//            word[strlen(word) - 1] = '\0';
//            p_s->condition = word;
//            printf("%s\n", p_s->condition);
//
//            //the first node of the linked list - *first*
//            if(i == 0){
//                first = p_s;
//            } else{
//
//            }
//            if(count == 1){
//                first->next = NULL;
//            }
//
//            previous->next = p_s;
//            previous = p_s;
//            previous->next = p_s;
        }

        printf("Nacitalo sa %d zaznamov\n", count);

        *repeat = count;
        return first;
    }
}

void functionV(int *repeat){
    printf("------------------------");
}