class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)

        ones1 = []
        ones2 = []

        # Step 1: Gather coordinates of all 1s in img1 and img2
        for i in range(n):
            for j in range(n):
                if img1[i][j] == 1:
                    ones1.append((i, j))
                if img2[i][j] == 1:
                    ones2.append((i, j))

        # Step 2: Create a dictionary to store translation vector counts
        shift_count = {}  # This is like map<pair<int,int>, int> in C++

        # Step 3: For every 1 in img1 and img2, compute the translation vector
        for (x1, y1) in ones1:
            for (x2, y2) in ones2:
                dx = x2 - x1
                dy = y2 - y1
                key = (dx, dy)
                if key not in shift_count:
                    shift_count[key] = 1
                else:
                    shift_count[key] += 1

        # Step 4: Find the maximum count of any translation
        max_overlap = 0
        for count in shift_count.values():
            if count > max_overlap:
                max_overlap = count

        return max_overlap