class Solution {
public:
    bool closeStrings(string Word1, string Word2) {
        int n1 = Word1.size(), n2 = Word2.size();
        if(n1!=n2){
            return false;
        }

        unordered_map<char,int>Freq_Map1,Freq_Map2;
        unordered_set<char>Unique_Set1,Unique_Set2;
        multiset<char>Freq_Set1,Freq_Set2;

        for(char Ch1 : Word1){
            Freq_Map1[Ch1]++;
            Unique_Set1.insert(Ch1);
        }
        
        for(char Ch2 : Word2){
            Freq_Map2[Ch2]++;
            Unique_Set2.insert(Ch2);
        }

        for(const auto& Pair_It1 : Freq_Map1){
            Freq_Set1.insert(Pair_It1.second);
        }

        for(const auto& Pair_It2 : Freq_Map2){
            Freq_Set2.insert(Pair_It2.second);
        }

        if(Unique_Set1!= Unique_Set2) return false;
        if(Freq_Set1!= Freq_Set2) return false;
        
        return true;

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