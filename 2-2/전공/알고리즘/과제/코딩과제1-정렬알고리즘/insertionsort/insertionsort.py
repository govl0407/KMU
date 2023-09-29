import sys
def insertionSort(A,m):
    swap_cnt = 0
    compare_cnt = 0
    for i in range(1,n-1):
        tmp = A[i]
        for j in range(i,0,-1):
            compare_cnt+=1
            if(A[j-1]>tmp):
                swap_cnt+=1
                A[j]= A[j-1]
            else: break
        A[j] = tmp

    print(A)
    print(compare_cnt, " ", swap_cnt)

n = int(sys.stdin.readline())

for i in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    m = arr[0]
    arr = arr[1:]
    insertionSort(arr, m)
