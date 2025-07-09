class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        n = len(image)

        for row in image:
            left_idx , right_idx = 0 , n-1

            while (left_idx <= right_idx):
                row[left_idx] , row[right_idx] = row[right_idx] ^ 1 , row[left_idx] ^ 1
                left_idx+=1
                right_idx-=1
        return image
        