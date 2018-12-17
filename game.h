#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define MAXNUM 24

void hint(void); //Retrieve the file with the hint to the puzzle.
void winCondition(void); // How to set value of player's guess and the secret word to equal each other
void getAnswer(void); // Retrieve file with the answer

int maxGuess = 7; // Max # of guesses allowed
int numGuess = 1; // Guess interval
char guess[MAXNUM]; // Player's guess
char answer[MAXNUM]; // Secret word to guess

int gameWin(void); //Conditions for winning
int gameLose(void); //Conditions for losing
int gameEnd(void); //Conditions for game ending

void hint()
{
     FILE *fp;
    char str[MAXNUM];
    char* filename = "hint.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error! Unable to open file %s",filename);
        return 1;
        }
    while (fgets(str, MAXNUM, fp) != NULL)
        printf("%s", str);
    fclose(fp);

}

void winCondition()
    {
        int a;
        printf("\n\n");
        for(a = 0; a < MAXNUM; a++)
            if( answer[a] == guess[a] )
            printf("%c", guess[a]);
        else
            printf("&");

        numGuess++;
    }

void getAnswer()
    {
        FILE *pFile;
        pFile = fopen("word.txt", "r");
        fscanf (pFile, "%s", &answer);
        fclose(pFile);
    }

int gameWin()
{

    int b = 1;
    int a;

    for ( a = 0; a < MAXNUM; a++ )
    {
        if( guess[a] != answer[a] )
            return 0;
    }
    return b;

}

int gameLose()
{
    if (gameWin() == 1 || numGuess > maxGuess)
        return 1;
    else
        return 0;
}

int gameEnd()
{
    if (gameWin() == 1)
        return 1;
    else
        return 0;
}


#endif // GAME_H_INCLUDED
