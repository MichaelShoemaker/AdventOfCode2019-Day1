#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int calcval(double);
int main(int argc, char *argv[]){
    double time_spent = 0.0;
    clock_t begin = clock();


    int totalfuel = 0;
    int placeholder = 0;

    FILE *inptr;
    inptr = fopen("input.txt", "r");

    char my[100];

    if (inptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create .\n");
        return 3;
    }
    while(!feof(inptr)){
        fgets(my, 100, inptr);
        totalfuel = totalfuel + calcval(atoi(my));
    }
    printf("%i\n", totalfuel);

    fclose(inptr);
    clock_t end = clock();
    time_spent +=(double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elapsed is %f seconds\n", time_spent);
    return 0;
}
int calcval(double mass){
    double fuel = (mass/3.0);
    int interfuel = (int)floor(fuel);
    int finalfuel = interfuel - 2;
    return finalfuel;
}




