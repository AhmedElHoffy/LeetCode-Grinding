class Solution {

private:
    int Num2Bin_Conv(int x){
        int CountOnes=0;
        while(x>0){
            CountOnes+=(x%2);
            x/=2;
        }
        return CountOnes;
    }

public:
    vector<int> countBits(int n) {
        vector<int>Ans(n+1,0);

        for(int i=0 ; i <=n ; i++){
            Ans[i] = Num2Bin_Conv(i);
        }

      return Ans;  
    }
};