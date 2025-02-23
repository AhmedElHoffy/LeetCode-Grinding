class Solution {
public:
    string simplifyPath(string path) {
         int n = path.length();
        stack<string> Dir_Stk;
        string Curr_Dir;
        
        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                if (!Curr_Dir.empty()) {
                    if (Curr_Dir == "..") {
                        if (!Dir_Stk.empty()) Dir_Stk.pop();
                    } else if (Curr_Dir != ".") {
                        Dir_Stk.push(Curr_Dir);
                    }
                    Curr_Dir.clear();  // Reset Curr_Dir for the next directory
                }
            } else {
                Curr_Dir += path[i];
            }
        }
        
        // Process the last directory segment if any
        if (!Curr_Dir.empty()) {
            if (Curr_Dir == "..") {
                if (!Dir_Stk.empty()) Dir_Stk.pop();
            } else if (Curr_Dir != ".") {
                Dir_Stk.push(Curr_Dir);
            }
        }

        string Result;
        while (!Dir_Stk.empty()) {
            Result = "/" + Dir_Stk.top() + Result;
            Dir_Stk.pop();
        }

        return Result.empty() ? "/" : Result; // Ensure root is returned if stack is empty
    }
};














/*
class Solution {
public:
    string simplifyPath(string path) {
        string Result;
        stack<string> Simp_Path;
        string curr_path = "";
        int n = path.length();
        int ptr = 0;

        while (ptr < n) {
            if (path[ptr] == '/') { // Process accumulated curr_path
                if (!curr_path.empty()) { // If there is a valid curr_path
                    if (curr_path == "..") {
                        // Pop the last directory if the stack is not empty
                        if (!Simp_Path.empty()) {
                            Simp_Path.pop();
                        }
                    } else if (curr_path != ".") {
                        // Push valid directory names into the stack
                        Simp_Path.push(curr_path);
                    }
                    curr_path = ""; // Reset curr_path
                }
            } else {
                // Accumulate characters for the current directory
                curr_path += path[ptr];
            }
            ptr++;
        }

        // Final Check for any remaining curr_path
        if (!curr_path.empty()) {
            if (curr_path == "..") {
                if (!Simp_Path.empty()) {
                    Simp_Path.pop();
                }
            } else if (curr_path != ".") {
                Simp_Path.push(curr_path);
            }
        }

        // Construct the result path from the stack
        while (!Simp_Path.empty()) {
            Result = "/" + Simp_Path.top() + Result;
            Simp_Path.pop();
        }

        // Return "/" if the result is empty
        return Result.empty() ? "/" : Result;
    }
};

*/