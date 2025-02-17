class Solution {

    int Max_Num(int a, int b){
        if( a>=b){
            return a;
        }else{
            return b;
        }
    }
public:

  
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        //Binary Search + DP (Patience Sorting) - O(n log n)
        vector<int>LIS_BS;
        int mid;
        for(int num: nums){
            int left = 0, right = LIS_BS.size() - 1, pos = -1;
            while(left <= right){
                mid = left + (right-left)/2;
                if(LIS_BS[mid] >=num ){
                    pos = mid;  // Found a possible replacement position
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }

            //Replacement found / not found
            if(pos!=-1){
                LIS_BS[pos]=num;
            }else{
                LIS_BS.push_back(num);
            }
        }

        return LIS_BS.size();



        // Dynamic Programming Approach  O(N^2)
        /*
        vector<int>LIS(n,1);
        for(int i=n-2; i >=0 ; i--){
            for(int j=i+1 ; j<n ; j++){
                if(nums[i] < nums[j]){
                    LIS[i] = Max_Num( LIS[i],1+ LIS[j]);
                }
            }
        }
        int Max_LIS=LIS[0];
        for(int x : LIS){
            if(x > Max_LIS){
                Max_LIS = x;
            }
        }
        return Max_LIS;
        */
    }
};