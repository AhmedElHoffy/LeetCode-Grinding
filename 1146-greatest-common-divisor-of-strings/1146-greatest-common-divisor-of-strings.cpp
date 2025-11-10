class Solution {
public:

    int GCD_str(int a, int b){
        while(b!=0){
            int rem = a % b;
            a = b ;
            b = rem;
        }
        return a;
    }

    string gcdOfStrings(string str1, string str2) {
        if( str1+str2 != str2+str1) return"";
        int n1=str1.size() , n2 = str2.size();
        int GCD_size= GCD_str(n1,n2);
        return str1.substr(0,GCD_size);
    }
};