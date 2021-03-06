#include <cstring>
#include <iostream>
#include <limits.h>

#include "dynprog.h"

using namespace std;


/*
 * Bottom up implementation of Smith-Waterman algorithm
 */
void SW_bottomUp(char* X, char* Y, char** P, int** H, int n, int m){
    
    //set first col to 0
    for (int row = 0; row <= n; row++) {
        //set first row to 0
        for (int col = 0; col <= m; col++) {
            H[row][col] = 0;
            P[row][col] = '_';
        }
    }

    //nested for loops to go through all items in the table EXCEP first row of 0
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
        int score1, score2, score3;
        //table is offset by 1 due to 0 values
            if (Y[col - 1] == X[row - 1]) {
                score1 = H[row - 1][col - 1] + 2;
            } else {
                score1 = H[row - 1][col - 1] - 1;
            }
            score2 = H[row - 1][col] - 1;
            score3 = H[row][col - 1] - 1;
        //find the max out of the 3 scores calculated
            H[row][col] = std::max( { score1, score2, score3 });

        //use the scores above to change the P tables
            if (H[row][col] == score1) {
                //use the top left diagonal so row-1 and col-1
                P[row][col] = 'd';
            } else {
                //if you picked score2 use the block above this block in the P table
                if (H[row][col] == score2) {
                    P[row][col] = 'u';
                } else {
                    //if you picked score3 use the block to the left of this block in the P table
                    P[row][col] = 'l';
            }
        }
       
    }
 
}
    //return;
}

/*
 * Top-down with memoization implementation of Smith-Waterman algorithm
 */
void memoized_SW(char* X, char* Y, char** P, int** H, int n, int m){
    //set first col to 0
        for (int row = 0; row <= n; row++) {
            //set first row to 0
            for (int col = 0; col <= m; col++) {
                H[row][col] = 0;
                P[row][col] = '_';
            }
        }

     
        memoized_SW_AUX(X, Y, P, H, n, m);
}


/*
 * Auxilary recursive function of top-down with memoization implementation of Smith-Waterman algorithm
 */
void memoized_SW_AUX(char* X, char* Y, char** P, int** H, int n, int m){
    //stores the subproblem to the solution
    int score1, score2, score3;
    //is remembering what we have computed previously
    //add code for the first row and columns to be zero
    if (n ==0 || m==0){
        H[n][m] = 0;
        return;
    }
    if (H[n - 1][m - 1] == 0) {
        memoized_SW_AUX(X, Y, P, H, n - 1, m - 1);
    }
    if (H[n - 1][m] == 0) {
        memoized_SW_AUX(X, Y, P, H, n - 1, m);
    }
    if (H[n][m - 1] == 0) {
        memoized_SW_AUX(X, Y, P, H, n, m - 1);
    }
    //if statement to check if calculated value exist
    if (Y[m - 1] == X[n - 1]) {
        score1 = H[n - 1][m - 1] + 2;
    } else {
        score1 = H[n - 1][m - 1] - 1;
    }
    score2 = H[n - 1][m] - 1;
    score3 = H[n][m - 1] - 1;

    H[n][m] = std::max( { score1, score2, score3 });
    
    //add values to P
    
        //use the top left diagonal so row-1 and col-1
    if (H[n][m] == score1) {
        P[n][m] = 'd';
    } else {
        //if you picked score2 use the block above this block in the P table
        if (H[n][m] == score2) {
            P[n][m] = 'u';
        } else {
  
            P[n][m] = 'l';
}
    }
}

/*
 * Print X'
 */
void print_Seq_Align_X(char* X, char** P, int n, int m){
	
    
    if (n <= 0 || m <= 0) {
        return;
    }
    else{
    if (P[n][m] == 'd') {
        print_Seq_Align_X(X, P, n - 1, m - 1);
        cout << X[n - 1];
    } else {
        //compare with left neighbor
        if (P[n][m] == 'l') {
            print_Seq_Align_X(X, P, n, m - 1);
            cout << "-";
        } else {
            print_Seq_Align_X(X, P, n - 1, m);
            cout << X[n - 1];
        }
    }
}
}
/*
 * Print Y'
 */
    void print_Seq_Align_Y(char *Y, char **P, int n, int m) {

        if (n <= 0 || m <= 0) {
            return;
        }
        else {
        if (P[n][m] == 'd') {
            print_Seq_Align_Y(Y, P, n - 1, m - 1);
            cout << Y[m-1];
        } else {
            //compare with left neighbor
            if (P[n][m] == 'l') {
                print_Seq_Align_Y(Y, P, n, m - 1);
                cout << Y[m-1];
            } else {
                print_Seq_Align_Y(Y, P, n - 1, m);
                cout << "-";
            }
        }
    }
    }
