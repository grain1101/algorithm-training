#include "C:\Users\grain\Desktop\gitrepo\Test\leetcode.h"
/*****
Palindrome Problem: Given a string s
    1. check a string is palindrome

    // 2 substring
    2.1 find the longest palindrome substring of s                  -- O(n**2)
    2.2 return all the palindrome substring of s                    -- O(n**2)
    2.3 find the longest palindrome substring of s use Manacher     -- O(n)

    // 3 subsequence
    3.1 the longest palindrome subsequence of s                     -- O(n**2)
    3.2 return all palindrome subsequence of s                      -- O(2**n)
    3.3 return all palindrome subsequence of s                      -- O(n**3) or O(|R[0..n]| * |R1|) 

    // 4 permutation
    4.1 determine if a permutation of the string s could form a palindrome.
    4.2 return all the palindromic permutations (without duplicates) of it.
    4.3 next permutation                                            -- O(n)

    // 5 partition
    5.1 partition s such that every substring of the partition is a palindrome, Return all possible palindrome partitioning of s.
    5.2 partition s such that every substring of the partition is a palindrome, Return the minimum cuts needed for a palindrome partitioning of s.

****/
class Palindrome {
    // 1 check palindrome
    bool isPalindrome(string& s) {
        string tmp = s; reverse(tmp.begin(), tmp.end());
        return s == tmp;
    }
    // 2.1 find the longest palindrome SubString of s   -- O(n**2)
    string longestPalindromeSubstring(string& s) {
        string ret = "";
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
            for(int j = 0; j < i; j++) {
                if (j + 1 == i) dp[j][i] = s[j] == s[i];
                if (j + 1 < i) dp[j][i] = (s[i] == s[j]) && dp[j + 1][i - 1];
                if (dp[j][i]) {
                    if (ret.size() < i - j + 1) ret = s.substr(j, i - j + 1);
                }
            }
        }
        return ret;
    }
    // 2.2 return all the palindrome substring of s
    set<string> allPalindromeSubstring(string& s) {
        set<string> ret;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
            for(int j = 0; j < i; j++){
                if (j + 1 == i) dp[j][i] = s[j] == s[i];
                if (j + 1 < i) dp[j][i] = (s[i] == s[j]) && dp[j + 1][i - 1];
                if (dp[j][i]) {
                    ret.insert(s.substr(j, i - j + 1));
                }
            }
        }
        return ret;
    }
    // 2.3 find the longest palindrome substring of s use Manacher     -- O(n)
    string longestPalindromeSubstringManacher(string& s) {
        string t = "$#";
        for(auto c : s) t += c + "#";
        vector<int> p(t.size(), 0);
        int idx = 0, mx = 0;
        int retIdx = 0, retMx = 0;
        for(int i = 0; i < p.size(); i++) {
            p[i] = (mx > i)? min(p[2 * idx - 1], mx - i) : 1;
            while(t[i + p[i]] == t[i - p[i]]) p[i]++;
            if (mx < i + p[i]) {
                mx = i + p[i];
                idx = i;
            }
            if (retMx < p[i]) {
                retMx = p[i];
                retIdx = i;
            }
        }
        return s.substr((retIdx - retMx) / 2, retMx - 1);
    }
    // 3.1. the longest palindrome subsequence of s
    int longestPalindromeSubsequence(string& s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = s.size() - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i + 1; j < s.size(); j++){
                if (s[i]==s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][s.size() - 1];
    }
    // 3.2 return all the palindrome subsequence of s
    // NP-Complete O(2**n)
    set<string> allPalindromeSubsequence_1(string& s) {
        set<string> ret;
        findAllPalindromeSubSequence(ret, s, "", 0);
        return ret;
    }
    // 3.3 return all the palindrome subsequence of s
    // O(|R| * |R1|)  or O(n**3)
    struct Info{
        string str;
        PII p;
        Info(string _str, PII _p) : str(_str), p(_p) {};
    };
    set<string> allPalindromeSubsequence_2(string& s){
        // O(|R| * |R1|)
        // r[i] store length = i + 1 's palindrome subsequence. r[0] = {"a","b"...}, r[1] = {"aa", "bb"};
        set<string> ret;
        if (s.size() == 1) {ret.insert(s); return ret;}
        vector<vector<Info>> r(s.size());
        int n = s.size();
        for(int i = 0; i < n; i++) {
            r[0].push_back(Info(string(1, s[i]), PII({i,i})));
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if (s[i] == s[j]){
                    r[1].push_back(Info(string(2, s[i]), PII({i, j})));
                }
            }
        }
        // loop
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < r[i].size(); j++) {
                for(int k = 0; k < r[1].size(); k++) {
                    if (rangeInclude(r[1][k], r[i][j])) {
                        // "a****b**a" || "**a*bbabb**a"
                        Info outer = r[1][k];
                        string str = string(1, outer.str[0]) + r[i][j].str + string(1, outer.str[1]);
                        r[2 + i].push_back(Info(str, outer.p));
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(auto e : r[i]) {
                ret.insert(e.str);
            }
        }
        return ret;
    }
    /**range a is include b [a.first < [b.first, b.second] < a.second]*/
    bool rangeInclude(const Info& a, const Info& b) {
        return a.p.first < b.p.first && b.p.second < a.p.second;
    }

    // 4.1 determine if a permutation of the string s could form a palindrome.
    bool canPermutePalindrome(string s) {
        // 266_PalindromePermutation hash map
        set<char> t;
        for(auto c : s){
            if (t.find(c) == t.end()) t.insert(c);
            else t.erase(c);
        }
        return t.size() <= 1;
    }

    // 4.2 return all the palindromic permutations (without duplicates) of it.
    // Return an empty list if no palindromic permutation could be form.
    // Given s = "aabb", return ["abba", "baab"].
    // Given s = "abc",  return [].
    vector<string> generatePalindromes(string s) {
        // 267_Palindrome Permutation II
        vector<string> ret;
        unordered_map<char, int> m;
        string left = "", mid = "";
        for(auto c : s) m[c]++;
        for(auto it : m){
            if (it.second % 2){
                if (mid!="") return ret;
                mid = it.first;
            }
            left.append(it.second / 2, it.first);
        }
        sort(left.begin(), left.end());
        do{
            ret.push_back(left + mid + string(left.rbegin(), left.rend()));
        }while(nextPermutation(left));
        return ret;
    }
    // 4.3 next permutation
     bool nextPermutation(string& s) {
        int i = s.size() - 1;
        for(; i >=0; i--) {
            if(i + 1 < s.size() && s[i] < s[i + 1]) {
                int j = s.size() - 1;
                for(; j > i; j--) {
                    if (s[j] > s[i]) break;
                }
                swap(s[i], s[j]);
                reverse(s.begin() + i + 1, s.end());
                return true;
            }
        }
        if (i == -1) return false;
     }
    // 5.1 partition s such that every substring of the partition is a palindrome, Return all possible palindrome partitioning of s.
    // s = "aab" -> [["aa","b"], ["a","a","b"]]     // 131. Palindrome Partitioning
    vector<vector<string>> allPalindromePatition(string s) {
        vector<vector<string>> ret;
        vector<string> path;
        dfsPalindromePatition(ret, path, s, 0);
        return ret;
    }

    // 5.2 partition s such that every substring of the partition is a palindrome, Return the minimum cuts needed for a palindrome partitioning of s.
    // s = "aab" -> ["aa","b"] -> 1             // 132. Palindrome Partitioning II
    int minCutPalindromePatition(string s) {
        int n = s.size();
        vector<int> dp(n + 1, s.size());
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            // center i;
            int l = 0;
            while(i - l >= 0 && i + l < n && s[i - l] == s[i + l]){
                dp[i + l + 1] = min(dp[i + l + 1], dp[i - l] + 1);
                l++;
            }
            // center i, i + 1;
            l = 0;
            while(i - l >= 0 && i + 1 + l < n && s[i - l] == s[i + 1 + l]){
                dp[i + 1 + l + 1] = min(dp[i + 1 + l + 1], dp[i - l] + 1);
                l++;
            }
        }
        return dp[n] - 1;
    }
private:
    void findAllPalindromeSubSequence(set<string>& ret, string& s, string str, int idx) {
        if (idx == s.size()) { ret.insert(str); return;}
        findAllPalindromeSubSequence(ret, s, str, idx + 1);
        findAllPalindromeSubSequence(ret, s, str + s[idx], idx + 1);
    }
    void dfsPalindromePatition(vector<vector<string>>& ret, vector<string>& path, string& s, int idx) {
        if (idx == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = idx; i < s.size(); i++) {
            string subStr = s.substr(idx, i - idx + 1);
            if (isPalindrome(subStr)) {
                path.push_back(subStr);
                dfsPalindromePatition(ret, path, s, i + 1);
                path.pop_back();
            }
        }
    }
};

int main() {
    Palindrome pf;
    vector<string> vs = {"a", "aa", "ab", "", "ababa", "babababababababbabab", "edfabbddfas555"};

    string s = "abba";
    for(auto s : vs) {
        showL("================================");
        showL(s);
        clock_t begin1 = clock();
        auto ans1 = pf.allPalindromeSubsequence_1(s);
        showL("1: ", 1.0 * (clock() - begin1) / CLOCKS_PER_SEC);
        showV(ans1);
        clock_t begin2 = clock();
        auto ans2 = pf.allPalindromeSubsequence_2(s);
        showL("2: ", 1.0 * (clock() - begin2) / CLOCKS_PER_SEC);
        showV(ans2);
        assert(ans1==ans2);
    }

}
