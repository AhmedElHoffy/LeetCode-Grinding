class Solution {
private:


public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(), [] (const vector<int> &a , const vector<int>&b){
            return a[1] < b[1];
        });
        int erase=0;
         // Sort intervals based on their ending times

        // Using Linear iteration (O(n) and saving last end time of the interval)
        int lastEnd = intervals[0][1]; // Keep track of the end of the last non-overlapping interval

        for (int i = 1; i < intervals.size(); ++i) {
            // If the current interval overlaps with the last one
            if (intervals[i][0] < lastEnd) {
                ++erase;
            } else {
                // Update the end of the last non-overlapping interval
                lastEnd = intervals[i][1];
            }
        }

        
        // Using 2 Nested While Loops (O(n^2) Time Complexity , not really efficient)
        /*
        int curr_ptr=0;
        int next_ptr = curr_ptr+1;
        cout<<" Sorted Array is = [ ";
        for( auto pair : intervals){
            cout<<"["<<pair[0]<<","<<pair[1]<<"] ";
        }
        cout<<" ]"<<endl;
        while(curr_ptr < n -1){

            while( next_ptr< n && intervals[curr_ptr][1] > intervals[next_ptr][0]){
                next_ptr++;
                erase++;
                cout<<"Overlapping found! , Erase now is = "<<erase<<endl;
            }
            curr_ptr=next_ptr;
            next_ptr = curr_ptr+1;
        }
        */

        return erase;
    }
};