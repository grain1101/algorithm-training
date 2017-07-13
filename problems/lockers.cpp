#include "leetcode.h"
/*
Given a number n that represents n lockers and n students.
All lockers start closed.
First student goes and opens all the lockers.
Second goes and toggles 2nd, 4th, 6th.. lockers.
Third student toggles  3rd, 6th, 9th.. lockers.
...
Print the lockers that remain open after all students pass.

https://www.careercup.com/question?id=6263110739427328
*/


class Solution {
public:
    int lockers(int n){
        vector<bool> locks(n, true);
        for(int i = 1; i <= sqrt(n); i++) cout << i * i << " ";
        cout << endl;
    }
};

int main() {
    Solution s1;
    int n = 100;
    cout << s1.lockers(n) << endl;
}
