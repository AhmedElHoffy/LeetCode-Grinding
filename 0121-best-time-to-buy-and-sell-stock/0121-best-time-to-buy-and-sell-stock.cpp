class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
    int MaxProfit = 0;
    int MinPrice = INT_MAX; // initialize to the maximum value of int

        for (int i=0;i<prices.size();i++){
           
            if (prices[i]<MinPrice){
                MinPrice = prices[i];
            }
            else if(prices[i]-MinPrice>MaxProfit){
                MaxProfit = prices[i]-MinPrice;

            }
        }

        return MaxProfit;
       
    }
















        // Approach 1
        /*
        int min_price=INT_MAX;
        int max_profit=0;

        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min_price)
            {
                min_price=prices[i];
            }
            else if(prices[i]-min_price>max_profit)
            {
                max_profit= prices[i]-min_price;

            }

        }
        return max_profit;
        
        }*/

};