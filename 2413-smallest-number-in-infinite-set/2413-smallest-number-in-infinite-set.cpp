class SmallestInfiniteSet {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> PQ_Descending;
    std::set<int> addedNumbers; // Track reinserted numbers
    int i;

    SmallestInfiniteSet() {
        i = 1;
    }

    int popSmallest() {
        int Curr_Num;
        if (!PQ_Descending.empty()) {
            Curr_Num = PQ_Descending.top();
            PQ_Descending.pop();
            addedNumbers.erase(Curr_Num); // Remove from set
        } else {
            Curr_Num = i;
            i++;
        }
        return Curr_Num;
    }

    void addBack(int num) {
        // Only add num if it was previously popped and is not in the set
        if (num < i && addedNumbers.find(num) == addedNumbers.end()) {
            PQ_Descending.push(num);
            addedNumbers.insert(num);
        }
    }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */










 /*
class SmallestInfiniteSet {
private:
    set<int> available;  // Stores the numbers currently in the set
    int current;         // Tracks the smallest number not yet added back

public:
    SmallestInfiniteSet() {
        // Initialize the set with all positive integers starting from 1
        current = 1;
    }
    
    int popSmallest() {
        if (!available.empty()) {
            // Get the smallest number from the set
            int smallest = *available.begin();
            available.erase(smallest);  // Remove it from the set
            return smallest;
        } else {
            // If the set is empty, return the next smallest integer
            return current++;
        }
    }
    
    void addBack(int num) {
        // Add the number back only if it's smaller than the current minimum
        // and not already in the set
        if (num < current && available.find(num) == available.end()) {
            available.insert(num);
        }
    }
};
*/
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
 