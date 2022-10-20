# CONNECT 4 
### By FRICHOT Roman
### Github link : https://github.com/Maeyxx
![N|Solid](https://www.polesup-delasalle.fr/wp-content/uploads/sites/5/2020/01/Sticker-Fili%C3%A8re-SI_Publi%C3%A9-250x250.jpg) 

## Introduction
This game look like [lululataupe.com (Connect 4)](https://lululataupe.com/tout-age/686-puissance-4) programming in C language.

## How to play ?
Launch program and follow instructions.

## How it works ?
If you choose any case in the array (7x6) i.e. 42 possibilities to insert a token.
In this game you have two players (P1 => player 1) & (P2 => player 2).
Player 1 start the game.

You have two symbols to simule token :
| Player | Symbol | 
| ------ | ------ | 
| 1 |  x | 
| 2 |  o |

If you have four symbols aligned horizontally, vertically or diagonally you win the game.

##### Win array example(Player1 win) :
# 
| | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| ------  | ------ | ------ | ------ |  ------ | ------ | ------ |  ------ |
| 1 | ------ | ------ |  ------ | ------ | ------ |  ------ | ------ |
| 2 | ------ | ------ |  ------ | ------ | ------ |  ------ | ------ |
| 3 | X | ------ |  ------ | ------ | ------ |  ------ | ------ |
| 4 | X |O |  ------ | ------ | ------ |  ------ | ------ |
| 5 | X |O |  ------ | ------ | ------ |  ------ | ------ |
| 6 | X | O |  ------ | ------ | ------ |  ------ | ------ |
| | 1 | 2 | 3 | 4 | 5 | 6 | 7 |

=> Result : Player 1 win

## Program connect to libraries
To works properly this program `include libraries` available in **header.h** :
```sh
#include "stdio.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
```

> ` !!!! Don't touch any libraries in this project if you don't wan't a crash !`

## Program functions
We use differents functions in this program 
| FUNCTION NAME | TYPE  | DESCRIPTION |
| ------ | ------ | ------ |
| currentPlayer | int | This function return the current player |
| printBattlefield | void | This function return the UX interface |
| insertColumn | char ** | This function insert token in column |
| checkWin | int | This function check if the game is win |
| checkLoose | int | This function check if the game is loose  |
| insertArraySpace | char ** | This function insert somes space in the battlefield |
| playGame | void | This function is call by the main function to play the game ! |
