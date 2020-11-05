/** pex1functs.c
* ===========================================================
* Name: Cleo Cowie
* Section: T1/2
* Project: PEX2
* Purpose: Selection Statements, Iterations, Function Calls
* ===========================================================
*/

#include "pex1functs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*** @fn void drawDie(int pips)
*    @brief This function draws a single die with the correct number of pips.
*    @param pips -number of pips to draw on the die
*    @return No return value.
*/

void drawDie(int pips) {

    switch (pips) {
        case 1:
            printf(" ------- \n|       |\n|   *   |\n|       |\n ------- \n");
            break;

        case 2:
            printf(" ------- \n| *     |\n|       |\n|     * |\n ------- \n");
            break;

        case 3:
            printf(" ------- \n| *     |\n|   *   |\n|     * |\n ------- \n");
            break;

        case 4:
            printf(" ------- \n| *   * |\n|       |\n| *   * |\n ------- \n");
            break;

        case 5:
            printf(" ------- \n| *   * |\n|   *   |\n| *   * |\n ------- \n");
            break;

        case 6:
            printf(" ------- \n| *   * |\n| *   * |\n| *   * |\n ------- \n");
            break;

    }
} 

/*** @fn int rollDie()
 * @brief This function rolls the die for the current player by using the rand() function to randomly select the number rolled.No parameters.
 * @return an integer, which is the die rolled. 
 */

int rollDie(void) {
    return ((rand() % 6 +1)); //produces random number for die result
} 

/*** @fn void turnStatus(int die,int player,int currentTotal, int score0, int score1,int* playerGame)
*    @brief This function provides an update on the player's turn by printing a message to the console. The message either notifies the player that they have Pigged Out (rolled a 1),or it updates the player on their current turn total. 
*    @param die-what number the die landed on
*    @param player-indicates which player is playing
*    @param currentTotal-current roll total of turn
*    @param score0-player zero score
*    @param score1-player one score
*    @param playerGame-pointer that will indicate to the program when to switch players. 
*    @return No return value.
*/ 

void turnStatus (int die,int player, int currentTotal, int score0, int score1, int* playerGame) {
    
    int TotalScore; //total score of roll(s)

    switch (player) { //switch statement to see who is player and what to do with their roll scores

        case 0:
            if (die==1) { //player pigs out if they roll a one
                printf("Player %d pigged out.\n", player);
                *playerGame = 1; //switch player
                
            }

            else { //player keeps going
                
                printf("Current score for player %d = %d.\n",player,currentTotal);
                TotalScore=score0+currentTotal; //total roll score updates as they keep rolling
                printf("Total score = %d.\n",TotalScore);

            }
            break;

        case 1:
            if (die==1) { //player pigs out if they roll a one
                printf("Player %d pigged out.\n",player);
                *playerGame = 0; //switch player
            
                
            }
            else {
            
                printf("Current score for player %d = %d.\n",player,currentTotal);
                TotalScore=score1+currentTotal; //total roll score updates as they keep rolling
                printf("Total score = %d.\n",TotalScore);
            }

            break;
    }
        return;
} 

/*** @fn void gameStatus(int player,int score0,int score1)
 * @brief This function provides an update on the status of the game at the conclusion of a player's turn,band either notifies the players whose turn it is, or provides a message stating who won the game.
 * @param player-indicates which player is playing
 * @param score0-player zero score
 * @param score1-player one score
 * @return No return value.
 */

void gameStatus(int player, int score0,int score1) { 


    printf("Player 0 score: %d\n",score0);
    printf("Player 1 score: %d\n",score1);

    if (player==0) {
        if (score0<100) {
            printf("It is Player 0 turn.\n");
        }
        else {
            printf("Player %d won! Score: %d\n",player, score0);
        }
    }

    else   {

        if (score1<100) {
            printf("It is Player 1 turn.\n");
        }

        else {
            printf("Player %d won! Score: %d\n.",player, score1);
        }
    }
        
} 

/*** @fn int totalScore(int score,int turnTotal)
 * @brief This function calculates a player's total score at the conclusions of their turn. 
 * @param score-current roll score
 * @param totalScore-player's total game score
 * @return Returns an integer value, then updates total game score. 
 */

int totalScore(int score, int turnTotal) {

    score=score+turnTotal; //total game score plus current roll score

    return score;

}