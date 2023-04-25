#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main()
{
    int floor;
    int ceil;
    scanf("%d%d", &floor, &ceil);

    int odgovor=INT_MIN;
    int guess=INT_MIN;
    int jeProtislovje=0;

    while (odgovor!=0){
        guess=(floor+ceil)/2;
        scanf("%d",&odgovor);

        if (odgovor == 1){
            floor=guess+1;
        }
        else if (odgovor == -1){
            ceil=guess-1;
        }
        if (floor>ceil || ceil<floor){
            printf("PROTISLOVJE");
            break;
        }
        if (odgovor==0){
            if (floor==ceil){
                printf("%d",ceil);
            }
            else{
                printf("%d %d",floor,ceil);
            }
            break;
        }
    }
}
