#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mem.h>
#include "Functions.h"

#define MAXCHAR 200

DEALERSHIP *functionN(int *repeat){
    char *word = malloc(sizeof(char) * MAXCHAR);
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
        //rewind back to start of file
        rewind(fptr);

        DEALERSHIP *p_s = NULL;
        DEALERSHIP *first = (DEALERSHIP *) malloc(sizeof(DEALERSHIP));
        DEALERSHIP *temp = (DEALERSHIP *) malloc(sizeof(DEALERSHIP));

        for(int i = 0; i < count; i++){
            //if more than 1 data struct was found in file
            if(count != 1){
                char *category = malloc(sizeof(char) * MAXCHAR);
                char *brand = malloc(sizeof(char) * MAXCHAR);
                char *carDealer = malloc(sizeof(char) * MAXCHAR);
                char *condition = malloc(sizeof(char) * MAXCHAR);
                int number = 0;

                p_s = (DEALERSHIP *) malloc(sizeof(DEALERSHIP));

                fgetc(fptr);
                fgetc(fptr);

                fgets(category, MAXCHAR, fptr);
                category[strlen(category) - 1] = '\0';
                p_s->category = category;

                fgets(brand, MAXCHAR, fptr);
                brand[strlen(brand) - 1] = '\0';
                p_s->brand = brand;

                fgets(carDealer, MAXCHAR, fptr);
                carDealer[strlen(carDealer) - 1] = '\0';
                p_s->carDealer =  carDealer;

                fscanf(fptr, "%d", &number);
                p_s->year = number;
                fgetc(fptr);

                fscanf(fptr, "%d", &number);
                p_s->price = number;
                fgetc(fptr);

                fgets(condition, MAXCHAR, fptr);
                condition[strlen(condition) - 1] = '\0';
                p_s->condition = condition;

                if(i == 0){
                    first = p_s;
                    first->next = temp;
                    temp = first;
                } else {
                    temp->next = p_s;
                    temp = temp->next;
                }
                temp->next = NULL;

            } else {
                char *category = malloc(sizeof(char) * MAXCHAR);
                char *brand = malloc(sizeof(char) * MAXCHAR);
                char *carDealer = malloc(sizeof(char) * MAXCHAR);
                char *condition = malloc(sizeof(char) * MAXCHAR);
                int number = 0;
                p_s = (DEALERSHIP *) malloc(sizeof(DEALERSHIP));

                fgetc(fptr);
                fgetc(fptr);

                fgets(category, MAXCHAR, fptr);
                category[strlen(category) - 1] = '\0';
                p_s->category = category;

                fgets(brand, MAXCHAR, fptr);
                brand[strlen(brand) - 1] = '\0';
                p_s->brand = brand;

                fgets(carDealer, MAXCHAR, fptr);
                carDealer[strlen(carDealer) - 1] = '\0';
                p_s->carDealer = carDealer;

                fscanf(fptr, "%d", &number);
                p_s->year = number;
                fgetc(fptr);

                fscanf(fptr, "%d", &number);
                p_s->price = number;
                fgetc(fptr);

                fgets(condition, MAXCHAR, fptr);
                condition[strlen(condition) - 1] = '\0';
                p_s->condition = condition;

                first = p_s;
                first->next = NULL;
            }
        }
        printf("Nacitalo sa %d zaznamov\n", count);

        *repeat = count;
        return first;
    }
}

void functionV(DEALERSHIP *first){
    DEALERSHIP *p_s = NULL;
    int count = 1;
    p_s = first;

    while (p_s != NULL) {
        printf("%d.\n", count++);
        printf("kategoria: %s\n", p_s->category);
        printf("znacka: %s\n", p_s->brand);
        printf("predajca: %s\n", p_s->carDealer);
        printf("cena: %d\n", p_s->price);
        printf("rok_vyroby: %d\n", p_s->year);
        printf("stav_vozidla: %s\n", p_s->condition);
        p_s = p_s->next;
    }
}
#pragma clang diagnostic pop