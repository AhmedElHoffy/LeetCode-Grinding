class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>Visitied_Cities(n,false);
        int Provinces_Num=0;
        stack<int>Stk;
        int Curr_City;
        for(int i=0; i<n ; i++){
            if(!Visitied_Cities[i]){
                Stk.push(i);
            
            while(!Stk.empty()){
                Curr_City = Stk.top();
                Stk.pop();

                if(!Visitied_Cities[Curr_City]){
                    Visitied_Cities[Curr_City] = true;

                    for(int j=0; j<n ; j++){
                        if(isConnected[Curr_City][j] && !Visitied_Cities[j]){
                            Stk.push(j);
                        }
                    }
                }
            }
            Provinces_Num++;
            }
        }
        return Provinces_Num;
    }
};