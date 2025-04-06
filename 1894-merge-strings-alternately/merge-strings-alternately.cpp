class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int i=0,j=0;
        string Result="";
        
        if(n1==0 && n2==0){
            return Result;
        }else if(n1==0){
            return word2;
        }else if (n2==0){
            return word1;
        }

        while(i<n1 && j<n2){
            Result+=word1[i];
            Result+=word2[j];
            i++;
            j++;
        }

        while(i<n1){
            Result+=word1[i];
            i++;
        }

        
        while(j<n2){
            Result+=word2[j];
            j++;
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