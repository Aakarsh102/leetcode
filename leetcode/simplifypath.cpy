class Solution:
    def simplifyPath(self, path: str) -> str:
        if path == "/":
            return path;
        l = path.split("/")
        stack = []
        for i in l:
            if i != "":
                stack.append(i)
        ignore_count = 0
        final_str = []
        while (len(stack) != 0):
            s = stack.pop()
            if s == "..":
                ignore_count += 1
            elif s == ".":
                continue
            else:
                if ignore_count != 0:
                    ignore_count -= 1
                    while ignore_count != 0:
                        if not stack:
                            break
                        thing = stack.pop()
                        if (thing == '.'):
                            continue
                        if (thing == ".."):
                            ignore_count += 1
                            continue
                        
                        ignore_count -= 1
                        
                else:
                    final_str.append(s)

        if (not final_str):
            return "/"
        final_str.reverse()

        return "/" + "/".join(final_str)
                

                