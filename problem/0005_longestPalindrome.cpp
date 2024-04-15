/*
5. 最长回文子串
中等
相关标签
相关企业
提示
给你一个字符串 s，找到 s 中最长的回文子串。
如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"

提示：
1 <= s.length <= 1000
s 仅由数字和英文字母组成
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //检查字符串长度是否小于等于1，如果是，直接返回输入字符串，因为长度为1的字符串本身就是回文串
        if (s.length() <= 1) {
            return s;
        }
        int n = s.length();
        // 初始化最长回文子串的起始位置和结束位置
        int start = 0; int end = 0;
        // 遍历输入字符串中的每个字符，以每个字符为中心，分别向两边扩展来寻找回文串
        for (int i = 0; i < n; i++) {
            // 情况1： 以当前字符为中心，向两边扩展直到不满足回文串的条件为止
            int left1 = i, right1 = i;
            while (left1 >= 0 && right1 < n && s[left1] == s[right1]) {
                left1--;
                right1++;
            }
            // 情况2： 以当前字符和下一个字符之间的间隔昨作为中心，向两边扩展直到不满足回文串的条件为止
            int left2 = i, right2 = i + 1;
            while (left2 >= 0 && right2 < n && s[left2] == s[right2]) {
                left2--;
                right2++;
            }
            // 更新最长回文子串的起始位置和结束位置
            /*
            这段代码是用来更新最长回文子串的起始位置和结束位置的。我来解释一下：
            首先，left1 和 right1 分别是情况1下回文串的左边界和右边界，left2 和 right2 分别是情况2下回文串的左边界和右边界。
            对于情况1，我们比较 right1 - left1 - 1 和当前最长回文子串的长度（end - start）。
            如果当前回文串的长度大于最长回文子串的长度，说明找到了更长的回文子串，我们就更新 start 和 end 为当前回文串的左右边界。
            对于情况2，同样进行比较，如果当前回文串的长度大于最长回文子串的长度，也更新 start 和 end。
            但请注意，情况1和情况2分别代表不同的中心情况，因此它们找到的回文串可能不同。
            如果情况2找到的回文串更长，则它会覆盖情况1找到的回文串，反之亦然。
            这样设计的原因是，我们需要考虑到字符串可能有奇数长度和偶数长度的回文串。
            比如字符串 "abba"，它既是以 "b" 为中心的奇数长度回文串，也是以两个 "b" 之间的间隙为中心的偶数长度回文串。
            因此，我们需要分别考虑这两种情况，并在比较的过程中选择更长的回文串作为最终结果。
            */
            if (right1 - left1 - 1 > end - start) {
                start = left1 + 1;
                end = right1 - 1; 
            }
            if (right2 - left2 - 1 > end - start) {
                start = left2 + 1;
                end = right2 - 1;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution solution;
    string s1 = "babab";
    string s2 = "cbbd";
    string s3 = "a";
    string s4 = "ac";
    cout << solution.longestPalindrome(s1) << endl;
    cout << solution.longestPalindrome(s2) << endl;
    cout << solution.longestPalindrome(s3) << endl;
    cout << solution.longestPalindrome(s4) << endl;
}
