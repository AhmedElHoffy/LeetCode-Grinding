class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
        vector<int>Merged(m+n,0);

        int Ptr_m=0, Ptr_n=0, Ptr_mn=0;
        while(Ptr_m<m && Ptr_n<n){
            if(nums1[Ptr_m]<= nums2[Ptr_n]){
                Merged[Ptr_mn++] = nums1[Ptr_m];
                Ptr_m++;
            }else{
                Merged[Ptr_mn++] = nums2[Ptr_n];
                Ptr_n++;
            }
        }
        while(Ptr_m<m){
            Merged[Ptr_mn++] = nums1[Ptr_m];
            Ptr_m++;
        }
        while(Ptr_n<n){
            Merged[Ptr_mn++] = nums2[Ptr_n];
            Ptr_n++;
        }
        nums1=Merged;
    }
};

















/*
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int Ptr1=m-1,Ptr2=n-1;
        int Ptr3 = m+n-1;
        while(Ptr1>= 0 && Ptr2 >=0 ){
            if(nums1[Ptr1] > nums2[Ptr2]){
                nums1[Ptr3] = nums1[Ptr1];
                Ptr1--;
            }else{
                nums1[Ptr3] = nums2[Ptr2];
                Ptr2--;
            }
            Ptr3--;
        }
        while(Ptr2>=0){
            nums1[Ptr3]=nums2[Ptr2];
            Ptr3--;
            Ptr2--;
        }
        
    }
*/
















/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr_m=m-1;
        int ptr_n = n-1;

        int ptr_mn = m+n-1;
        while( ptr_m>=0 && ptr_n>=0){
            if(nums1[ptr_m] > nums2[ptr_n]){
                nums1[ptr_mn--] = nums1[ptr_m--];
            }else{
                nums1[ptr_mn--] = nums2[ptr_n--];
            }
        }
        while(ptr_n >=0){
            nums1[ptr_mn--]=nums2[ptr_n--];
        }
    }
};

*/