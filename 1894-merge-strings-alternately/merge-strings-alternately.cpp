class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int i=0, j=0;
        string result="";
        while( i<n1 &&  j<n2){
            result+=word1[i];
            result +=word2[j];
            i++;j++;
        }
        while(i<n1){
            result+=word1[i];
            i++;
        }

        while(j<n2){
            result+=word2[j];
            j++;
        }
        return result;
        
    }
};