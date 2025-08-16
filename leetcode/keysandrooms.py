class Solution:
    def canVisitAllRooms(self, rooms: list[list[int]]) -> bool:
        stack = [0]
        s = set()
        n = len(rooms)
        while len(stack) != 0:
            cur = stack.pop()
            s.add(cur)
            for i in rooms[cur]:
                if (i not in s):
                    stack.append(i)
                    s.add(i)
            if len(s) == n:
                return True
        return False