class Solution {
public:
    string predictPartyVictory(string Senate) {
        int n = Senate.size();
        queue<pair<char,int>>Radiant,Dire;
        for(int i=0; i<n ; i++){
            if(Senate[i]=='R'){
                Radiant.push({Senate[i],i});
            }else{
                Dire.push({Senate[i],i});
            }
        }

        while(!Radiant.empty() && !Dire.empty()){
            if(Radiant.front().second < Dire.front().second){
                Dire.pop();
                Radiant.push({'R',Radiant.front().second + n});
                Radiant.pop();
            }else{
                Radiant.pop();
                Dire.push({'D',Dire.front().second + n});              
                Dire.pop();
            }
        }
        return ( (Radiant.empty())  ? "Dire":"Radiant");
    }
};














/*
class Solution {
public:
    string predictPartyVictory(string senate) {
         queue<int> Radiant, Dire;
        int n = senate.size();

        // Step 1: Populate queues with indices of 'R' and 'D'
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                Radiant.push(i);
            } else {
                Dire.push(i);
            }
        }

        // Step 2: Process rounds
        while (!Radiant.empty() && !Dire.empty()) {
            int r_index = Radiant.front();
            int d_index = Dire.front();
            Radiant.pop();
            Dire.pop();

            // Step 3: Compare indices; the earlier senator "bans" the other
            if (r_index < d_index) {
                // Radiant wins this round, push back with new index
                Radiant.push(r_index + n);
            } else {
                // Dire wins this round, push back with new index
                Dire.push(d_index + n);
            }
        }

        // Step 4: Determine the winner
        return Radiant.empty() ? "Dire" : "Radiant";
        
    }
};
*/