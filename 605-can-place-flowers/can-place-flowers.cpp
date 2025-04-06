class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int Size = flowerbed.size();
        
        if(n==0){
            return true;
        }else if(n>Size){
            return false;
        }

        if(Size>=2){
            if(flowerbed[0]==0 && flowerbed[1]==0 && n>0){
                n--;
                flowerbed[0]=1;
            }

        for(int i=1 ; i < Size-1 ; i++){
            cout<<"We are at i = "<<i<<endl;
            if (n==0)break;
            if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                n--;
                flowerbed[i]=1;
                cout<<"FlowerBed at "<<i<<" Changed to 1"<<endl;

            }
        }

        if(flowerbed[Size-1]==0 && flowerbed[Size-2]==0 && n>0){
                n--;
                flowerbed[Size-1]=1;
            }
        
        }else if (Size==1){
            if(flowerbed[0]==0 && n>0){
                n--;
            }
        }

        return ( (n==0) ? true:false) ;
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