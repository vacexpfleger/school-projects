#include <stdio.h>
#include <stdlib.h>
#define VSTUP "cisla.txt"
#define VYSTUP "vysledky.txt"
#define pi = 3.14

int main(int argc, char** argv) {
    FILE *vstupniSoubor;
    FILE *vystupniSoubor;
    
    int r;
    int hValec;
    int vVoda;
    float vValec;
    float hVoda;
    
    vstupniSoubor = fopen (VSTUP,"r");
    if(vstupniSoubor == NULL){
        printf("Soubor %s se nepodarilo precist.\n",VSTUP);
        return (EXIT_FAILURE);
    }
    
    vystupniSoubor = fopen (VYSTUP,"w");
    if(vystupniSoubor == NULL) {
        printf("Soubor %s se nepodarilo vytvorit.\n",VYSTUP);
        return (EXIT_FAILURE);
    }
    
    while(fscanf(vstupniSoubor,"%d %d %d",&r,&hValec,&vVoda)==2){
        vValec = (float)2*pi*r*(r+hValec);
        
        
    }
    return (EXIT_SUCCESS);
}

