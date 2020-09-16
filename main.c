/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 16. září 2020, 12:18
 */

#include <stdio.h>
#include <stdlib.h>
#define VSTUP "C:\\Users\\student\\Documents\\NetBeansProjects\\mocniny\\cisla.txt"
#define VYSTUP "vysledky.txt"

unsigned int mocnina (int z, int ex){
    unsigned int moc = 1;
    for(;ex>0;ex--) {
        moc*=z;  
    }
    return moc;
}

int main(int argc, char** argv) {
    int zaklad;
    int exponent;
    FILE *soubor2;
    FILE *soubor;
    soubor = fopen(VSTUP, "r");
    if (soubor == NULL) {
        printf("Soubor %s se nepodarilo otevrit.", VSTUP);
        return EXIT_FAILURE;
    }
    
    soubor2 = fopen(VYSTUP, "r+");
    if (soubor2 == NULL) {
        printf("Soubor %s se nepodarilo otevrit.", VYSTUP);
        getchar();
        return EXIT_FAILURE;
    }
    
    while(fscanf(soubor,"%d %d",&zaklad, &exponent)==2){
        printf("%2d * %2d = %10u \n",zaklad,exponent,mocnina(zaklad,exponent));
        fprintf("%2d * %2d = %10u \n",zaklad,exponent,mocnina(zaklad,exponent));
    }
    
    if (fclose(soubor)==EOF) {
        printf("Soubor se nepodarilo zavrit.");
    }
    if (fclose(soubor2)==EOF){
        printf("Soubor se nepodarilo zavrit.");
    }
    else {
        printf("Soubor byl uspesne vytvoren.");
    }

    return (EXIT_SUCCESS);
}

