#ifndef PROJEKT2_FUNCTIONS_H
#define PROJEKT2_FUNCTIONS_H

//struct used for linked list
typedef struct DEALERSHIP{
    char *category;
    char *brand;
    char *carDealer;
    int price;
    int year;
    char *condition;
    struct DEALERSHIP *next;
}DEALERSHIP;

//functions
DEALERSHIP *functionN(int *repeat);
void functionV(DEALERSHIP *dealership);
void functionH(DEALERSHIP *dealership);

#endif //PROJEKT2_FUNCTIONS_H