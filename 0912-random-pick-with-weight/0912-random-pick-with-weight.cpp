class Solution {
private:
    vector<double> Weights; // Store cumulative probabilities
    double TotalWeight;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        TotalWeight = 0.0;
        Weights.resize(n, 0.0);

        // Compute total sum of weights
        for (int num : w) {
            TotalWeight += num;
        }

        // Convert weights to cumulative probabilities
        double cumulativeSum = 0.0;
        for (int i = 0; i < n; i++) {
            cumulativeSum += w[i] / TotalWeight; // Use floating point
            Weights[i] = cumulativeSum; // Store cumulative probability
        }
    }
    
    int pickIndex() {
        double target = (double)rand() / RAND_MAX; // Random float in [0,1]

        // Iterate to find the first index where cumulative probability >= target
        for (int i = 0; i < Weights.size(); i++) {
            if (target < Weights[i]) return i;
        }
        return Weights.size() - 1; // Safety return (should never reach here)
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */







 /*
class Solution {
    int sum;
    vector<int> Acc_SumW;

public:
    Solution(vector<int>& w) {
        int n = w.size();
        sum = 0;
        Acc_SumW.resize(n, 0);
        for (int i = 0; i < n; i++) {
            sum += w[i];
            Acc_SumW[i] = sum;
        }
    }

    int pickIndex() {
        // Generate a random target value in the range [0, sum)
        int target_Val = rand() % sum;

        // Perform binary search to find the index
        int l = 0, r = Acc_SumW.size() - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (target_Val < Acc_SumW[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
 */