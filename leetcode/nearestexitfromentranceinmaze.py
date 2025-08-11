from collections import deque
class Solution:
    def nearestExit(self, maze: list[list[str]], entrance: list[int]) -> int:
        q = deque()
        #q = []
        q.append([entrance[0], entrance[1], 0])
        maze[entrance[0]][entrance[1]] = '+'
        m = len(maze)
        n = len(maze[0])
        dir = -1

        while (len(q) != 0):
            cur = q.popleft()
            if (dir != -1 and (cur[1] == n - 1 or cur[1] == 0 or cur[0] == m - 1 or cur[0] == 0)):
                return cur[2]
            dir = cur[2] + 1
            if (cur[1] < n - 1 and maze[cur[0]][cur[1] + 1] == '.'):
                q.append([cur[0], cur[1] + 1, dir])
                maze[cur[0]][cur[1] + 1] = '+'
            if (cur[1] > 0 and maze[cur[0]][cur[1] - 1] == '.'):
                q.append([cur[0], cur[1] - 1, dir])
                maze[cur[0]][cur[1] - 1] = '+'
            if (cur[0] < m - 1 and maze[cur[0] + 1][cur[1]] == '.'):
                q.append([cur[0] + 1, cur[1], dir])
                maze[cur[0] + 1][cur[1]] = '+'
            if (cur[0] > 0 and maze[cur[0] - 1][cur[1]] == '.'):
                q.append([cur[0] - 1, cur[1], dir])
                maze[cur[0] - 1][cur[1]] = '+'
            
        return -1