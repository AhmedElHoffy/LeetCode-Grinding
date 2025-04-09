class RecentCounter {
public:
    queue<int>Q_Calls;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        Q_Calls.push(t);
            while(Q_Calls.front() < t-3000){
                Q_Calls.pop();
            }
        return Q_Calls.size();
    }
};






/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */




 /*
class RecentCounter {
public:
    queue<int> Result;
    RecentCounter() {
    // Constructor initializes the queue (no additional logic needed)
    }
    
    int ping(int t) {
        Result.push(t);
        while(Result.front() < t-3000){
            Result.pop();
        }
        return Result.size();
    }
};
*/
/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */


