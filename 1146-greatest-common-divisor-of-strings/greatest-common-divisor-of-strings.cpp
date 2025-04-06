class Solution {
private:
    int GCD_Length_Fn(int a, int b){
        int temp=0;
        while(b!=0){
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    string gcdOfStrings(string Str1, string Str2) {

        int Size_1 = Str1.size(), Size_2 = Str2.size();
        string Result="";
        int GCD_Len=0;
        if(Str1+Str2 == Str2+Str1){
            GCD_Len = GCD_Length_Fn(Size_1,Size_2);
            for(int i=0 ; i < GCD_Len ; i++){
                Result+=Str1[i]; // either Str1[1] or Str2[i] because they are already concatanated
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