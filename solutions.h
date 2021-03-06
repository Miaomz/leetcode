//
// Created by 苗沐之 on 2018/10/13.
//
#include <vector>
#include <iostream>


#ifndef LEETCODE_SOLUTIONS_H
#define LEETCODE_SOLUTIONS_H

bool isValid(std::vector<std::vector<char>>& board);

std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

int threeSumClosest(std::vector<int>& nums, int target);

std::vector<std::string> letterCombinations(std::string digits);

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);

std::vector<std::string> generateParenthesis(int n);

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists);

#endif //LEETCODE_SOLUTIONS_H
