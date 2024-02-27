#행렬 출력
def print_mat(mat):
    for i in range(6):
        for j in range(6):
            print(mat[i][j], " ",end='') # 6*6행렬을 출력 
        print("\n")

def reflection(mat):#반사관계 판별-대각원소가 1인지 검사
    for i in range(6):
        if(mat[i][i]==0):
            return False
    return True

def symmetric(mat):#대칭관계 판별-대각 원소를 기준으로 반대의 원소와 다르면 대칭이 아님
    for i in range(6):
        for j in range(6-i):
            if(mat[i][j]!=mat[j][i]):
                return False
    return True

def mult(mat1,mat2):#행렬의 부울 곱
    tmp=[]
    for i in range(6):
        tm = []
        for j in range(6):
            t=0
            for k in range(6):
                t += mat1[i][k] * mat2[k][j]
            if(t!=0):
                t = 1
            tm.append(t)
        tmp.append(tm)
    return tmp

def transitive(mat):#추이관계 판별 - 거듭제곱이 R에 포함되는지 판별
    mat1 = mat
    for z in range(5):
        mat1 = mult(mat1,mat)#거듭제곱
        for i in range(6):
            for j in range(6):
                if(mat1[i][j]==1):#거듭제곱된 행렬이 R의 부분집합인지 판별
                    if(mat[i][j]==0):
                        return False
    return True


while True:
    # 파일을 열어서 mat에 넣기
    fname = input()#파일명 입력받기
    if (fname == 'end'):#입력이 end면 종료
        print("program end")
        break
    else:
        f = open(fname, 'r')
        mat = []#0으로 채워진 6*6행렬 생성
        for i in range(6):
            tmp = []
            for j in range(6):
                tmp.append(0)
            mat.append(tmp)

        for r in f:#파일의 값으로 6*6행렬 채우기
            mat[int(r[0]) - 1][int(r[2]) - 1] = 1

    #출력
    print_mat(mat)

    #반사관계 판별
    if(reflection(mat)==True):
        print("반사관계")
    else:
        print("반사관계가 아님")

    # 대칭관계 판별
    if (symmetric(mat) == True):
        print("대칭관계")
    else:
        print("대칭관계가 아님")

    # 추이관계 판별
    if (transitive(mat) == True):
        print("추이관계")
    else:
        print("추이관계가 아님")