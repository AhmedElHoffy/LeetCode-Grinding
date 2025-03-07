class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int n = arr.size();

       // Approach 1 : Time : O(n+k), space: O(1)
       /*
        int missing_count=0,current_num=1,Index=0;

        while(missing_count < k){
            if(Index < n && current_num==arr[Index]){
                Index++;
            }else{
                missing_count++;
                if(missing_count==k){
                    return current_num;
                }
            }
            current_num++;
        }
        return -1; //shouldn't reach this point
        */

        // Approach 2 : Binary Search -->  Time: O(log(n))

        int left = 0 , right = n-1;
        int mid, missing_count;

        while(left <=right){
            mid = left + (right-left)/2;
            missing_count = arr[mid] - (mid+1);

            if(missing_count < k ){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return left + k;
    }
};