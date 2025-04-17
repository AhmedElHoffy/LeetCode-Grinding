/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<pair<vector<NestedInteger>,int>>BFS_Q;  //{nestedList,Depth}
        int Total_Sum=0;
        BFS_Q.push({nestedList,1});

        pair<vector<NestedInteger>,int> Pair_It;
        while(!BFS_Q.empty()){
            auto [NestedList ,  Depth] = BFS_Q.front();
            BFS_Q.pop();
            
            for(auto& X : NestedList){
                if(X.isInteger()){
                    Total_Sum+= X.getInteger() * Depth;
                }else{
                    BFS_Q.push({X.getList(),Depth+1});
                }
            }
        }
        return Total_Sum;
    }
};














/*
int depthSum(vector<NestedInteger>& nestedList) {
        queue<pair<vector<NestedInteger>,int>>BFS_Q; // {NestedList, Depth}
        BFS_Q.push({nestedList,1});
        int Total_Sum=0;
        
        while(!BFS_Q.empty()){
            pair<vector<NestedInteger>,int> Pair_It = BFS_Q.front();
            BFS_Q.pop();

            for( auto& x : Pair_It.first){
                if(x.isInteger()){
                    Total_Sum+= x.getInteger() * Pair_It.second;
                }else{
                    BFS_Q.push({x.getList(),Pair_It.second +1});
                }
            }
        }
        return Total_Sum;
    }
*/


/*
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<pair<vector<NestedInteger>,int>> BFS_Q;
        BFS_Q.push({nestedList,1});
        int Total_Sum=0;

        while(!BFS_Q.empty()){
            pair<vector<NestedInteger>,int> Pair_It = BFS_Q.front();
            BFS_Q.pop();

            for (auto x : Pair_It.first){
                if(x.isInteger()){
                    Total_Sum+= x.getInteger()*Pair_It.second;
                }else{
                    BFS_Q.push({x.getList(),Pair_It.second+1});
                }
            }

        }
        return Total_Sum;
    }
};
*/