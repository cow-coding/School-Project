

def makeMatrix():
    row = int(input("행의 수 입력 : "))
    col = int(input("열의 수 입력 : "))
    print()

    mat = list()
    for i in range(0, row):
        tmp = list()
        tmp = input(str(i+1)+'행의 값을 입력하세요(예, 1 2 3) : \n')
        tmp = list(map(int, tmp.split(' ')))
        mat.append(tmp)

    return mat

def printMatrix(matrix):
    for i in matrix:
        for item in i:
            print(item,' ', end='')
        print()


def makeUpper(matrix):
    tmp = matrix

    for i in range(0,len(tmp)):
        # i행을 기준으로 연산
        start = tmp[i]
        frontNum = tmp[i][i]

        for j in range(i + 1, len(tmp)):
            # i행 이후 연산시작
            front = tmp[j][i]

            if front == 0 : continue

            for k in range(0, len(tmp[j])):
                tmp[j][k] = tmp[j][k] / front * frontNum
                tmp[j][k] = start[k] - tmp[j][k]

    matrix = tmp
    return matrix

if __name__ == '__main__':
    matrix = makeMatrix()
    print()
    printMatrix(matrix)

    print('\nupper 변경 후\n')

    matrix = makeUpper(matrix)
    printMatrix(matrix)