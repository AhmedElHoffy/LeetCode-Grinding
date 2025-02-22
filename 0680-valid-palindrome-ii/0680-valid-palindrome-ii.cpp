class Solution {
private:
    bool Is_Palindrome(string SubStr, int LefIdx, int RightIdx){
        int n_Sub = SubStr.length();
        int L=LefIdx,R=RightIdx;
        while(L<R){
            if(SubStr[L]!=SubStr[R]){
                return false;
            }
            L++;
            R--;
        }
        return true;
    }

public:
    bool validPalindrome(string Str) {
        int n = Str.length();
        int Left_Idx = 0,  Right_Idx = n-1;

        while(Left_Idx < Right_Idx){
            if(Str[Left_Idx] != Str[Right_Idx]){
                return (Is_Palindrome(Str,Left_Idx+1,Right_Idx) ||  Is_Palindrome(Str,Left_Idx,Right_Idx-1));
            }
            Left_Idx++;
            Right_Idx--;
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