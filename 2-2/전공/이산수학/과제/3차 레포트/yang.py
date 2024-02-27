def readFile(fileName):
    L = []
    f = open(fileName, 'r')

    for line in f:
        lines = line.strip().split()
        if lines:
            L.append(tuple(map(int, lines)))
    findRelation(L)

def reflexive(matrix):
    for i in range(6):
        for j in range(6):
            if matrix[i][i] != 1:
                return False
    return True

def transitive(matrix):
    for i in range(6):
        for j in range(6):
            if matrix[i][j] == 1:
                for k in range(6):
                    if matrix[j][k] == 1:
                        if matrix[i][k] != 1:
                            return False
    return True

def symmetric(matrix):
    for i in range(6):
        for j in range(6):
            if matrix[i][j] != matrix[j][i]:
                return False
    return True

def findRelation(L):
    relMatrix = []
    for i in range(6):
        relMatrix.append([0] * 6)

    for row, col in L:
        relMatrix[row - 1][col - 1] = 1

    print(relMatrix)

    print("Reflexive :", reflexive(relMatrix))
    print("Transitive :", transitive(relMatrix))
    print("Symmetric :", symmetric(relMatrix))

    print()


if __name__ == '__main__':
    while True:
        fileName = input("파일 이름을 입력하시오. (end - 프로그램 종료): ")
        if fileName == 'end':
            break

        relMatrix = readFile(fileName)

        if relMatrix is not None:
            findRelation(relMatrix)

