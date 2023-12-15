#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char playerShape(){
    char shape;
    printf("[r]ock , [p]aper , [s]cissors, [q]uit :");
    scanf("%c", &shape);
    return shape;
}
char computerShape(){
    int r;
    r = rand() % 3;
    char s[]={'r','p','s'};
    return s[r];
}
int main(){
    srand(time(NULL));
   // printf("%c\n",playerShape());
   // computerShape();

    char player, computer;
    player = playerShape();
    computer = computerShape();
    printf("player -> %c\n",player);
    printf("computer -> %c\n",computer); 
    if (player == computer)
    {
        printf("Tie\n");
    }
    else{
        if (player == 'r' && computer == 's' )
        {
            printf("You won\n");
        }
        else if (player == 's' && computer == 'p')
        {
            printf("You won\n");
        }
        else if (player == 'p' && computer == 'r')
        {
            printf("You won\n");
        }
        else{
            printf("You Lose\n");
        }
    }


}