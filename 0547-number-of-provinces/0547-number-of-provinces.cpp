class Solution {
private:
    void DFS_Helper(vector<vector<int>>& isConnected, 
                   unordered_set<int>&Visited_Cities,int i){
        int n=isConnected.size();
        Visited_Cities.insert(i);
        for(int j=0; j<n ;j++){
            if(isConnected[i][j] && (Visited_Cities.count(j)==0)){
                DFS_Helper(isConnected,Visited_Cities,j);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int Provinces_Num=0;
        unordered_set<int> Visited_Cities;
        for(int i=0 ; i<n ; i++){
            {
                for(int j=0; j<n ; j++){
                    if(Visited_Cities.count(i)==0){
                        Provinces_Num++;
                        DFS_Helper(isConnected,Visited_Cities,i);
                    }
                }
            }
        }
        return Provinces_Num;
    }
};