class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& Candies, int ExtraCandies) {
        int Max_Candies = INT_MIN;
        int n = Candies.size();
        vector<bool> Result(n,false);
        
        for(int Candy:Candies){
            if(Candy>=Max_Candies){
                Max_Candies = Candy;
            }
        }

        for(int i=0 ; i<n ; i++){
            if(Candies[i]+ ExtraCandies >= Max_Candies){
                Result[i]=true;
            }
        }
        return Result;
    }
};






















/* int MaxVal_Vector(vector<int> V){
        int ResultMax=V[0];
        for(int i = 1 ; i < V.size() ; i++){
            if (V[i] > ResultMax){
                ResultMax = V[i];
            }
        }
        return ResultMax;
    }
    */

      // vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       
   

    /* vector<bool>Result(candies.size(),false);

        int MaxElement= MaxVal_Vector(candies);

        for(int j= 0 ; j <candies.size() ; j++){
            if(candies[j] + extraCandies >= MaxElement){
                Result[j] = true;
            }
        }
      
        for(int i=0 ; i<candies.size();i++){
              int MaxVal=0;
            for(int j=0; j<candies.size();j++){
                if(candies[j]>MaxVal & j!=i){
                    MaxVal = candies[j];
                }
            }
            if(MaxVal <= candies[i] + extraCandies){
                Result[i]=true;
            }
        }
        //return Result;
       
    }
    */