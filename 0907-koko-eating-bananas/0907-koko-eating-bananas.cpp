class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int Left= 1 ; 
        int Right = INT_MIN;
        int n = piles.size();

        for(int i = 0  ; i < n ; i++ ){
            if(piles[i]>Right){
                Right = piles[i];
            }
        }
        // piles[3,6,7,11];
        // k = [1,2,3,4,5,6,7,8,9,10,11]


         // Binary search for the minimum eating speed
        while (Left <= Right) {
            int mid = Left + (Right - Left) / 2; // Recalculate mid inside the loop
            long long h_temp = 0; // Use long long to prevent overflow

            // Calculate hours needed to eat all piles at speed `mid`
            for (int j = 0; j < n; j++) {
                h_temp += (static_cast<long long>(piles[j]) + mid - 1) / mid;
            }

            if (h_temp <= h) {
                // If we can finish within `h` hours, try a smaller eating speed
                Right = mid - 1;
            } else {
                // Otherwise, try a larger eating speed
                Left = mid + 1;
            }
        }

        return Left; // The minimum eating speed that allows Koko to finish within h hours
    }
};