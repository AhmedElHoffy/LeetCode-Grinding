class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>PQ;
        int Result;
        for(int num : nums){
            PQ.push(num);
        }

        while(k>0){
            Result = PQ.top();
            PQ.pop();
            k--;
        }
        return Result;
        
    }
};





























/*
class Solution {
private:

 void Swap_Val(int &x , int &y){
    int temp = x;
    x = y;
    y = temp;
 }
 int BubbleSort_Kth_LargestElement(vector<int>&nums , int k){
    int n = nums.size();
    for(int i=0; i < k ; i++ ){
        for(int j=0; j < n-i-1 ; j++ ){
            if(nums[j] > nums[j+1]){
                Swap_Val(nums[j+1],nums[j]);
            }
        }
    }
     return nums[n-k];
 }

 // Partition function
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right]; // Choose the last element as the pivot
    int p = left; // Pointer for larger elements

    for (int i = left; i < right; i++) {
        if (nums[i] >= pivot) { // Compare with the pivot (descending order)
            swap(nums[p], nums[i]); // Swap larger element to the 'p' position
            p++; // Move the pointer for larger elements
        }
    }
    swap(nums[p], nums[right]); // Place the pivot in its correct position
    return p; // Return the index of the pivot
}

// QuickSelect function
int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left <= right) {
        int p = partition(nums, left, right); // Perform partition
        if (p == k) {
            return nums[p]; // If the pivot index matches k, return the element
        } else if (p > k) {
            return quickSelect(nums, left, p - 1, k); // Search the left subarray
        } else {
            return quickSelect(nums, p + 1, right, k); // Search the right subarray
        }
    }
    return -1; // This should never be reached if input is valid
}
public:
    int findKthLargest(vector<int>& nums, int k) {
       
        // Using STL Priority Queue
        /*priority_queue<int>PQ;
        for(int x : nums){
            PQ.push(x);
        }
        while(k>1){
            PQ.pop();
            k--;
        }
        return PQ.top();
        */
       
       
        // Using Bubble Sort (not sufficient for large Array with large Kth numebr required) as it is  O(n^2)
        //return BubbleSort_Kth_LargestElement(nums,k);

        // Using QuickSelect Algorithm
        //int n = nums.size();
       // return quickSelect(nums,0,n-1,k-1);
    //}
//};

//*/