#include <stdio.h>
#include <ctype.h>

int main(){
    char questions[][100] = { "1.Who is the one of human name? :",                        
                              "2.Who is first the winner in flied game ?:",                          
                              "3.Why do you like ROR : "};
     char options[][100] = {"A.Adam", "B.Lubu", "C.Jack", "D.Bhudda",                           
                            "A.Adam", "B.Sasaki", "C.Thor", "D.Bhudda",
                            "A.is Good", "B.Idk", "C.I don't see", "D.Bad"};
     char answer[3] ={'A','C','A'};
     int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);

     char guess;
     int score;

     printf("Quiz Game\n");

     for (int i = 0; i < numberOfQuestions; i++)
     {
        printf("********************************\n");
        printf("%s\n", questions[i]);
        printf("********************************\n");
        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("%s\n", options[j]);
        }
        
        printf("Guess :");
        scanf("%c", &guess);
        scanf("%c");

        guess = toupper(guess);
        if (guess == answer[i])
        {
            printf("Correct\n");
            score++;
        }
        else
        {
            printf("Wrong\n");
        }
        
     }
     printf("********************************\n");
     printf("Final score : %d/%d\n", score,numberOfQuestions);
     printf("********************************\n");
}