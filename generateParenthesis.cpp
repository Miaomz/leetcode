//
// Created by 苗沐之 on 2018/10/18.
//
#include "solutions.h"
using namespace std;

bool isValid(const string& str, int remain){
    int counter = 0;
    for (auto ch: str){
        ch == '(' ? counter++ : counter--;
        if (counter < 0){
            return false;
        }
    }
    return counter <= remain && counter >= -remain;
}

vector<string> possiblePostfix(const string& prefix, int remain){
    if (!isValid(prefix, remain)){
        return vector<string>();
    }

    if (remain == 1){
        string unchecked;
        if (isValid(unchecked = prefix+')', 0)){
            return vector<string>(1, unchecked);
        } else {
            return vector<string>();
        }
    } else {
        vector<string> adder1 = possiblePostfix(prefix+'(', remain-1);
        vector<string> adder2 = possiblePostfix(prefix+')', remain-1);
        adder1.insert(adder1.end(), adder2.begin(), adder2.end());
        return adder1;
    }
}

vector<string> generateParenthesis(int n){
    return possiblePostfix("(", 2*n-1);
}
