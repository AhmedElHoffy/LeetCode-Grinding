class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int>Radiant_Q,Dire_Q;

        for(int i=0; i < n ; i++){
            if(senate[i]=='R'){
                Radiant_Q.push(i);
            }else{
                Dire_Q.push(i);
            }
        }

        int Curr_Radiant_Idx, Curr_Dire_Idx;
        while(!Radiant_Q.empty() && !Dire_Q.empty()){
            Curr_Radiant_Idx = Radiant_Q.front();
            Curr_Dire_Idx = Dire_Q.front();
            Radiant_Q.pop();
            Dire_Q.pop();

            if(Curr_Radiant_Idx < Curr_Dire_Idx){
                Radiant_Q.push(Curr_Radiant_Idx + n);
            }else{
                Dire_Q.push(Curr_Dire_Idx + n);
            }
        }
        return Radiant_Q.empty() ?  "Dire" : "Radiant";       
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