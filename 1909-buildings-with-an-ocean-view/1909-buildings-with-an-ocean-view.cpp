class Solution {
public:
    vector<int> findBuildings(vector<int>& Heights) {
 int n = Heights.size();
    vector<int> result;
    int Max_Height = INT_MIN;

    for (int j = n - 1; j >= 0; j--) {
        if (Heights[j] > Max_Height) {
            result.push_back(j);
            Max_Height = Heights[j];
        }
    }

    reverse(result.begin(), result.end());
    return result;
    }
};


















/*
⏱ Time & Space Complexity
Time: O(n)

Space: O(n) — because of the stack and result list

 vector<int> findBuildings(vector<int>& Heights) {
     int n = Heights.size();
     stack<int>Stk;
     int Max_Height=INT_MIN;

     for(int j=n-1 ; j>=0 ; j--){
        if(Heights[j]>Max_Height){
            Max_Height=Heights[j];
            Stk.push(j);
        }
     }

     vector<int>Result;
     while(!Stk.empty()){
        Result.push_back(Stk.top());
        Stk.pop();
     } 
     return Result;
    }
*/











/*
 vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int Max_Height=INT_MIN;
        stack<int>Stk;
        vector<int>Result;
        for(int j = n-1 ; j>=0 ; j--){
            if(heights[j] > Max_Height){
                Max_Height= heights[j];
                Stk.push(j);
            }
        }
        while(!Stk.empty()){
            Result.push_back(Stk.top());
            Stk.pop();
        }
        return Result;
    }
*/





/*
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int>Buildings_Idx;
        int Max_Height=INT_MIN;
        int n = heights.size();
        for(int j = n-1 ; j>=0 ; j--){
            if(heights[j]>Max_Height){
                Buildings_Idx.push(j);
                Max_Height=heights[j];
            }
        }
        vector<int>Result;
        while(!Buildings_Idx.empty()){
            Result.push_back(Buildings_Idx.top());
            Buildings_Idx.pop();
        }
        return Result;
    }
};
*/