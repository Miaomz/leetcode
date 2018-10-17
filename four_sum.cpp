//
// Created by 苗沐之 on 2018/10/17.
//
# include "solutions.h"

using namespace std;


vector<vector<int>> findTwoValue(const vector<int>& nums, int low, int high, const int targetSum){
    vector<vector<int>> twoValues;
    while (low < high){
        int tempSum = nums[low] + nums[high];
        if (tempSum == targetSum){
            vector<int> v({nums[low], nums[high]});
            twoValues.push_back(v);
        }

        if (tempSum < targetSum){
            do {
                low ++;
            } while (nums[low-1] == nums[low]);
        } else {//including the situation that two value equal
            do {
                high--;
            } while (nums[high+1] == nums[high]);
        }
    }
    return twoValues;
}

vector<vector<int>> fourSum(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    for (int i=0; i<nums.size()-3; i++){
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        for (int j=i+1; j<nums.size()-2; j++){
            if (j-i>1 && nums[j] == nums[j-1]){
                continue;
            }

            auto twoValues = findTwoValue(nums, j + 1, (int) nums.size() - 1, target - nums[i] - nums[j]);
            for (auto twoValue: twoValues){
                twoValue.insert(twoValue.begin(), nums[j]);
                twoValue.insert(twoValue.begin(), nums[i]);
                result.push_back(twoValue);
            }
        }
    }
    return result;
}
