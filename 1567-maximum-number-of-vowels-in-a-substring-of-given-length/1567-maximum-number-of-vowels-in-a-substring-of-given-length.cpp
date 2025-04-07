class Solution {
private:
    bool Vowel_Detect(char Ch){
        if( Ch == 'a' || Ch == 'e'|| Ch == 'i' ||
            Ch == 'o' || Ch == 'u'){
                return true;
            }else{
                return false;
            }
    }

public:
    int maxVowels(string Str, int k) {
        int n = Str.size(), Vowels_Max=0;
        int Vowels_Count=0;
        for(int i=0; i<k ; i++){
            if(Vowel_Detect(Str[i])){
                Vowels_Count++;
            }
        }
        Vowels_Max = Vowels_Count;

        for(int j=k ; j<n ; j++){
            if(Vowel_Detect(Str[j])){
                Vowels_Count++;
            }
            if(Vowel_Detect(Str[j-k])){
                Vowels_Count--;
            }
            if(Vowels_Count > Vowels_Max){
                Vowels_Max = Vowels_Count;
            }
        }
        return Vowels_Max;
    }

};







/*
private:
    bool Vowel_Detect(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }else{
            return false;
        }
    }
    int Max_Num(int x, int y){
        if(x>=y){
            return x;
        }else{
            return y;
        }
    }
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int Curr_Count=0 , Max_Count=0;
        // Initial Window
        for(int i = 0 ; i < k ; i++){
            if(Vowel_Detect(s[i])){
                Curr_Count++;
            }
        }
        Max_Count = Curr_Count;

        for(int j = k ; j < n ; j++){
            if(Vowel_Detect(s[j])){
                Curr_Count++;
            }
            if(Vowel_Detect(s[j-k])){
                Curr_Count--;
            }
            Max_Count = Max_Num(Max_Count, Curr_Count);
        }

        return Max_Count;
    }



*/

























/*
class Solution {
public:
    int Max_Num(int x, int y){
        if(x >=y){
            return x;
        }else{
            return y;
        }

    }
    int maxVowels(string s, int k) {
        int Max_count=0;
        int curr_count=0;
        unordered_set<char>Vowels = {'a','e','i','o','u'};
        for(int i=0;i<k;i++){
            if(Vowels.count(s[i])){
                curr_count++;
            }
        }
        Max_count = curr_count;
        for(int j=1 ; j+k<= s.size() ;j++){
            if(Vowels.count(s[j-1])){
                curr_count--;
            }
            if(Vowels.count(s[j+k-1])){
                curr_count++;
            }
            Max_count = Max_Num(Max_count,curr_count);
        }
        return Max_count;
    }
};

*/