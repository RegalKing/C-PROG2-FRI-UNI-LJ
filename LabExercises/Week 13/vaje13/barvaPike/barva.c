#include <stdio.h>
#include <stdlib.h>


int main (int argc, char** argv){

    FILE* input = fopen(argv[1], "rb");
    int width = atoi(argv[2]);
    int height= atoi(argv[3]);

    int tempNumber = 10;
    char* temp = malloc (10 * sizeof(char));

    int ReadWidth, ReadHeight;

    fgets(temp, tempNumber, input); // preberemo vrstico P6 (P6 = 2 char + \n = 1 char + '\0' = 1 char)
    fscanf(input, "%d %d", &ReadWidth, &ReadHeight);
    fgets(temp, tempNumber, input); // preberemo newline po 3 2 stevilkah
    fgets(temp, tempNumber, input); // preberemo 255 vrstico (255 = 3 char + \n = 1 char + '\0' = 1 char)

    unsigned char* bits = malloc (3*ReadWidth*ReadHeight*sizeof(unsigned char)); //preberemo podatke o pixlih (R G B dele posameznega pixla)
    fread(bits, sizeof(unsigned char), 3*ReadWidth*ReadHeight, input);
    fclose(input);

    // najdemo barvne komponente pixlov na podanih koordinatah
    int indeks = 3*(width*ReadHeight+height);
    printf("%d %d %d\n", bits[indeks], bits[indeks+1], bits[indeks+2]);

}
