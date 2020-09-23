#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int *p_cislo = NULL;
    int cislo = 7; 
    p_cislo = &cislo;
    
    // p_cislo = adresa ukazatele
    // *p_cislo = hodnota ukazatele
    // &cislo = adresa promenne
    
    printf("Hodnota promenne je %d.\n",cislo);
    printf("Hodnota ukazatele na promennou je %d.\n",*p_cislo);
    printf("Adresa ukazatele je %p.\n",p_cislo);
    printf("Adresa promenne je %p.\n",&cislo);
    
    // inkrement do ukazatele
    (*p_cislo)++;
    printf("Hodnota ukazatele po inkrementu je %d.\n",*p_cislo);
    
    return (EXIT_SUCCESS);
}

