import sys
def selectionSort(A,m):
    swap_cnt = 0
    compare_cnt = 0
    for i in range(0,n-2):
        jmin = i
        for j in range(i+1,n-1):
            if(A[j]<A[jmin]):
                jmin = j
        compare_cnt+=1
        if(jmin != i):
            k = A[jmin]
            A[jmin] = A[j]
            A[j] = k
            swap_cnt+=1
    print(A)
    print(compare_cnt, " ", swap_cnt)

n = int(sys.stdin.readline())

for i in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    m = arr[0]
    arr = arr[1:]
    selectionSort(arr, m)
