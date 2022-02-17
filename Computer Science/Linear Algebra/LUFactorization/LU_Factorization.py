

def makeMatrix():
    matrix = list()
    row = input("행렬의 행 수를 입력하세요 : ")
    col = input("행렬의 열 수를 입력하세요 : ")

    for i in range(0, int(row)):
        tmp = list()
        tmp = input(str(i+1)+"번째 행의 값을 입력하세요. (예 : 1 2 3)\n")
        tmp = list(map(int, tmp.split(' ')))
        matrix.append(tmp)

    return matrix

def printMat(matrix):
    for i in matrix:
        for item in i:
            print(item, ' ', end='')
        print()

def initElem(row, col):
    mat = list()

    for i in range(0, row):
        tmp = list()
        for j in range(0, col):
            if i == j:
                tmp.append(1)
            else:
                tmp.append(0)
        mat.append(tmp)

    return mat

def matrixProduct(mat1, mat2):
    ret = initElem(len(mat1), len(mat2[0]))
    tmp1 = list() # mat2 col data change
    tmp2 = list() # row data save

    for i in range(0, len(mat1)):
        # mat1의 i행일 때
        tmp1 = list()

        for j in range(0, len(mat2[0])):
            dat = 0
            for k in range(0, len(mat2)):
               dat += mat1[i][k] * mat2[k][j]
            ret[i][j] = dat

    return ret

def LUFactorization(matrix):
    mat = matrix
    row = len(matrix)
    col = len(matrix[0])

    ret = initElem(row, col) # return용

    for i in range(0, row):
        elem = initElem(row, col)  # 연산용
        tmp = initElem(row, col)
        for j in range(0, col):
            if i == 0 and j == 0:
                tmp[i][j] = mat[i][j]
                elem[i][j] = 1/mat[i][j]
                ret = matrixProduct(ret, tmp)
                mat = matrixProduct(elem, mat)
                break

            if mat[i][0] != 0:
                tmp[i][j] = mat[i][j]
                elem[i][0] = -mat[i][0]
                ret = matrixProduct(ret, tmp)
                mat = matrixProduct(elem, mat)
                break

    printLU(matrix, ret, mat)

def printLU(origin, Lmat, Umat):
    for i in range(0, len(origin)):
        for j in range(0, len(origin)*len(origin)+2):
            if i == int(len(origin)/2):
                if j < len(origin):
                    print(origin[i][j],' ', end='')
                elif j >= len(origin) and j < len(origin) + 1:
                    print(' =  ', end='')
                elif j >= len(origin) + 1 and j < 2 * len(origin) + 1:
                    print(Lmat[i][(j-1)%len(origin)],' ', end='')
                elif j >= 2 * len(origin) + 1 and j < 2 * len(origin) + 2:
                    print(' *  ', end='')
                elif j >= 2 * len(origin) + 2:
                    print(Umat[i][(j-2)%len(origin)],' ', end='')
            else:
                if j < len(origin):
                    print(origin[i][j],' ', end='')
                elif j >= len(origin) and j < len(origin) + 1:
                    print('    ', end='')
                elif j >= len(origin) + 1 and j < 2 * len(origin) + 1:
                    print(Lmat[i][(j - 1) % len(origin)],' ', end='')
                elif j >= 2 * len(origin) + 1 and j < 2 * len(origin) + 2:
                    print('    ', end='')
                elif j >= 2 * len(origin) + 2:
                    print(Umat[i][(j - 2) % len(origin)],' ', end='')



        print()

if __name__ == '__main__':
    mat1 = makeMatrix()
    LUFactorization(mat1)