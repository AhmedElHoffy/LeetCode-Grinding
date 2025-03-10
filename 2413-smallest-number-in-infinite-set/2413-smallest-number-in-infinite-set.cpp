class SmallestInfiniteSet {
public:
   set<int> S;
    int i;

    SmallestInfiniteSet() {
        i = 1;
    }

    int popSmallest() {
        if (!S.empty()) {
            int smallest = *S.begin(); // Get the smallest number
            S.erase(S.begin());        // Remove from the set
            return smallest;
        }
        return i++;
    }

    void addBack(int num) {
        if (num < i) { // Ensure only missing elements are added
            S.insert(num);
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
set<int> S;
    int i;

    SmallestInfiniteSet() {
        i = 1;
    }

    int popSmallest() {
        if (!S.empty()) {
            int smallest = *S.begin(); // Get the smallest number
            S.erase(S.begin());        // Remove from the set
            return smallest;
        }
        return i++;
    }

    void addBack(int num) {
        if (num < i) { // Ensure only missing elements are added
            S.insert(num);
        }
    }
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
 