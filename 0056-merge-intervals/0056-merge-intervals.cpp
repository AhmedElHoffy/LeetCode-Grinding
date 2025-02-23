class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& Intervals) {
        int n = Intervals.size();
        vector<vector<int>> Result;
        sort(Intervals.begin(),Intervals.end(), [] (vector<int> &a, vector<int>&b){
            return a[0] < b[0]; // Sort by start time
        });

        vector<int>Curr_Interval = Intervals[0];
        for(int i = 1  ; i < n ; i++){
            if(Curr_Interval[1] < Intervals[i][0]){
                Result.push_back(Curr_Interval);
                Curr_Interval = Intervals[i];
            }else{
                if( Curr_Interval[1] <= Intervals[i][1] ){
                    Curr_Interval[1] = Intervals[i][1];
                }

            }
        }

        if(!Curr_Interval.empty()){
            Result.push_back(Curr_Interval);
        }
        return Result;        
    }
};













/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>Result;
         sort(intervals.begin(), intervals.end());
        // Initialize with the first interval
        vector<int> Curr_Interval = intervals[0];
        int LastEnd = intervals[0][1]; // Initialize LastEnd
        
        for (int i = 1; i < intervals.size(); i++) {
            // Check if the current interval overlaps with the previous one
            if (LastEnd >= intervals[i][0]) {
                // Merge intervals by updating the end time
                Curr_Interval[1] = max(Curr_Interval[1], intervals[i][1]);
                LastEnd = Curr_Interval[1]; // Update LastEnd
            } else {
                // No overlap, add the current interval to the result
                Result.push_back(Curr_Interval);
                // Update to the next interval
                Curr_Interval = intervals[i];
                LastEnd = Curr_Interval[1]; // Update LastEnd
            }
        }
        
        // Add the last interval
        Result.push_back(Curr_Interval);
        return Result;
    }
};
*/