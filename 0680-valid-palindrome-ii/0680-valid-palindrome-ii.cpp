class Solution {
private:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Try removing one character from either side
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};


















/*
class Solution {
private: 
    bool IsSubPalindrome(const string&  Sub_Str, int Left, int Right){
        while(Left < Right){
            if(Sub_Str[Left]!=Sub_Str[Right]){
                return false;
            }
            Left++;
            Right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int Left = 0;
        int Right = n -1;

        while(Left < Right){
            if(s[Left]!= s[Right] ){
                return IsSubPalindrome(s,Left+1,Right) || IsSubPalindrome(s,Left,Right-1);
            }
            Left++;
            Right--;
        }
        return true;
    }
};
*/