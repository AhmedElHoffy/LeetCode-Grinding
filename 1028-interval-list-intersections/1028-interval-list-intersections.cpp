class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1=firstList.size(), n2=secondList.size();
        vector<vector<int>>Intersection_List;
        int i=0, j=0;
        int start,end;
        while( i<n1 && j<n2){
            start = max(firstList[i][0],secondList[j][0]);
            end   = min(firstList[i][1],secondList[j][1]);

            if(start<=end){
                Intersection_List.push_back({start,end});
            }

            if(firstList[i][1] < secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }

        return Intersection_List;

        
    }
};













/*
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> Intersection_List;
        int i = 0, j = 0;

        while (i < firstList.size() && j < secondList.size()) {
            // Find the overlap between intervals
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            // If there is an intersection, add it to the result
            if (start <= end) {
                Intersection_List.push_back({start, end});
            }

            // Move the pointer of the interval that ends first
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return Intersection_List;
    }
};

*/