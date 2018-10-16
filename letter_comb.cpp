//
// Created by 苗沐之 on 2018/10/16.
//

#include "solutions.h"

using namespace std;

vector<string> table({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});


vector<string> letterCombinations(string digits){
    if (digits.empty()){
        return *new vector<string>;
    }

    string prefixes = table[digits[0]-'0'];

    if (digits.size() == 1){
        vector<string> strings;
        for (auto it=prefixes.begin(); it<prefixes.end(); it++){
            strings.emplace_back(1, *it);
        }
        return strings;
    } else {
        vector<string> rests = letterCombinations(digits.substr(1));
        vector<string> results;
        for (auto i=prefixes.begin(); i<prefixes.end(); i++){
            for (auto j=rests.begin(); j<rests.end(); j++){
                results.push_back(string(1, *i) + *j);
            }
        }
        return results;
    }
}

