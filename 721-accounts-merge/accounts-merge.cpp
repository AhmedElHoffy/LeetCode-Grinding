class Solution {
public:
    unordered_set<string> visited_accounts;
    unordered_map<string,vector<string>> Adjacent_Accounts;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        // BFS Approach

        int n = accountList.size();

        // Build the Adjacency Lists;
        for(const vector<string>& account : accountList){
            int account_size = account.size();
            string accountFristEmail = account[1];
            for(int j=2 ; j  < account_size ; j++){
                string email = account[j];
                Adjacent_Accounts[accountFristEmail].push_back(email);
                Adjacent_Accounts[email].push_back(accountFristEmail);
            }
        }

        // Traverse accounts and use BFS to find connected components
        vector<vector<string>>mergedAccounts;

        for(vector<string>& account : accountList){
            string accountName = account[0];
            string accountFristEmail = account[1];

            if(visited_accounts.find(accountFristEmail)==visited_accounts.end()){
                vector<string>MergedAccount;
                queue<string>BFS_Q;

                // BFS Traversal

                BFS_Q.push(accountFristEmail);
                visited_accounts.insert(accountFristEmail);

                while(!BFS_Q.empty()){
                    string email = BFS_Q.front();
                    BFS_Q.pop();
                    MergedAccount.push_back(email);

                    for(const string& neighbor:Adjacent_Accounts[email]){
                        if(visited_accounts.find(neighbor)==visited_accounts.end()){
                            visited_accounts.insert(neighbor);
                            BFS_Q.push(neighbor);
                        }
                    }
                }

                // sort emails and add account name
                sort(MergedAccount.begin(),MergedAccount.end());
                MergedAccount.insert(MergedAccount.begin(),accountName);
                mergedAccounts.push_back(MergedAccount);
            }
            
        }
        return mergedAccounts;

    }
};















/*
class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;
    
    void DFS(vector<string>& mergedAccount, const string& email) {
        visited.insert(email);
        // Add the email vector that contains the current component's emails
        mergedAccount.push_back(email);
        
        for (const string& neighbor : adjacent[email]) {
            if (visited.find(neighbor) == visited.end()) {
                DFS(mergedAccount, neighbor);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        int accountListSize = accountList.size();
        
         for (vector<string>& account : accountList) {
            int accountSize = account.size();
            
            // Building adjacency list
            // Adding edge between first email to all other emails in the account
            string accountFirstEmail = account[1];
            for (int j = 2; j < accountSize; j++) {
                string email = account[j];
                adjacent[accountFirstEmail].push_back(email);
                adjacent[email].push_back(accountFirstEmail);
            }
        }
        
        // Traverse over all th accounts to store components
        vector<vector<string>> mergedAccounts;
        for (vector<string>& account : accountList) {
            string accountName = account[0];
            string accountFirstEmail = account[1];
            
            // If email is visited, then it's a part of different component
            // Hence perform DFS only if email is not visited yet
            if (visited.find(accountFirstEmail) == visited.end()) {
                vector<string> mergedAccount;
                // Adding account name at the 0th index
                mergedAccount.push_back(accountName);
                DFS(mergedAccount, accountFirstEmail);
                // Skip the first element (name)
                // Name should be the first element, we only need to sort the emails
                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(mergedAccount);
            }
        }
        
        return mergedAccounts;
    }
};

*/