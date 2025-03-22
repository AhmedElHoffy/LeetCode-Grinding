class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>Result(n,0);


        //  2 While Loops Approach (not efficient with very Large Dataset)
        /*int curr_ptr=0;
        int next_ptr,count;
        while(curr_ptr < n-1){
            count=0;
            next_ptr=curr_ptr+1;
            while(next_ptr < n && temperatures[curr_ptr] >= temperatures[next_ptr] ){
                next_ptr++;
            }
            count = ( next_ptr < n) ?  next_ptr-curr_ptr : 0;
            Result[curr_ptr]=count;
            curr_ptr++;
        }*/


        //Monotonic Stack Approach (Efficient with large Dataset as each Eleement
        // Is Pushed and Popped Once at most)

         stack<int> s; // Stack to store indices of temperatures
         int idx;

        for (int i = 0; i < n; ++i) {
            // While the stack is not empty and the current temperature is greater than
            // the temperature at the index stored at the top of the stack
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                idx = s.top();
                s.pop();
                Result[idx] = i - idx; // Calculate the number of days
            }
            s.push(i); // Push the current index onto the stack
        }

        return Result;
    }
};