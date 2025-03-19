class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> Stk;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            while (!Stk.empty() && Stk.top() > 0 && asteroid < 0) {
                if (Stk.top() + asteroid == 0) {
                    Stk.pop();
                    destroyed = true;
                    break;
                } else if (abs(Stk.top()) > abs(asteroid)) {
                    destroyed = true;
                    break;
                } else {
                    Stk.pop();
                }
            }

            if (!destroyed) {
                Stk.push(asteroid);
            }
        }

        vector<int> Result;
        while (!Stk.empty()) {
            Result.push_back(Stk.top());
            Stk.pop();
        }
        reverse(Result.begin(), Result.end());
        return Result;
    }
};



























/*
class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {
       vector<int> Result;
       for (int asteroid : asteroids) {
            bool destroyed = false;
            // Handle collisions when the current asteroid is moving left
            while (!Result.empty() && Result.back() > 0 && asteroid < 0) {
                if (abs(Result.back()) < abs(asteroid)) {
                    // Top asteroid is destroyed
                    Result.pop_back();
                } else if (abs(Result.back()) == abs(asteroid)) {
                    // Both asteroids destroy each other
                    Result.pop_back();
                    destroyed = true;
                    break;
                } else {
                    // Current asteroid is destroyed
                    destroyed = true;
                    break;
                }
            }
            // If the asteroid is not destroyed, add it to the result
            if (!destroyed) {
                Result.push_back(asteroid);
            }
        }
        return Result;
    }
};

*/