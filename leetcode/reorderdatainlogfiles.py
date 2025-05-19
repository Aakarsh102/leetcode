class Solution:
    def reorderLogFiles(self, logs: list[str]) -> list[str]:
        logs2 = [i[i.find(" "): ].replace(" ", "") for i in logs]
        store = []
        comb = list(zip(logs, logs2))
        count = 0
        for i in range(len(comb)):
            if (comb[i][1].isalpha()):
                store.append(comb[i][0])
        store.sort()
        store.sort(key = lambda x: x[x.find(" ") + 1 : ])
        for i in comb:
            if (i[1].isdigit()):
                store.append(i[0])

        return store


        