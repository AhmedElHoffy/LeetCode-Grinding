class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int Max_Altitude=0,Curr_Altitude=0;
        for(int x : gain){
            Curr_Altitude+=x;
            Max_Altitude = max(Max_Altitude,Curr_Altitude);
        }
        return Max_Altitude;
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