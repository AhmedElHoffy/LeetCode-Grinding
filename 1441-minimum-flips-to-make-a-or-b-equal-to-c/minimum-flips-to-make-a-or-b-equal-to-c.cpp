class Solution {
public:
    int minFlips(int a, int b, int c) {
        int Total_Flips=0;
        int Curr_bitA, Curr_bitB, Curr_bitC;
        for (int bit =0 ; bit <32 ; bit++){
            Curr_bitA = (a >> bit) & 1;
            Curr_bitB = (b >> bit) & 1;
            Curr_bitC = (c >> bit) & 1;

            if(Curr_bitC==1){
                if(Curr_bitA==0 && Curr_bitB==0){
                    Total_Flips++;
                }
            }else{
                if(Curr_bitA==1) Total_Flips++;
                if(Curr_bitB==1) Total_Flips++;
            } 
        }
        return Total_Flips;
    }
};