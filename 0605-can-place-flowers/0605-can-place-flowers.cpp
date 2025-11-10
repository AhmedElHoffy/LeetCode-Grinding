class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int num) {
     if(num==0) return true;
     bool Left_Empty,Right_Empty;
     int n = flowerbed.size();

     for(int i=0 ; i<n ;i++){
        if(flowerbed[i]==0){
            Left_Empty =  (i==0)   || (flowerbed[i-1]==0);
            Right_Empty = (i==n-1) || (flowerbed[i+1]==0);
            if(Left_Empty && Right_Empty){
                flowerbed[i]=1;
                num--;
                if(num==0) return true;
            }
        }
     }
      return num==0;   
    }
};