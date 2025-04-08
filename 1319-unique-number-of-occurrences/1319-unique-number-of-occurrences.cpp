class Solution {
public:
    bool uniqueOccurrences(vector<int>& Arr) {
        unordered_map<int,int>Freq_Map;
        int n= Arr.size();
        for(int i=0 ; i<n ; i++){
            Freq_Map[Arr[i]]++;
        }
        unordered_map<int,int>::iterator Pair_It=Freq_Map.begin();

        unordered_set<int>Freq_Set;
        for( Pair_It ; Pair_It!=Freq_Map.end() ; Pair_It++){
            if(Freq_Set.find(Pair_It->second) != Freq_Set.end()){
                return false;
            }
            Freq_Set.insert(Pair_It->second);
        }
        return true;
    }
};



/*
unordered_map<int,int>Freq_Map;
        int n= Arr.size();
        for(int i=0 ; i<n ; i++){
            Freq_Map[Arr[i]]++;
        }
        unordered_map<int,int>::iterator Pair_It=Freq_Map.begin();

        unordered_set<int>Freq_Set;
        for( Pair_It ; Pair_It!=Freq_Map.end() ; Pair_It++){
            if(Freq_Set.find(Pair_It->second) != Freq_Set.end()){
                return false;
            }
            Freq_Set.insert(Pair_It->second);
        }
        return true;
    }
*/































/*
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>Num_Freq;

        // inserting the values in the hashmap <Value, key> where key is the number of occurrences
        for(int i=0; i < arr.size() ; i++){
                Num_Freq[arr[i]]++;
        }
        unordered_set<int> Freq_Set;
        for(const auto& pair : Num_Freq){
            if(Freq_Set.count(pair.second)){
                return false;
            }else{
                Freq_Set.insert(pair.second);
            }
        }
        return true;


    }
};


*/