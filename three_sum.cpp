//
// Created by 苗沐之 on 2018/10/14.
//

#include <iostream>
#include "solutions.h"
using namespace std;

struct Triplet{
    int firstAnchor, secondAnchor, selected;

    Triplet(int firstAnchor, int secondAnchor, int selected){
        this->firstAnchor = firstAnchor;
        this->secondAnchor = secondAnchor;
        this->selected = selected;
    }

    bool operator==(const Triplet& another) const {
        return firstAnchor==another.firstAnchor && secondAnchor==another.secondAnchor && selected==another.selected;
    }

    bool operator!=(const Triplet& another) const {
        return firstAnchor!=another.firstAnchor || secondAnchor!=another.secondAnchor || selected!=another.selected;
    }

    bool operator<(const Triplet& another) const {
        return firstAnchor < another.firstAnchor
               || firstAnchor == another.firstAnchor && secondAnchor < another.secondAnchor
               || firstAnchor == another.firstAnchor && secondAnchor == another.secondAnchor && selected < another.selected;
    }

    vector<int> transform() const{
        vector<int> t = {firstAnchor, secondAnchor, selected};
        return t;
    }
};

vector<vector<int>> threeSum(vector<int>& nums){
    if (nums.size() < 3){
        return *new vector<vector<int>>;
    }
    sort(nums.begin(), nums.end());

    vector<Triplet> temp;
    for (int i = 0; i < nums.size()-2; ++i) {
        if (nums[i] > 0 || nums[i] + nums[nums.size()-1] + nums[nums.size()-2] < 0 || i>0&&nums[i-1]==nums[i]){
            //pay attention to "i>0&&nums[i-1]==nums[i]"
            continue;
        }

        for (int j = i+1; j < nums.size()-1; ++j) {
            int tar = 0-nums[i]-nums[j];
            if (binary_search(nums.begin()+j+1, nums.end(), tar)){
                Triplet t(nums[i], nums[j], tar);
                if (!binary_search(temp.begin(), temp.end(), t)){
                    temp.push_back(t);
                }
            }
        }
    }

    vector<vector<int>> result;
    for (auto it=temp.begin(); it<temp.end(); it++){
        result.push_back(it->transform());
    }
    return result;
}



