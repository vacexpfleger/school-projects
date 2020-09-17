#include <stdio.h>
#include <stdlib.h>
#define VSTUP "cisla.txt"
#define VYSTUP "vysledky.txt"

int main(int argc, char** argv) {
    int draha;
    int cas;
    int poradi=1;
    int drahaComplete=0;
    int drahaAvg;
    float rychlost;
    
    FILE *soubor;
    FILE *soubor2;
    
    soubor = fopen(VSTUP,"r");
    if (soubor == NULL) {
        printf("Soubor %s se nepodarilo precist.\n", VSTUP);
        return EXIT_FAILURE;
    }
    
    soubor2 = fopen(VYSTUP,"w");
    if (soubor2 == NULL) {
        printf("Soubor %s se nepodarilo vytvorit.\n",VYSTUP);
        return EXIT_FAILURE;
    }

    while(fscanf(soubor,"%d %d",&draha, &cas)==2){
        rychlost = (float)draha/cas;
        printf("%d.\t%d metru\t%d sekund\t%.2f m/s\n",poradi,draha,cas,rychlost);
        fprintf(soubor2,"%d.\t%d metru\t%d sekund\t%.2f m/s\n",poradi,draha,cas,rychlost);
        drahaComplete += draha;
        poradi++;
    }
    
    drahaAvg = drahaComplete/(poradi-1);
    printf("\nPrumerna draha je %d metru.\n",drahaAvg);
    fprintf(soubor2,"\nPrumerna draha je %d metru.\n",drahaAvg);
    printf("Ze souboru %s bylo pricteno %d dvojic cisel.\n",VSTUP,poradi-1);
    fprintf(soubor2,"Ze souboru %s bylo pricteno %d dvojic cisel.\n",VSTUP,poradi-1);

    if(fclose(soubor)==EOF){
        printf("Soubor %s se nepodarilo zavrit.\n",VSTUP);
    }
    if(fclose(soubor2)==EOF){
        printf("Soubor %s se nepodarilo zavrit.\n",VYSTUP);
    }
    else {
        printf("Soubor %s se byl uspesne vytvoren.\n",VYSTUP);
    }

    return (EXIT_SUCCESS);
}

