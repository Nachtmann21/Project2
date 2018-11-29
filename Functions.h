#ifndef PROJEKT2_FUNCTIONS_H
#define PROJEKT2_FUNCTIONS_H

typedef struct DEALERSHIP{
    char *category;
    char *brand;
    char *carDealer;
    int price;
    int year;
    char *condition;
    struct DEALERSHIP *next;
}DEALERSHIP;

DEALERSHIP *functionN(int *repeat);
void functionV(int *repeat);

#endif //PROJEKT2_FUNCTIONS_H


