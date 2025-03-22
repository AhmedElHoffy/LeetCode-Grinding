class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        
        //Points sorted by Xend;
        sort(points.begin(),points.end(), [] (const vector<int>&a,vector<int>&b){
            return a[1] < b[1];
        });

        int Overlap=0;
        int Lastend=points[0][1];

        for(int i=1 ; i < n ; i++){
            if(Lastend >= points[i][0]){
                Overlap++;
            }else{
                Lastend = points[i][1];
            }
        }
        return n - Overlap;

    }
};