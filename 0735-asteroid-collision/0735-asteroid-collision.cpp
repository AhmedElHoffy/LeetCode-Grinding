class Solution {
        // Cases:
        //  1. Curr(+ve) && New(+ve) (Good)
        //  2. Curr(-ve) && New(-ve) (Good)
        //  3. Curr(-ve) && New(+ve) (Good)
        //  4. Curr(+ve) && New(-ve) (Collision)
        //      a. Curr >  abs(New) Keep Curr and Destroy New 
        //      b. Curr == abs(New) Destroy Both
        //      c. Curr <  abs(New) Destroy Curr and Add New
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int Write=0;
        bool Destroyed_New = false;

        for(int Ast : asteroids){
            Destroyed_New = false;

            while(Write>0 && asteroids[Write-1]>0 && Ast<0){
                if(asteroids[Write-1] < -Ast){
                    Write--;
                }else if(asteroids[Write-1] == -Ast){
                    Write--;
                    Destroyed_New = true;
                    break;
                }else{
                    Destroyed_New = true;
                    break;
                }
            }

            if(!Destroyed_New){
                asteroids[Write++] = Ast;
            }
        }
        asteroids.resize(Write);
        return asteroids;

    }
};











/*

vector<int> asteroidCollision(vector<int>& Asteroids) {
        stack<int>Stk;

        for(int Ast : Asteroids){
            if(Ast > 0){
                Stk.push(Ast);
            }else{
                while(!Stk.empty() && Stk.top()>0 &&  Stk.top()<-Ast){
                    Stk.pop();
                }

                if(Stk.empty() || Stk.top()<0){
                    Stk.push(Ast);
                }

                if(!Stk.empty() &&  Stk.top() == -Ast){
                    Stk.pop();
                }
            }
        }
        vector<int>Result(Stk.size());
        int j = Result.size()-1;
        while(!Stk.empty()){
            Result[j--] = Stk.top();
            Stk.pop();
        }
        return Result;
    }
*/




















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