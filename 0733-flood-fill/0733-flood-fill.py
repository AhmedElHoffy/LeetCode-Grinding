class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        Orig_Image = image[sr][sc]

        if Orig_Image == color:
            return image
        
        rows , cols = len(image) , len(image[0])

        Q_BFS = deque([(sr,sc)])

        image[sr][sc] = color

        # BFS

        while Q_BFS:
            Curr_row , Curr_Col = Q_BFS.popleft()

            for i , j in ((1,0) , (-1,0) , (0,1) , (0,-1)):
                new_row , new_col = Curr_row + i , Curr_Col + j

                if  0 <= new_row < rows and 0 <= new_col < cols  and image[new_row][new_col] == Orig_Image:
                    image[new_row][new_col] = color
                    Q_BFS.append((new_row,new_col))
        return image