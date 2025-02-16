class Solution {
public:

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int Size_Candies = candies.size();
        vector<bool>Result(Size_Candies,false);
        int Max_num = candies[0];
        for(int i=1 ; i < Size_Candies ; i++){
            if(candies[i] >= Max_num ){
                Max_num = candies[i];
            }
        }

        for(int i=0 ; i < Size_Candies ; i++){
            if(candies[i] + extraCandies >=Max_num){
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