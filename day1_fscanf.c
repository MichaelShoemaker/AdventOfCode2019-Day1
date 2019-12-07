//Changed the fgets to fscanf to try and get a performance increase
//fscanf clocks in at .000086 seconds
//fgets clocks in at .000069 seconds
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

    int temp = 0;

    if (inptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create .\n");
        return 1;
    }
    while(fscanf(inptr,"%d",&temp)!=EOF){
        totalfuel = totalfuel + calcval(temp);
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



