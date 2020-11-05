/** pex1functs.h
* ===========================================================
* Name: Cleo Cowie
* Section: T1/2
* Project: PEX2
* Purpose: Selection Statements, Iterations, Function Calls
* ===========================================================
*/

#ifndef PEX1FUNCTS_H
#define PEX1FUNCTS_H



/*** @fn void drawDie(int pips)
*    @brief This function draws a single die with the correct number of pips.
*    @param pips -number of pips to draw on the die
*    @return No return value.
*/ 

    void drawDie(int pips); 
    

/*** @fn int rollDie()
 * @brief This function rolls the die for the current player by using the rand() function to randomly select the number rolled.No parameters.
 * @return an integer, which is the die rolled. 
 */
 
    int rollDie(); 


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

    void turnStatus(int die,int player,int currentTotal, int score0, int score1,int* playerGame);


/*** @fn void gameStatus(int player,int score0,int score1)
 * @brief This function provides an update on the status of the game at the conclusion of a player's turn,band either notifies the players whose turn it is, or provides a message stating who won the game.
 * @param player-indicates which player is playing
 * @param score0-player zero score
 * @param score1-player one score
 * @return No return value.
 */

    void gameStatus(int player,int score0,int score1);


/*** @fn int totalScore(int score,int turnTotal)
 * @brief This function calculates a player's total score at the conclusions of their turn. 
 * @param score-current roll score
 * @param totalScore-player's total game score
 * @return Returns an integer value, then updates total game score. 
 */

    int totalScore(int score, int turnTotal);


#endif //PEX1FUNCTS_H




