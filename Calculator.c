#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char a='Y';
    do
    {
    float x;
    float y;
    char op;

    printf("Enter your first number:\n");
    scanf("%f",&x);
    while (getchar() != '\n');
    printf("Enter your operator: + - * /\n");
    scanf("%c",&op);
    printf("Enter your second number:\n");
    scanf("%f",&y);

    switch (op)
    {
    case '+':
        float z= x+y;
        printf("%.2f",z);
        break;
    case '-':
        z=x-y;
        printf("%.2f",z);
        break;
    case '*':
        z=x*y;
        printf("%.2f",z);
        break;
    case '/':
        z=x/y;
        printf("%.2f",z);
        break;
    
    default:
        break;
    
    }
    printf("\nDo you want to do it again?\nYes(Y) or No(N)\n");
    while (getchar() != '\n');
    scanf("%c",&a);
    a=toupper(a);
    } while (a=='Y');
    

    return 0;
}

