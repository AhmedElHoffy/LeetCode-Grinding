class Solution {
public:
    int largestAltitude(vector<int>& Gains) {
        int n = Gains.size();
        int Curr_Alt=0,Max_Alt=0;
        for(int Gain : Gains){
            Curr_Alt+=Gain;
            if(Curr_Alt>=Max_Alt){
                Max_Alt=Curr_Alt;
            }
        }
        return Max_Alt;
    }
};



























/*

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
    // Gain_Arr = [] , Length = n
    // Gain[i]  -->  Net Gain Attitude bet. i & i+1 for (0 <= i < n)
    int n = gain.size();
    int Max_Height = 0;
    int Curr_Height = 0;
    for (int i= 0 ; i < n ; i++){
        Curr_Height+=gain[i];
        Max_Height = (Curr_Height > Max_Height) ? Curr_Height : Max_Height;
    }
    return Max_Height;
    }
};

*/