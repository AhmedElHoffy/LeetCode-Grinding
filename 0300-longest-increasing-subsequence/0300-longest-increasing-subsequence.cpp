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
       vector<int> lis;

        for (int num : nums) {
            // Perform manual binary search
            int left = 0, right = lis.size() - 1, pos = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (lis[mid] >= num) {
                    pos = mid;  // Found a possible replacement position
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // If no replacement found, append new element
            if (pos == -1) {
                lis.push_back(num);
            } else {
                lis[pos] = num; // Replace element at the found position
            }
        }

        return lis.size();
    


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