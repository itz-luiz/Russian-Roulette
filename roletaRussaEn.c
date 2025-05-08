#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define _CHAMBERS 6

void animateSpin5();
void animateSpin3();

int main(){
    srand(time(0)); // Selects a seed to make rand unpredictable

    printf("\n= Russian Roulette - by: Luiz =");
    printf("\nThe revolver has %d chambers and 1 bullet.", _CHAMBERS);
    printf("\nPress \"enter\" to pull the trigger.");
    printf("\n\nTry your luck...");
    
    // Animate the cylinder spinning
    animateSpin5();

    // Register bullet position (1 = Loaded, 0 = Empty)
    int currentPosition = rand() % _CHAMBERS;
    int bulletPosition = rand() % _CHAMBERS;

    bool alive = true;
    int triggersPulled = 0; // Count how many times the trigger was pulled

    while(alive){
        getchar(); // Wait for user to pull the trigger

        triggersPulled++;
        printf("\nPulled #%d", triggersPulled);
        animateSpin3();

        if(currentPosition == bulletPosition){
            printf("\nBANG! You lost...\n");
            alive = false;
        } else{
            printf("\nClick. You survived!\n");
            currentPosition = (++currentPosition) % _CHAMBERS;
        }   
        
        if(triggersPulled == _CHAMBERS-1){
            printf("\nYou survived! Congratulations!!");
            alive = false;
        }
    }

    printf("\nThank you for playing! See you next time!!");

    return 0;
}

void animateSpin5(){
    printf("\n\nSpinning the cylinder");
    for(int i=0; i<5; i++){
        printf(".");
        sleep(1); // Wait 1 second for the next .
    }
    printf("\n");
}

void animateSpin3(){
    for(int i=0; i<3; i++){
        printf(".");
        sleep(1); // Wait 1 second for the next .
    }
}