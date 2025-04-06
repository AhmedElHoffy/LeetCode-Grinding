class Solution {
public:
    bool canPlaceFlowers(vector<int>& Flowerbed, int n) {
        int Size = Flowerbed.size();
        bool Empty_Left, Empty_Right;

        for(int i=0 ; i < Size && n>0 ; i++){
            if(Flowerbed[i]==0){
                Empty_Left= (i==0 || Flowerbed[i-1]==0);
                Empty_Right = (i==Size-1 || Flowerbed[i+1]==0);

                if(Empty_Left && Empty_Right){
                    Flowerbed[i]=1;
                    n--;
                }
            }
        }

        return n==0;
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