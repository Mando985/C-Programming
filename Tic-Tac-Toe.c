
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

void resetBoard();
void printboard();
int checkfreespaces();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);
void gamerecord(char);

char board[3][3];
const char PLAYER='X';
const char COMPUTER='O';
char a='Y';

int main()
{
    char winner=' ';
    resetBoard();
    do
    {
      resetBoard();
      winner=' ';
      while(winner==' '&& checkfreespaces()!=0)
    {
        printboard();
        playermove();
        winner= checkwinner();
        if(winner!=' ' || checkfreespaces()==0)
        {
            break;
        }
        computermove();
        if(winner!=' ' || checkfreespaces()==0)
        {
            break;
        }

    }
    printboard();
    printwinner(winner);
    printf("\nDo you want to continue? Yes (Y) or No (N): ");  
    while (getchar() != '\n');
    scanf("%c",&a);
    a=toupper(a);

    }while (a=='Y');
    
    
    return 0;
}

void resetBoard()
{ 
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j]=' ';
        }
    }
}

void printboard()
{
    printf(" %c | %c | %c",board[0][0],board[0][1],board[0][2]);
    printf("\n---+---+---\n");
    printf(" %c | %c | %c",board[1][0],board[1][1],board[1][2]);
    printf("\n---+---+---\n");
    printf(" %c | %c | %c",board[2][0],board[2][1],board[2][2]);
    printf("\n");

}

int checkfreespaces()
{
    int freespaces= 9;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++ )
        {
            if (board[i][j] !=' ')
            {
                freespaces--;
            }
        }
    }
    return freespaces;
}

void computermove()
{
    srand(time(0));
    int x;
    int y;

    if(checkfreespaces()>0)
    {
        do{
            x=rand()%3;
            y=rand()%3;
        }while(board[x][y] !=' ');

        board[x][y]=COMPUTER;
    }
    else
    {
        printwinner(' ');
    }
}

char checkwinner()
{
    //rows
    for(int i=0; i<3 ; i++)
    {
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2]) 
        {
            return board[i][0];
        }
    }

    //columns
    for(int i=0; i<3 ; i++)
    {
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i])
        {
            return board[0][i];
        }
    }

    //diagonals
    for(int i=0; i<3 ; i++)
    {
        if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
        {
            return board[0][0];
        }
    }

    for(int i=0; i<3 ; i++)
    {
        if(board[0][2]==board[1][1] && board[0][2]==board[2][0])
        {
            return board[0][2];
        }
    }
 return ' ';
}

void gamerecord(char winner)
{
    FILE *file = fopen("score.csv", "r");  
    FILE *temp = fopen("temp.csv", "w");  
    char buffer[100];

    while (fgets(buffer,sizeof(buffer),file))
    {
        int playerscore,computerscore,playerloses,computerloses,draws;
        buffer[strcspn(buffer, "\n")] = 0;
        sscanf(buffer, "%d,%d,%d,%d,%d",&playerscore,&computerscore,&playerloses,&computerloses,&draws);

        if(winner==PLAYER)
        {
        playerscore=playerscore+1;
        computerloses=computerloses+1;
        fprintf(temp,"%d,%d,%d,%d,%d", playerscore,computerscore,playerloses,computerloses,draws);
        printf("The player has won %d times so far, lost %d times so far.",playerscore,playerloses);
        
        }
        else if(winner==COMPUTER)
        {
        computerscore=computerscore+1;
        playerloses=playerloses+1;
        fprintf(temp,"%d,%d,%d,%d,%d", playerscore,computerscore,playerloses,computerloses,draws);
        printf("The Computer has won %d times so far, lost %d times so far.",computerscore,computerloses);
        }
        
        else
        {
        draws=draws+1;
        fprintf(temp,"%d,%d,%d,%d,%d", playerscore,computerscore,playerloses,computerloses,draws);
        printf("It has been %d draws so far.",draws);
        }
        
    }
    
    fclose(file);  
    fclose(temp);

    remove("score.csv");  
    rename("temp.csv", "score.csv");  

}


void printwinner(char winner)
{
    if (winner==PLAYER)
    {
        printf("YOU WIN!!");
        gamerecord(winner);
    }
    else if(winner==COMPUTER)
    {
        printf("YOU LOSE!!");
        gamerecord(winner);

    }
    else
    {
        printf("It is a draw.");
        gamerecord(winner);
    }

}



void playermove()
{
    int x;
    int y;
    
    do{
        printf("Enter row #(1-3):");
        scanf("%d",&x);
        x--;
        printf("Enter column #(1-3):");
        scanf("%d",&y);
        y--;

        if(board[x][y]!=' ')
        {
            printf("invalid move!\n");
        }
        else
        {
            board[x][y]=PLAYER;
            break;
        }
    }while(board[x][y]!=' ');

}
