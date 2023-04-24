#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

main(){
    for (float fahrenheit=0;fahrenheit<=300;fahrenheit+=20){
        printf("%3.0f Fahrenheit\t ---> ",fahrenheit);
        printf("%3.1f Celsius\n",5*(fahrenheit-32)/9); /* Using the formula for conversion from Fahrenheit to Celsius */
    }
}
