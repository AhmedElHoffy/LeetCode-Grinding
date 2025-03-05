class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<double>Distance(n,0);
        for(int i=0 ; i<n ; i++){
            Distance[i]=sqrt( (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]) ); 
        }
        priority_queue<pair<double,int>,vector<pair<double, int>>, greater<pair<double, int>>>MinHeap;
        for(int j=0 ; j < n ;j++){
            MinHeap.push({Distance[j],j});
        }
        vector<vector<int>>Result;
        for(int x=0 ; x < k ; x++){
            Result.push_back(points[MinHeap.top().second]);
            MinHeap.pop();
        }
        return Result;
    }
};