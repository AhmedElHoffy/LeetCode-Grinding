class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int Max_Num = INT_MIN, n = candies.size();
        for(int Candy : candies){
            if(Candy>Max_Num){
                Max_Num = Candy;
            }
        }
        vector<bool>Result(n,false);
        for(int i=0; i<n ; i++){
            if( (candies[i] + extraCandies) >=Max_Num){
                Result[i]=true;
            }
        }
        return Result;
    }
};