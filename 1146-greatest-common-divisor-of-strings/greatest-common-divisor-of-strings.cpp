class Solution {
private:    

    // iterative approach
    int GCD_Length_iterative(int a, int b){
        int temp;
        while(b!=0){
            temp = b;
            b= a % b;
            a = temp;
        }
        return a;
    }

    // Recursive Approach
    int GCD_Length_Recursive(int a, int b){
        if(b==0){
            return a;
        }
        return GCD_Length_Recursive(b,a%b);
    }

public:

    string gcdOfStrings(string str1, string str2) {
        int str1_size= str1.size(), str2_size = str2.size();

        string Result="";
        if(str1+str2 !=str2+str1){
            // Not Concatenated of s(t)
        }else{
            int GCD_substr_len = GCD_Length_Recursive(str1_size,str2_size);
            for(int i=0 ; i <GCD_substr_len;i++){
                Result+=str2[i];
            }
        }
        return Result;
       
    }
};













/*    int GCDLength_Strings(int a, int b){
        while( b!=0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }*/

    /*    string gcdOfStrings(string str1, string str2) {

        int size1 = str1.size();
        int size2 = str2.size();
        int GCDLength=0;
        string result="";
        if(str1+str2 != str2+str1){ // not concatenation of t(s)
        }else{
            GCDLength = GCDLength_Strings(size1,size2);
            for(int i=0;i<GCDLength;i++){
                result+=str2[i];
            }
        }
        return result;
    }
    */