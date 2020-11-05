/** pex1.c
* ===========================================================
* Name: Cleo Cowie
* Section: T1/2
* Project: PEX2
* Purpose: Selection Statements, Iterations, Function Calls
* ===========================================================
* Documentation Statement: 
    C3C Peter Ye looked over the functionality of the pex1.c in order to fix errors that were associated with the game play. 
    More specifically, he recommended to me that I use a pointer in order to switch players after each turn. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "pex1functs.h"

int main (void) {
   int currentTotal=0; // actual current roll score
   int playerZeroScore=0; //player zero score
   int playerOneScore=0; //player one score
   int diceResult; //value from die
   int gamePlayer=0; //player's turn
   const int MAX_POINTS=100; //max amount of points to win Pig Game
   int hold; //variable to indicate whether the player wants to hold or roll
   int turns=0; //turns in game

   printf("Pig!\n\n");

   printf("Player 0 will go first.\n"); //Player 0 will start 

    while (playerZeroScore<MAX_POINTS && playerOneScore<MAX_POINTS) { //game will continue as long as either player's score is below 100
        turns++; //counter for turns

        if (turns>40) { //if turns>40, game will end.
           break;
       }


        if (gamePlayer==0) {  //Player zero's turn

           diceResult=rollDie(); //value of die 
           drawDie(diceResult); //drawing the die

           currentTotal=diceResult; //the current roll score is the result of dice roll
           
           turnStatus(diceResult,gamePlayer,currentTotal,playerZeroScore,playerOneScore,&gamePlayer); //updates player's turn
           gameStatus(gamePlayer,playerZeroScore,playerOneScore); //check to see if either player won game, notifies whose turn it is

           printf("What do you want to do: (1)hold or (2) roll.\n"); //asks player if they want to roll or hold die
           scanf("%d",&hold);

           if (hold==1) { 
               playerZeroScore=playerZeroScore+currentTotal; 
               //adding roll score to the player's score at the end of their turn
               currentTotal=0; //resets current roll score to zero for the next player
               gamePlayer=1; //player one's turn after this round

               printf("You held, you have %d points.\n",playerZeroScore);
           }
           else {
               playerZeroScore=playerZeroScore+currentTotal;
           }
       }
    
           
        if (gamePlayer==1) { //Player zero's turn

            diceResult=rollDie(); //value of die 
            drawDie(diceResult); //drawing the die

            currentTotal=diceResult; //the current roll score is the result of dice roll

            turnStatus(diceResult,gamePlayer,currentTotal,playerZeroScore,playerOneScore,&gamePlayer);   //updates player's turn         
            gameStatus(gamePlayer,playerZeroScore,playerOneScore); //check to see if either player won game, notifies whose turn it is

            
            printf("What do you want to do: (1)hold or (2) roll.\n"); //asks player if they want to roll or hold die
            scanf("%d",&hold);

            if (hold==1) {
                playerOneScore=playerOneScore+currentTotal; //adding roll score to the player's score at the end of their turn
                currentTotal=0; //resets current roll score to zero for the next player
                gamePlayer=0; //player zero's turn after this round
                printf("You holded, you have %d points.\n",playerOneScore);
            }
            else {
                playerOneScore=playerOneScore+currentTotal;
            }

            
        }

        if (playerOneScore > MAX_POINTS || playerOneScore > MAX_POINTS) { //after the end of a round, exits game if either player has more than 100 points
            break;
        }
       
    }

    gameStatus(gamePlayer,playerZeroScore,playerOneScore); //updates the status of the game

            return 0;
    }




