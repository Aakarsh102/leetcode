class StreamChecker:

    def __init__(self, words: List[str]):
        self.words = words
        self.trie = {}
        self.stream = deque()
        self.m = 0
        for i in words:
            self.m = max(self.m, len(i))
            t = len(words)
            k = self.trie
            for j in i[::-1]:
                if j not in k:
                    k[j] = {}
                k = k[j]
                t -= 1
            k['end'] = {}
            
        

    def query(self, letter: str) -> bool:
        self.stream.appendleft(letter)
        if (len(self.stream) > self.m):
            self.stream.pop()
        k = self.trie
        for i in self.stream:
            if "end" in k:
                return True
            if i not in k:
                return False
            k = k[i]
        return 'end' in k
        


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)