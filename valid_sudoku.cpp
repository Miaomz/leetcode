//
// Created by 苗沐之 on 2018/10/14.
//

#include "solutions.h"
using namespace std;

inline int parseChar(char digit){
    return digit == '.' ? -1 : digit - '0';
}

bool isPartlyValid(vector<int>& line){
    int bitmap = 0;
    for(auto it = line.begin(); it != line.end(); it++){
        if (*it < 1 || *it > 9){
            continue;
        }

        if ((bitmap & (1 << *it)) != 0){
            return false;
        } else {
            bitmap = bitmap | (1 << *it);
        }
    }
    return true;
}

bool isValid(vector<vector<char>>& board){
    for (int i=0; i<9; i++){
        vector<int> row(9), column(9), subBox(9);
        for (int j = 0; j < 9; ++j) {
            row[j] = parseChar(board[i][j]);
            column[j] = parseChar(board[j][i]);
            subBox[j] = parseChar(board[(i%3)*3 + j%3][(i/3)*3 + j/3]);
        }
        if (!(isPartlyValid(row)&&isPartlyValid(column)&&isPartlyValid(subBox))){
            return false;
        }
    }
    return true;
}
