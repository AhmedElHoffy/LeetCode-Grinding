class Solution {
public: 
    int minFlips(int a, int b, int c) {
        int count = 0;
      
      
      // Bit Manipulation Solution
      /*
      while( a>0 || b>0 || c>0){
        //(LSB extract)
        int bit_a = a & 1; 
        int bit_b = b & 1;
        int bit_c = c & 1;

        // if LSB at c is zero , LSB at A and at B are 1's , we need to flip both of them
        if(bit_c==0){
            count+= bit_a + bit_b;
        }else{
            // bit_c == 1 , we flip only 1 of A or B if botha are 0s 
            if(bit_a==0 && bit_b==0){
                count++;
            }
        }
        //SHR
        a >>= 1;
        b >>= 1;
        c >>= 1;
      }
      */

      // Calculating the Remainder solution (Slower)

       while( a>0 || b>0 || c>0){
        //(LSB extract)
        int bit_a = a % 2; 
        int bit_b = b % 2;
        int bit_c = c % 2;

        // if LSB at c is zero , LSB at A and at B are 1's , we need to flip both of them
        if(bit_c==0){
            count+= bit_a + bit_b;
        }else{
            // bit_c == 1 , we flip only 1 of A or B if botha are 0s 
            if(bit_a==0 && bit_b==0){
                count++;
            }
        }
        //SHR
        a /= 2;
        b /= 2;
        c /= 2;
      }
      return count;
    }
};