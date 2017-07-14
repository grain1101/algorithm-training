#include "leetcode.h"
/*
How to randomly select a number in an array?
array: [15, 2, 4, 5, 1, -2, 0]

Follow-up:
Given a second array freq where freq[i] represents the occurrence of the ith number in array, how to randomly select a number in array based on the frequency.

Extra requirement:
Could you complete the selection in a single-pass(go through each array only once)?</p>

https://www.careercup.com/question?id=5767234518515712

Same as: randomly select a linked list node based on then weights.
http://www.geeksforgeeks.org/select-a-random-node-from-a-singly-linked-list/

Reservoir Sample
Leetcode: 382_Linked List Random Node, 384_Shuffle an Array, 398_Random Pick Index
*/


class Solution {
public:
    int pickRandom(vector<int>& num, vector<int>& freq){
        srand(time(nullptr));
        int sumOccur = accumulate(freq.begin(), freq.end(), 0);
        int randIdx = rand() % sumOccur;
        for(int i = 0; i < freq.size(); i++){
            if (randIdx < freq[i]) return num[i];
            randIdx -= freq[i];
        }
    }
    vector<ListNode*> pickRandom(ListNode* head, int k){
        vector<ListNode*> ret(k);
        ListNode* p = head;
        int i = 0;
        for(i = 0; i < k && p; i++){
            ret[i] = p;
            p = p->next;
        }
        while(p){
            i++;
            int j = rand() % i;
            if (j < k) ret[j] = p;
            p = p->next;
        }
        return ret;
    }
};

int main() {
    Solution s1;
    int n = 5;
    vector<int> nums(n);
    vector<int> freq(n);
    for(int i = 0; i < n; i++){
        nums[i] = i;
        freq[i] = rand()% n;
    }
    showV(nums);
    showV(freq);
    cout << s1.pickRandom(nums, freq) << endl;
}
