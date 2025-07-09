class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        # Step 1: Transpose the Matrix (Swap matrix[i][j] with matrix[j][i])
        for i in range(n):
            for j in range(i+1,n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        

        # Step 2: Reverse Rows
        for Curr_row in range(n):
            left_idx , right_idx = 0 , n-1
            while (left_idx < right_idx):
                matrix[Curr_row][left_idx], matrix[Curr_row][right_idx] = matrix[Curr_row][right_idx], matrix[Curr_row][left_idx]
                left_idx +=1
                right_idx -=1
