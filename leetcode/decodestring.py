class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        final_str = ""
        i = 0
        while i < len(s):
            if s[i].isdigit():
                k = 0
                while s[i].isdigit():
                    k = k * 10 + int(s[i])
                    i += 1
                stack.append(str(k))
                continue
            if s[i] == ']':
                k = stack.pop()
                t = ""
                while stack and k != '[':
                    t += k
                    k = stack.pop()

                p = 0
                k = 0
                print(stack)
                while stack and stack[-1].isdigit():
                    k += int(stack.pop()) * 10 ** p
                    p+=1
                print(k)
                t = t[::-1] * k
                stack.extend([i for i in t])
                i += 1
                continue
                
            stack.append(s[i])
            i += 1

        return "".join(stack)