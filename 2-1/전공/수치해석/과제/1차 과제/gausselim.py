#문제에서 주어진 연립방정식의 행렬
A = [[1,1,2],[2,4,-3],[3,6,-5]]
B = [[9],[1],[0]]

#가우스 소거 함수
def gauss_el(a,b):
    leng = len(b)
    ans = [0]*leng
    for i in range(0,leng-1):
        for j in range(i+1,leng):
            pivot = a[j][i]/a[i][i]#pivot을 찾고 뺄 계수를 구함
            b[j][0]=b[j][0]-b[i][0]*pivot
            for k in range(0,leng):
                a[j][k] = a[j][k]-a[i][k]*pivot#상삼각행렬을 만드는 과정

    print("상삼각행렬")
    U = a #계산으로 나온 상 삼각행렬을 U에 저장
    for i in range(leng):
        print(U[i])  # 상 삼각행렬 출력
    print("\n")

    #대입 시작

    ##우선 계수를 다 1로 초기화
    for i in range(0,leng):
        coe = a[i][i]
        b[i][0] = b[i][0]/coe
        for j in range(i,leng):
            a[i][j] = a[i][j]/coe
    print("계수 1")
    for i in range(leng):
        print(str(a[i]) + str(b[i][0]))
    print("\n")#계수를1로 초기화한 행렬을 출력

    ##소거 시작
    for m in range(leng-1, 0, -1):
        for j in range(m-1,-1,-1):
            pivot = a[j][m]/a[m][m]
            a[j][m] = 0
            b[j][0]= b[j][0]-b[m][0]*pivot

    #출력
    print("소거된 행렬")
    for i in range(leng):
        print(str(a[i])+str(b[i][0]))
    print("\n")#가우스 소거가 끝난 행렬을 출력

    print("해")
    print(b)
    #상삼각행렬 U와 해의 리스트 b를 리턴
    return U,b


gauss_el(A,B)


