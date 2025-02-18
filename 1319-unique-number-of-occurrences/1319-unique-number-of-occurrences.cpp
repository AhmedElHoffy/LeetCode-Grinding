class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>Unique_Map;

        for(int num : arr){
            Unique_Map[num]++;
        }
        unordered_set<int>Freq_Set;
        for( auto x : Unique_Map){
            if(!Freq_Set.count(x.second)){
                Freq_Set.insert(x.second);
            }else{
                return false;
            }
        }
        return true;

    }
};































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