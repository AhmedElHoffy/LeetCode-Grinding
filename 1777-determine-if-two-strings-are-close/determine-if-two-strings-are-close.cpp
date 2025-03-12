class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        unordered_set<char>Word1_Set;
        unordered_set<char>Word2_Set;

        unordered_map<char,int>Word1_MapFreq;
        unordered_map<char,int>Word2_MapFreq;
        // string word1 and strign word2 must be same size to be able to 
        //perofrm operation 2 successfully
        if(n1!=n2){
            return false;
        }

        for(char c1 : word1){
            Word1_Set.insert(c1);
        }

        for(char c2 : word2){
            Word2_Set.insert(c2);
        }

        // same letters must be in both strings regardless size
        for( char c : Word1_Set ){
            if(!Word2_Set.count(c)){
                return false;
            }
        }




        multiset<int>Freq1;
        multiset<int>Freq2;

        for(char c1 : word1){
            Word1_MapFreq[c1]++;
        }

        for(char c2 : word2){
            Word2_MapFreq[c2]++;
        }

        for(const auto& pair : Word1_MapFreq){
            Freq1.insert(pair.second);
        }

        for(const auto& pair : Word2_MapFreq){
            Freq2.insert(pair.second);
        }

        return Freq1==Freq2;



    }
};





























/*

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();


        // Step 1: If sizes are not equal, return false
        if (size1 != size2) {
            return false;
        }


        // Step 2: Check if both words have the same set of characters
        unordered_set<char> Word1_Set(word1.begin(), word1.end());
        unordered_set<char> Word2_Set(word2.begin(), word2.end());
        
         if(Word1_Set!=Word2_Set){
            return false;
         }
        
        
        // Step 3: Calculate the frequency of each character
        unordered_map<char, int> Word1_Freq, Word2_Freq;
        for (char c : word1) {
            Word1_Freq[c]++;
        }

        for (char c : word2) {
            Word2_Freq[c]++;
        }


                // Step 4: Compare frequency counts (sorted)
        vector<int> freq1, freq2;

        for (auto& pair : Word1_Freq) {
            freq1.push_back(pair.second);
        }
        for (auto& pair : Word2_Freq) {
            freq2.push_back(pair.second);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2; // Compare sorted frequencies


        
    }
};
*/