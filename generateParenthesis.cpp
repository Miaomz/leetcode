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

vector<string> generateParenthesis(int n){
    vector<string> res(1, "(");

    for (int i=2*n-1; i>0; i--){
        vector<string> temp;
        for(const string& resStr: res){
            if (isValid(resStr, i)){
                temp.push_back(resStr + '(');
                temp.push_back(resStr + ')');
            }
        }
        res = temp;
    }

    vector<string> result;
    for (auto& s: res){
        if (isValid(s, 0)){
            result.push_back(s);
        }
    }
    return result;
}
