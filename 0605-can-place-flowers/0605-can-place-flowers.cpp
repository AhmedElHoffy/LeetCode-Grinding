class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int Available_Slots=0;
        int Flowerbed_Size = flowerbed.size();
        bool Left_Empty,Right_Empty;
        for(int i=0 ; i < Flowerbed_Size ; i++){
            Left_Empty = (i==0) || (flowerbed[i-1]==0);
            Right_Empty = (i==Flowerbed_Size-1) || (flowerbed[i+1]==0);
            if(Left_Empty&&Right_Empty && flowerbed[i]==0 ){
                flowerbed[i]=1;
                Available_Slots++;
                if (Available_Slots >= n) return true; // Return early
            }
        }
        return (Available_Slots>=n) ? true:false;
    }
};


















/*
 for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                bool emptyPrev = (i == 0 || flowerbed[i - 1] == 0);
                bool emptyNext = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
                
                if (emptyPrev && emptyNext) {
                    flowerbed[i] = 1; // Plant a flower
                    n--; // Decrement required flowers
                }
            }
            if (n <= 0) return true; // Early exit if all flowers are planted
        }
        return n <= 0;

*/