class Solution {
private:


public:
    int maxOperations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end()); // O(n log n)
        
        int left = 0, right = nums.size() - 1;
        int count = 0;
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum == k) { 
                count++; 
                left++; 
                right--;
            } 
            else if (sum < k) { 
                left++; 
            } 
            else { 
                right--; 
            }
        }
        return count;
        
        
        // HashMap approach

        /*int n = nums.size();
        unordered_map<int,int>Freq; //integer adn freq map

        int Complement;
        int count=0;
        // Storing elements and their frequencies in the hashmap
        for(int num : nums){
            Complement = k - num;
            if(Freq[Complement]>0){
                count++;
                Freq[Complement]--;
            }else{
                Freq[num]++;
            }
        }
        return count;
        */
    }
};




















/*


class Solution {
public:
    void Swap_Int(int &x, int &y){
        int temp = x;
            x = y;
            y = temp;
    }
    int partition(vector<int>&Arr, int LeftIdx, int RightIdx){
        int i = LeftIdx;
        int j = RightIdx;
        int Pivot_Loc = i;
        while(true){

            while(Arr[Pivot_Loc] <= Arr[j]  && Pivot_Loc!=j){
                j--;
            }

            if(Pivot_Loc ==j){
                break;
            }else if(Arr[Pivot_Loc]> Arr[j]){
                Swap_Int(Arr[Pivot_Loc],Arr[j]);
                Pivot_Loc = j;
            }

            while(Arr[Pivot_Loc]>= Arr[i] && Pivot_Loc!=i){
                i++;
            }
            if(Pivot_Loc==i){
                break;
            }else if(Arr[Pivot_Loc] < Arr[i]){
                Swap_Int(Arr[Pivot_Loc],Arr[i]);
                Pivot_Loc = i;
            }

        }
        return Pivot_Loc;
    }
    void QuickSort(vector<int>&Arr, int LeftIdx, int RightIdx){
        if(LeftIdx < RightIdx){
            int Pivot = partition(Arr,LeftIdx,RightIdx);
                        QuickSort(Arr,LeftIdx,Pivot-1);
                        QuickSort(Arr,Pivot+1,RightIdx);
        }
    }
    int maxOperations(vector<int>& nums, int k) {
       
       // Quick Sort Approach and 2 ptrs (Left and Right Ptr)
       QuickSort(nums, 0, nums.size()-1);
        int Left_Ptr= 0;
        int Right_Ptr = nums.size()-1;
        int count = 0;
        while(Left_Ptr < Right_Ptr){
            int temp = k - nums[Left_Ptr];
            if(temp== nums[Right_Ptr]){
                count++;
                Left_Ptr++;
                Right_Ptr--;
            }else if(temp < nums[Right_Ptr]){
                Right_Ptr--;
            }else{
                Left_Ptr++;
            }
        }
        

     // HashMap Approach
        unordered_map<int, int> freq; // To store frequencies of elements
        int count = 0;

        for (int num : nums) {
            int complement = k - num;
            if (freq[complement] > 0) {
                // Found a pair
                count++;
                freq[complement]--; // Decrease frequency of the complement
            } else {
                // Store the current number's frequency
                freq[num]++;
            }
        }
        

        // Using Built in Sort function for vectors

        sort(nums.begin(), nums.end()); // Sort the array in ascending order
        int Left_Ptr= 0;
        int Right_Ptr = nums.size()-1;
        int count = 0;
        while(Left_Ptr < Right_Ptr){
            int temp = k - nums[Left_Ptr];
            if(temp== nums[Right_Ptr]){
                count++;
                Left_Ptr++;
                Right_Ptr--;
            }else if(temp < nums[Right_Ptr]){
                Right_Ptr--;
            }else{
                Left_Ptr++;
            }
        }
        return count;

        
    }
};

*/