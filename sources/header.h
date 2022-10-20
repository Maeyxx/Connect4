// including c libraries
#include "stdio.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


// declare prototypes
char *currentPlayer(int indexCurrentPlayer);
void printBattlefield(int *indexCurrentPlayer, int *turn, char **battlefield);
char **insertColumn(char **battlefield, char *player);
int checkWin(char **battlefield);
int checkLoose(char **battlefield);
int controlTurn(int *indexCurrentPlayer, int *turn, char **battlefield);
char **insertArray(char **battlefield, int row, int column);
void playGame();