class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int Word1_Size = word1.size(), Word2_Size= word2.size();
        string Result;
        int ptr1=0,ptr2=0;
        while(ptr1<Word1_Size && ptr2<Word2_Size){
            Result.push_back(word1[ptr1]);
            Result.push_back(word2[ptr2]);
            ptr1++;ptr2++;
        }
        while(ptr1<Word1_Size ){
            Result.push_back(word1[ptr1]);
            ptr1++;
        }
        
        while(ptr2<Word2_Size ){
            Result.push_back(word2[ptr2]);
            ptr2++;
        }
        return Result;
    }  
};



















/*
  int size1, size2;
        size1 = word1.size();
        size2 = word2.size();
        int c1 = 0 ;
        int c2 = 0 ;
        string result;
       for(int i = 0 ; i<size1 && i<size2;i++){
        result+=word1[i];
        result+=word2[i];
       }
       if(size1<size2){
        for(int j=size1;j<size2;j++){
            result+=word2[j];
        }
       }else{
        for(int k=size2;k<size1;k++){
            result+=word1[k];
        }
       }
        return result;
    }
    */