class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> WordSet(wordList.begin(),wordList.end());

        if(WordSet.find(endWord)==WordSet.end())return 0; // If endWord is not in wordList

        queue<pair<string,int>> BFS_Q;

        BFS_Q.push({beginWord,1}); // Start BFS with beginWord

        while(!BFS_Q.empty()){
            auto [ Curr_Word , Length] = BFS_Q.front();
            BFS_Q.pop();

             if (Curr_Word == endWord) return Length; // If we reached the endWord

            // Try All Possible  one lette Transformations
            for( int i=0; i < Curr_Word.size() ; i++){
                char Original_Char = Curr_Word[i];

                for(char ch='a'; ch <='z';ch++){
                    Curr_Word[i] = ch;
                    if(WordSet.find(Curr_Word)!=WordSet.end()){
                        BFS_Q.push({Curr_Word,Length+1});
                        WordSet.erase(Curr_Word); // Remove From Word Set to avoid Revisiting
                    }
                }

                Curr_Word[i] = Original_Char; //  Restore Original Letter
            }

        }

        return 0;
        
    }
};