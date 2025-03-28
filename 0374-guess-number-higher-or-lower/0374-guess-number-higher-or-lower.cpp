/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int middle;
        int left = 1;
        int right = n;

        while (left <= right) {
            middle = left + (right - left) / 2; // Avoid overflow for large values of left + right
            int key = guess(middle); // Update the result of guess for the current middle

            if (key == -1) { 
                // num > picked num
                right = middle - 1;
            } else if (key == 1) {
                // num < picked num
                left = middle + 1;
            } else {
                // num == picked num
                return middle;
            }
        }
        return -1; // Shouldn't reach here, as per problem guarantees
    }
};