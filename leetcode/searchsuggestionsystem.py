class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        res = []
        for i in range(1, len(searchWord) + 1):
            res.append(self.find_lower(products, searchWord[:i]))
        return res

    def find_lower(self, products, word):
        l = 0
        r = len(products)
        n = len(word)
        while l < r:
            mid = l + (r - l) // 2
            if products[mid][:n] >= word:
                r = mid
            else:
                l = mid + 1
        count = 0
        r = len(products)
        k = []
        while (count < 3 and l < r) :
            if (products[l][:n] == word):
                k.append(products[l])
            l += 1
            count += 1
        return k
        