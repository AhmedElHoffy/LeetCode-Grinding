class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        Rows_Size = len(img)
        Cols_Size = len(img[0])

        Result_Matrix = []

        for _ in range(Rows_Size):
            Row = [0] * Cols_Size
            Result_Matrix.append(Row)

        # Directions to explore: current cell + 8 neighbors
        Directions = [(-1,-1), (-1,0), (-1,1),
                      ( 0,-1), ( 0,0), ( 0,1),
                      ( 1,-1), ( 1,0), ( 1,1)]
        
        for i in range(Rows_Size):
            for j in range(Cols_Size):
                total = 0
                Count = 0

                for Dir_X,Dir_Y in Directions:
                    new_i , new_j = i + Dir_X , j + Dir_Y
                    if 0 <= new_i < Rows_Size and 0 <= new_j < Cols_Size:
                        total+= img[new_i][new_j]
                        Count+=1
                Result_Matrix[i][j] = total // Count
        return Result_Matrix

        