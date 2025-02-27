class Solution {
private: 

   // Helper Backtracking Function
    void BackTrack_Fn(const string& Digits, int DigitIdx, string Curr_Str, 
                      unordered_map<int, vector<char>>& Digits_Map, vector<string>& Results) {
        // Base Case: If the current string length matches the digits length, add it to results
        if (Curr_Str.size() == Digits.size()) {
            Results.push_back(Curr_Str);
            return;
        }

        // Get the current digit and its corresponding letters
        int Current_Digit = Digits[DigitIdx] - '0'; // Convert char to int
        for (char c : Digits_Map[Current_Digit]) {
            // Append the character and move to the next digit
            BackTrack_Fn(Digits, DigitIdx + 1, Curr_Str + c, Digits_Map, Results);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
             if (digits.empty()) return {}; // If input is empty, return empty vector

        vector<string> Results; // Final results to store combinations

        // Map of digits to corresponding letters
        unordered_map<int, vector<char>> Digits_Map = {
            {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}},
            {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}
        };

        // Start backtracking
        BackTrack_Fn(digits, 0, "", Digits_Map, Results);

        return Results;
    }
};