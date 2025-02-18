class Solution {
public:
    bool isSubsequence(string s, string t) {

        int S_Size = s.size();
        int t_Size = t.size();
        int Last_Idx=-1;
        bool found = false;
        for(int i=0 ; i < S_Size ; i++ ){
            found= false;
            for(int j = 0 ; j < t_Size ; j++){
                if(s[i]==t[j] && Last_Idx < j){
                    found = true;
                    Last_Idx=j;
                    break;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;

    }
};




























/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int Size_Sub = s.size();
        int Size_Str = t.size();
        int Ptr_Sub =0;
        int Ptr_Str =0;
        if(Size_Sub == 0 && Size_Str == 0){
            return true;
        }
        while(Ptr_Str < Size_Str){
            if(s[Ptr_Sub] == t[Ptr_Str]){
                Ptr_Sub++;
            }
            if(Ptr_Sub == Size_Sub){
                return true;
            }
            Ptr_Str++;
        }
        return false;
        
    }
};

*/