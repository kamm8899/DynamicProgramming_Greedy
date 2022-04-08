#include <cstring>
#include <iostream>
#include <limits.h>

#include "dynprog.h"

using namespace std;


/*
 * Bottom up implementation of Smith-Waterman algorithm
 */
void SW_bottomUp(char* X, char* Y, char** P, int** H, int row, int col, int n, int m){
    
    //recursion
    if( col > m){
        //row starts from col 0
        SW_bottomUp(X, Y, P, H, row+1, 1, n, m);
        return;
    }
    else if(row > n){
        //once you get to the last row you're done
        return;
    }
    int score1, score2, score3;
    //check if the letters of strings are equal
    if(X[row -1] == Y[col-1]){
        score1 = H[row -1][col -1 ] +2;
    }
    else{
        score1 = H[row -1 ][col -1]-1;
    }
    score2= H[row -1 ][col] -1;
    score3= H[row][col-1]-1;
    
    //score comparison
    if(score1 >= score2 && score1 >= score3){
        H[row][col] = score1;
    }
    else if(score2 >= score1 && score2 >= score3){
        H[row][col] = score2;
    }
    else if(score3>= score1 && score3 >= score2){
        H[row][col]= score3;
    }
    //change scores from the above code to change the P tables
    if(H[row][col] == score1){
        //top left diagonal row-1 and col-1
        P[row][col] = P[row-1][col-1];
    }
    else{
        if(H[row][col]==score2){
            P[row][col] = P[row-1][col];
        }
        else{
            P[row][col] = P[row -1][col];
        }
    }
    //call recursive call again
    SW_bottomUp(X, Y, P, H, row, col+1, n, m);
}

/*
 * Top-down with memoization implementation of Smith-Waterman algorithm
 */
void memoized_SW(char* X, char* Y, char** P, int** H, int n, int m){
	
}

/*
 * Auxilary recursive function of top-down with memoization implementation of Smith-Waterman algorithm
 */
void memoized_SW_AUX(char* X, char* Y, char** P, int** H, int n, int m){
	
}

/*
 * Print X'
 */
void print_Seq_Align_X(char* X, char** P, int n, int m){
	
}

/*
 * Print Y'
 */
void print_Seq_Align_Y(char* Y, char** P, int n, int m){
	
}


//not completly sure how you know which numeric value is what letter
//how do I know what you want us to put in for n and m
//What do I do for the report, what cases do I use and how many
//Where does the recursion go for the algorithm
//M where are the slides refering too
//what happens with the character the array

