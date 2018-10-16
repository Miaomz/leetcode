//
// Created by 苗沐之 on 2018/10/15.
//
#include "solutions.h"
using namespace std;

int getClosest(const vector<int>& nums, const int minus, int begin){
    int low = begin;
    int high = (int)nums.size()-1;
    while (low < high){
        int mid = (low+high)/2;
        if (nums[mid] == minus){
            return minus;
        } else if (nums[mid] < minus){
             if (mid+1 < nums.size() && minus-nums[mid]<=nums[mid+1]-minus){
                 return nums[mid];
             }
            low = mid+1;
        } else if (nums[mid] > minus){
             if (mid-1 >= begin && nums[mid]-minus<=minus-nums[mid-1]){
                 return nums[mid];
             }
            high = mid-1;
        }
    }

    int lastIndex = (low+high)/2;
    return lastIndex >= begin ? nums[lastIndex] : nums[begin];
}

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int temp = nums[0] + nums[1] + nums[2];
    for (int i=0; i<nums.size()-2; i++){
        for (int j=i+1; j<nums.size()-1; j++){
            int minus = target - nums[i] - nums[j];
            int closest = getClosest(nums, minus, j+1);
            if (abs(closest-minus) < abs(temp-target)){
                temp = closest + nums[i] + nums[j];
            }
        }
    }
    return temp;
}