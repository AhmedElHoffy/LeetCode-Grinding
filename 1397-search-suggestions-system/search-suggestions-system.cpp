class Trie{
private: 
    struct TrieNode{
        bool IsEndOfWord;
        unordered_map<char,TrieNode*>Children;
        vector<string>Suggesstions;  // Store up to 3 suggesstions
    };

    TrieNode* root;
public:

    Trie(){
        root = new TrieNode();
    }

    void Insert(string word){
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->Children[c]){
                curr->Children[c] = new TrieNode();
            }
            curr = curr->Children[c];
            if(curr->Suggesstions.size() < 3){
                curr->Suggesstions.push_back(word);
            }
        }
        curr->IsEndOfWord = true;     
    }

    vector<string> GetSuggesstions(string Prefix){
        TrieNode* curr = root;
        for(char c: Prefix){
            if(!curr->Children[c]){
                return {}; //Prefix Not found
            }
            curr = curr->Children[c];
        }
        return curr->Suggesstions;
    }

};

class Solution {

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        // Sort products lexicographically to ensure suggestions are in order
        sort(products.begin(), products.end());



        //Prefix Trie Solution

        /*
        Trie trie;
        for( const string&product : products){
            trie.Insert(product);
        }

        vector<vector<string>>Result;
        string Prefix = "";

        for(char c : searchWord){
            Prefix+=c;
            Result.push_back(trie.GetSuggesstions(Prefix));
        }

        return Result;


        */
         
         // 3 nested loops approach

         
        
         // Result vector with size equal to the length of searchWord
        vector<vector<string>> Recommended_Products(searchWord.size());

        // Iterate over each character in searchWord
        for (int i = 0; i < searchWord.size(); i++) {
            // Iterate over each product
            for (int j = 0; j < products.size(); j++) {
                // Check if the product matches the prefix of length (i + 1)
                bool matches = true;
                for (int k = 0; k <= i; k++) {
                    if (k >= products[j].size() || products[j][k] != searchWord[k]) {
                        matches = false;
                        break;
                    }
                }

                // If the product matches the prefix, add it to the list
                if (matches) {
                    Recommended_Products[i].push_back(products[j]);
                }

                // Limit to 3 suggestions
                if (Recommended_Products[i].size() == 3) break;
            }
        }
        return Recommended_Products;

    }
};