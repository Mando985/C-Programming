#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main(){
    
    char questions[3][100]={"1. What is the color of the sky on a clear day?",
    "2. Which number comes after 2?",
    "3. What do you use to write on paper?"};
    char mcqs[3][4][20]={
        {"A) Red","B) Blue","C) Green","D) Yellow"},
        {"A) 1", "B) 3", "C) 4","D) 5"},
        {"A) A hammer", "B) A pen", "C) A spoon","D) A shoe"}
    };
    char ans[3]={'B','B','B'};
    int a;

    for (int i = 0; i < 3; i++)
     {
        printf("%s\n", questions[i]); 
        
        for (int j = 0; j < 4; j++)

        {
            printf("%s\n", mcqs[i][j]); 
        }

        printf("Enter the answer:\n");
        char choice;
        scanf("%c",&choice);
        choice=toupper(choice);
        while (getchar() != '\n');
        
        if(choice==ans[i])
        {
            printf("Thats correct!\n");
            a++;
        }
        else
        {
            printf("Thats wrong!\n");
        }
        
    }
printf("Your score is %d/3",a);
    return 0;
}