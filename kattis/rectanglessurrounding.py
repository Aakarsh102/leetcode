

def check_in(l, x, y):
    for i in l:
        if i[0][0]<= x < i[1][0] and i[0][1] <= y < i[1][1]:
            return True
    return False
while ((n := int(input())) != 0):
    counter = 0
    l = []
    for i in range(n):
        line = input()
        corners = [int(i) for i in line.split(" ")]
        l.append([(corners[0], corners[1]), (corners[2], corners[3])])
        
    for i in range(501):
        for j in range(501):
            if (check_in(l, i, j)):
                counter += 1
    print(counter)