class Solution {
private:
vector<int>Prefix_Sum;
int Total_Sum;

public:
    Solution(vector<int>& w) {
        Total_Sum = 0;
        for(int Weight : w){
            Total_Sum+= Weight;
            Prefix_Sum.push_back(Total_Sum);
        }
    }
    
    int pickIndex() {
        int Target_Val = rand() % Total_Sum;
        int L=0, R= Prefix_Sum.size()-1,  Mid;
        while(L < R){
            Mid = L + (R-L)/2;
            if(Target_Val < Prefix_Sum[Mid]){
                R = Mid;
            }else{
                L = Mid+1;
            }
        }
        return L;
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