// Including header file and call prototype
#include "header.h"

/// @brief Function to create UX battlefield interface
/// @param turn : number of turn
/// @param battlefield : the battlefield
/// @param indexCurrentPlayer : index of current player

void printBattlefield(int *indexCurrentPlayer, int *turn, char ** battlefield)
{
    int row, column;

    row = 0;
    printf("Player 1 symbols = x\nPlayer 2 symbols = o\n\n");
    printf("                                   1   2   3   4   5   6   7  \n");

    do
    {
        printf("                                 +---+---+---+---+---+---+---+\n");
        printf("                                 | ");
        column = 0;
        do
        {
            printf("%c | ", battlefield[row][column]);    
            column++;        
        } while (column < 7);
        
        printf("\n");
        row++;    
    } while (row < 6);
    
    printf("                                 +---+---+---+---+---+---+---+\n");
    printf("                                   1   2   3   4   5   6   7  \n\n\n");
    printf("Player %s, it's your turn. (turn %d)\n", currentPlayer(*indexCurrentPlayer), *turn);
}


#pragma region Checker
/// @brief Function to check if the player win
/// @param battlefield : the battlefield
/// @return 
int checkWin(char **battlefield)
{
    int row;
    int column;

    row = 0;
    while(row < 3)
    {
        column = 0;
        while (column < 7)
        {
            if(battlefield[row][column] != ' ')
            {
                if (battlefield[row][column] == battlefield[row + 1][column] && battlefield[row][column] == battlefield[row + 2][column] && battlefield[row][column] == battlefield[row + 3][column])
                {
                    return 1;
                }
            }
            column++;
        }
        row++;
    }

    row = 0;
    while(row < 6)
    {
        column = 0;
        while (column < 4)
        {
            if(battlefield[row][column] != ' ')
            {
                if (battlefield[row][column] == battlefield[row][column + 1] && battlefield[row][column] == battlefield[row][column + 2] && battlefield[row][column] == battlefield[row][column + 3])
                {
                    return 1;
                }
            }
            column++;
        }
        row++;
    }

    row = 0;
    while(row < 3)
    {
        column = 0;
        while (column < 4)
        {
            if(battlefield[row][column] != ' ')
            {
                if (battlefield[row][column] == battlefield[row + 1][column + 1] && battlefield[row][column] == battlefield[row + 2][column + 2] && battlefield[row][column] == battlefield[row + 3][column + 3])
                {
                    return 1;
                }
            }
            column++;
        }
        row++;
    }

    row = 0;

    // verify if the row is not the last one
    // if it is the last one, we don't need to check the diagonal
    //
    while(row < 3)
    {
        column = 3;
        while (column < 7)
        {
            if(battlefield[row][column] != ' ')
            {
                if (battlefield[row][column] == battlefield[row + 1][column - 1] && battlefield[row][column] == battlefield[row + 2][column - 2] && battlefield[row][column] == battlefield[row + 3][column - 3])
                {
                    return 1;
                }
            }
            column++;
        }
        row++;
    }

    return 0;
}

/// @brief Function to check if the player loose
/// @param battlefield : the battlefield
/// @return 
int checkLoose(char **battlefield)
{
    int m = 0;
    int n = 0;

    while (m < 6)
    {
        while (n < 7)
        {
            if(battlefield[m][n] == ' ')
                return 0;
            n++;
        }
        m++;
    }
    return 2;
}

#pragma endregion

#pragma region Controller

/// @brief Function to determine the current player
/// @param indexCurrentPlayer 
/// @return 
char *currentPlayer(int indexCurrentPlayer)
{
    if(indexCurrentPlayer % 2 == 0)
        return("P1");
    else
        return("P2");
}

/// @brief Function to check if the game is over and control turn of the game
/// @param turn : number of turn
/// @param battlefield : the battlefield
/// @param indexCurrentPlayer : index of the current player (P1 or P2)
/// @return 
int controlTurn(int *indexCurrentPlayer, int *turn, char **battlefield)
{
    int checkWinResult, checkLooseResult;

    battlefield = insertColumn(battlefield, currentPlayer(*indexCurrentPlayer));
    *indexCurrentPlayer = *indexCurrentPlayer + 1;
    *turn = *turn + 1;
    checkWinResult = checkWin(battlefield);
    checkLooseResult = checkLoose(battlefield);


    printBattlefield(indexCurrentPlayer, turn, battlefield);

    if(checkWinResult == 1)
    {
        printf("-> Result : Player %s win !\n", currentPlayer(*indexCurrentPlayer-1));
        return 1;
    }
    else if(checkLooseResult == 2)
    {
        printf("-> Result : egality");
        return 1;
    }
    
    return 0;
}

#pragma endregion

#pragma region Game logic

/// @brief Function to insert a token in the column of the battlefield
/// @param battlefield :    The battlefield
/// @param player :         The player who plays
/// @return 
char **insertColumn(char **battlefield, char *player)
{
    int initialisator = 0;
    int column;
    int row = 6 - 1;
    char token;

    int resultPlayer = strcmp(player, "P1");
    
    switch(resultPlayer)
    {
        case 0:
            token = 'x';
            break;
        case 1:
            token = 'o';
            break;
    }


    printf("Choose where you put your piece (1-7) : ");
    scanf("%d", &column);
    column--;

    if(column < 0 || column > 6)
    {
        printf("failed input\n");
        printf("Please retry\n");
        insertColumn(battlefield, player);
    }
    
    do
    {
        if(battlefield[row][column] == ' ')
        {
            battlefield[row][column] = token;
            initialisator = 1;
        }
        else
            row--;    
    } while (row != -1 && initialisator == 0);
    
    if(row == -1)
    {
        insertColumn(battlefield, player);
        printf("Column is full please choose another one\n");
    }
    return(battlefield);
}

/// @brief Initialize the battlefield with empty space
/// @param battlefield : the battlefield
/// @param row : the row of the battlefield
/// @param column : the column of the battlefield
/// @return 
char **insertArraySpace(char **battlefield, int row, int column)
{
    int m = 0; 

    do
    {
        int n = 0;
        do
        {
            battlefield[m][n] = ' ';
            n++;
        } while (n < column);
        
        battlefield[m][n] = '\0';
        m++;
    } while (m < row);

    return(battlefield);
}
#pragma endregion


/// @brief function to launch the game
void playGame()
{
    int control, indexCurrentPlayer, turn, m = 0;
    char **battlefield;


    // battlefield is a 2D array
    battlefield = malloc(sizeof(char *) * 6);
   
   // we allocate memory for each row
    do
    {
        battlefield[m] = malloc(sizeof(char) * 7 + 1);
        m++;    
    } while (m < 6);
    
    // we initialize the battlefield with space
    battlefield = insertArraySpace(battlefield, 6, 7 + 1);

    turn = 1;
    indexCurrentPlayer = 0;
    control = 0;

    // we print the battlefield
    printBattlefield(&indexCurrentPlayer, &turn, battlefield);

    do
    {
      // we control the turn
      control = controlTurn(&indexCurrentPlayer, &turn, battlefield);
    } while (control == 0);
}

/// @brief main function
int main(void)
{
    playGame();
    return 0;
}