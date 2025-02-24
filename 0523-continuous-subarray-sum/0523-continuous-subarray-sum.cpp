#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1; // To handle the case where the subarray starts at index 0
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            int r = (k == 0) ? total : (total % k);

            if (remainderIndex.find(r) == remainderIndex.end()) {
                remainderIndex[r] = i; // Store the first occurrence of this remainder
            } else if (i - remainderIndex[r] > 1) {
                return true; // Valid subarray found
            }
        }
        return false;
    }
};
