#include <vector>
#include <iostream>
#include <string>

using namespace std;
// 1.Preprocess  noon -> $#n#o#o#n#
//   做法是在每一个字符的左右都加上一个特殊字符，比如加上'#
//   这样做的好处是不论原字符串是奇数还是偶数个，处理之后得到的字符串的个数都是奇数个，这样就不用分情况讨论了
//   为了防止越界，我们还需要在首尾再加上非#号字符
// 2. p[i]表示以t[i]字符为中心的回文子串的半径，若p[i] = 1，则该回文子串就是t[i]本身
//    id为最大回文子串中心的位置，mx是回文串能延伸到的最右端的位置
//    p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
string Manacher(string s) {
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
}

int main() {
    string s1 = "12212";
    cout << Manacher(s1) << endl;
    string s2 = "122122";
    cout << Manacher(s2) << endl;
    string s = "waabwswfd";
    cout << Manacher(s) << endl;
}
