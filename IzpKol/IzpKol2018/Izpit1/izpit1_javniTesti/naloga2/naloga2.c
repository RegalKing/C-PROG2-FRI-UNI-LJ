
/*
 * Va"sa re"sitev druge naloge --- datoteko dopolnite in jo oddajte na spletno u"cilnico!
 *
 * Your solution to task 2 --- complete the file and submit it to U"cilnica!
 *
 * V naslednjo vrstico vpi"site va"so vpisno "stevilko / Enter your student ID number in the next line:
 *
 */

#include "naloga2.h"

uchar* preberi(char* imeDatoteke, int* sirina, int* visina, int* stBajtov) {
    
    FILE* input = fopen(imeDatoteke, "rb");

    char* temp = malloc (10* sizeof(char));
    fgets(temp, 10, input);
    int width, height;
    fscanf(input,"%d %d",&width,&height);
    fgets(temp, 10, input);
    fgets(temp, 10, input);

    *sirina=width;
    *visina=height;

    uchar* binary = malloc(3*width*height*sizeof(uchar));

    fread(binary, sizeof(uchar), 3*width*height, input);

    return binary;

    *stBajtov=3*width*height;

}

int sivina(uchar* pike, int sirina, int visina, int vrstica, int stolpec) {
    // popravite oz. dopolnite / modify and/or add ...
    return -1;
}

int main() {
    // po "zelji dodajte kodo za ro"cno testiranje ...
    // add manual testing code if desired ...
    return 0;
}
