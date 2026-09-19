class Solution(object):
    ans = [[]]

    def valid(self, i, j, color, ori_color):
        if i<0 or i>=len(self.ans) or j<0 or j>=len(self.ans[0]) or self.ans[i][j] != ori_color:
            return False
        return True

    def rec_floodfill(self, i, j, color, ori_color):
        if not self.valid(i, j, color, ori_color):
            return

        self.ans[i][j] = color

        self.rec_floodfill(i+1, j, color, ori_color)
        self.rec_floodfill(i-1, j, color, ori_color)
        self.rec_floodfill(i, j+1, color, ori_color)
        self.rec_floodfill(i, j-1, color, ori_color)

    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        curr_color = image[sr][sc]
        if (curr_color == color):
            return image

        self.ans = image

        self.rec_floodfill(sr, sc, color, curr_color)

        return self.ans