#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include "random.h"

int random(int seed){
    return  (3 * seed + 2) % 100;
}


int main(){
    int seed = (long int) currenttime;
    //printf("%d\n", seed);
    double num;
    double average;

    for (int i = 0; i < 100; i++){
        seed = random(seed);      
	num = (float) seed / 100;
        printf("%.2f ", num);
        average += num;
	
    }
    printf("\n");
    printf("%f", average/100);

    return 0;
}

    

