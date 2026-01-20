
n = 0
# This is to know if we're in the first line 
# since we only print newline char if we're not
first=True
while ((n := int(input())) != 0):
    # print newline char for images after the first
    if not first:
        print()
    first = False
    line_sum = -1
    isErr = False
    for i in range(n):
        line = input()
        # This splits the input str on the " "
        # to get individual values
        elements = list(line.split(" "))
        # converts the str to int in the list 
        for i in range(1 , len(elements)):
            elements[i] = int(elements[i])

        if (line_sum == -1):
            line_sum = sum(elements[1:])
        # setting error flag if elements all lines don't have the same sum
        if (line_sum != sum(elements[1:])):
            isErr = True
        val = elements[0]
        final_str = ""
        # building then printing the final string
        for i in elements[1:]:
            final_str += val * i
            if val == '#':
                val = '.'
            else:
                val = '#'
        print(final_str)
    if (isErr):
        print("Error decoding image")
    
