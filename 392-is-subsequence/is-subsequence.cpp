class Solution {
public:
    bool isSubsequence(string Sub_Str_S, string Str_T) {
        int S_size = Sub_Str_S.length(), T_size = Str_T.length();
        int Running_Idx=0;
        for(char Ch : Str_T){
            if(Sub_Str_S[Running_Idx] == Ch){
                Running_Idx++;
            }
            if(Running_Idx==S_size){
                break;
            }
        }
        return ( (Running_Idx==S_size) ? true:false);
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



/*
 bool isSubsequence(string s, string t) {

        // Faster Approach O(t_size)

        int i=0,j=0;
        int S_Size = s.size();
        int t_Size = t.size();

        while( i < S_Size &&  j < t_Size){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.size();
*/
        //Time Compelxity O(t_size * s_size)
        /*
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
        */
    //}