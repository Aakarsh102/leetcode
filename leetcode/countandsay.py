class Solution:
    def countAndSay(self, n: int) -> str:
        if (n == 1):
            return "1"

        final_string = "11"
        new_string = ""
        for i in range(3, n + 1):
            count = 1
            for j in range(0, len(final_string)):
                if (j < len(final_string) - 1) and (final_string[j] == final_string[j + 1]):
                    count += 1
                else:
                    new_string = new_string + f"{count}{final_string[j]}"
                    count = 1
            final_string = new_string
            new_string = ""

        return final_string

        