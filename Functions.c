#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mem.h>
#include "Functions.h"

#define MAXNAME 200
#define MAXCONDITION 100
#define MAXCHAR 50

//reads all data from text file, saves it into a linked list
DEALERSHIP *functionN(int *repeat){
    char *word = malloc(sizeof(char) * MAXCHAR);
    int count = 0;

    //reads from this file, be careful, the path may vary depending on your IDE
    FILE *fptr;
    fptr = fopen("..\\auta.txt", "r");

    //if no data was found in file
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

                fgets(carDealer, MAXNAME, fptr);
                carDealer[strlen(carDealer) - 1] = '\0';
                p_s->carDealer =  carDealer;

                fscanf(fptr, "%d", &number);
                p_s->price = number;
                fgetc(fptr);

                fscanf(fptr, "%d", &number);
                p_s->year = number;
                fgetc(fptr);

                fgets(condition, MAXCONDITION, fptr);
                condition[strlen(condition) - 1] = '\0';
                p_s->condition = condition;

                //creates linked list
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
                //if there is only one data part in text file
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

                fgets(carDealer, MAXNAME, fptr);
                carDealer[strlen(carDealer) - 1] = '\0';
                p_s->carDealer = carDealer;

                fscanf(fptr, "%d", &number);
                p_s->price = number;
                fgetc(fptr);

                fscanf(fptr, "%d", &number);
                p_s->year = number;
                fgetc(fptr);

                fgets(condition, MAXCONDITION, fptr);
                condition[strlen(condition) - 1] = '\0';
                p_s->condition = condition;

                //no need to create temp struct
                first = p_s;
                first->next = NULL;
            }
        }
        printf("Nacitalo sa %d zaznamov\n", count);

        *repeat = count;
        return first;
    }
}

//prints the loaded data in linked list
void functionV(DEALERSHIP *first){
    DEALERSHIP *p_s = NULL;
    int count = 1;
    p_s = first;

    //runs until ->next is null
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

//filter cars with same brand and lower price
void functionH(DEALERSHIP *first){
    DEALERSHIP *p_s = NULL;
    char *carBrand = malloc(sizeof(char) * MAXCHAR);
    char *brandCompare;
    int count = 1;
    int carPrice = 0;
    p_s = first;

    //wait for user input
    scanf("%s", carBrand);
    scanf("%d", &carPrice);
    strlwr(carBrand);

    //runs until ->next is null
    while (p_s != NULL) {
        brandCompare = strlwr(p_s->brand);
        if(p_s->price <= carPrice && strcmp(brandCompare, carBrand) == 0){
            printf("%d.\n", count++);
            printf("kategoria: %s\n", p_s->category);
            printf("znacka: %s\n", p_s->brand);
            printf("predajca: %s \n", p_s->carDealer);
            printf("cena: %d\n", p_s->price);
            printf("rok_vyroby: %d\n", p_s->year);
            printf("stav_vozidla: %s\n", p_s->condition);
        }
        p_s = p_s->next;
    }

    //if no cars met conditions, print message
    if(count == 1){
        printf("V ponuke niesu pozadovane auta\n");

    }
}

#pragma clang diagnostic pop