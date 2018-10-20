//
// Created by 苗沐之 on 2018/10/20.
//

#include "solutions.h"
using namespace std;

int find_min(const vector<ListNode*>& lists){
    if (lists.empty()){
        return -1;
    }

    int min_index = 0;
    int min_val = lists[0]->val;
    for (int i=1; i<lists.size(); i++){
        if (lists[i]->val < min_val){
            min_val = lists[i]->val;
            min_index = i;
        }
    }
    return min_index;
}

ListNode* mergeKLists(vector<ListNode*>& lists){
    for (auto it=lists.begin(); it<lists.end();){//stupid pre-processing for null nodes
        if (*it == nullptr){
            lists.erase(it);
        } else {
            it++;
        }
    }

    ListNode* header = nullptr;
    ListNode* end = nullptr;

    while (!lists.empty()){
        int min_index = find_min(lists);

        if (header == nullptr){//generate new
            header = lists[min_index];
            end = lists[min_index];
        } else {
            end->next = lists[min_index];
            end = end->next;
        }

        lists[min_index] = lists[min_index]->next;
        if (lists[min_index] == nullptr){
            lists.erase(lists.begin()+min_index);
        }
    }

    return header;
}