class Solution {
public:
    double myPow(double &x, int n) {
        long long Power = n;
        if(Power<0){
            x = 1 /x;
            Power = -Power;
        }
        if(Power==0) return 1;

        double Half = myPow(x,Power/2);
        if(Power%2==0){
            return Half * Half;
        }else{
            return Half * Half* x;
        }
    }
};























/*
 double myPow(double x, int n) {
    if (n == 0) return 1;  // Base case: x^0 = 1
        if (x == 0) return 0;  // Base case: 0^n = 0 (for n > 0)

        // Handle negative n by converting to long long to avoid overflow
        long long absN = abs((long long)n);

        // Recursive calculation
        double half = myPow(x, absN / 2);

        // Combine results
        double result = half * half;
        if (absN % 2 != 0) result *= x;  // If n is odd, multiply by x once more

        // If n is negative, return 1 / result
        return (n < 0) ? 1 / result : result;
        }
*/