#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Prototype function to calculate each line in file
int calcval(double);
int main(void){
    //setup timing of execution
    double time_spent = 0.0;
    clock_t begin = clock();

    //inialize variables for total fuel
    int totalfuel = 0;
    int placeholder = 0;
    //create file pointer
    FILE *inptr;
    //open file
    inptr = fopen("input.txt", "r");
    //create character array to hold values from file
    char my[100];

    //if file pointer is unsucessfule close pointer
    if (inptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create .\n");
        return 1;
    }
    
    //while it's not the end of the file get 100 characters per line and put them in the my array
    while(!feof(inptr)){
        fgets(my, 100, inptr);
        //update total fuel with result of calcval function
        totalfuel = totalfuel + calcval(atoi(my));
    }
    //print total fuel
    printf("%i\n", totalfuel);

    fclose(inptr);
    clock_t end = clock();
    time_spent +=(double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elapsed is %f seconds\n", time_spent);
    return 0;
}
int calcval(double mass){
    //for each input divide by 3
    double fuel = (mass/3.0);
    //round down and convert to an int
    int interfuel = (int)floor(fuel);
    //subtract 2
    int finalfuel = interfuel - 2;
    //return result
    return finalfuel;
}




