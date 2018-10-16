#include <iostream>
#include "solutions.h"

using namespace std;

int main() {
//    vector<vector<char>> board(9);
//    for (int i = 0; i < 9; ++i) {
//        board[i] = *new vector<char>(9, '.');
//    }
//    board[0][0] = '8';
//    board[0][1] = '2';
//    board[2][2] = '1';
//    cout << isValid(board);
//
//    vector<int> v;
//    v.push_back(-1);
//    v.push_back(0);
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(-1);
//    v.push_back(-4);
//
//    vector<vector<int>> triplets = threeSum(v);
//    for (auto it=triplets.begin(); it<triplets.end(); it++){
//        for (auto innerIt=it->begin(); innerIt<it->end(); innerIt++){
//            cout << *innerIt << ' ';
//        }
//        cout << endl;
//    }
    vector<int> nums({1,2,5,10,11});
    cout << threeSumClosest(nums, 12);
}