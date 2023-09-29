import sys
def bubbleSort(A,m):
    arr = A.copy()
    swap_cnt = 0
    compare_cnt = 0
    for p in range(1,m):
        for i in range(1,m-p+1):
            compare_cnt+=1
            if(arr[i-1]>arr[i]):
                k = arr[i-1]
                arr[i-1] = arr[i]
                arr[i]=k
                swap_cnt+=1

    return[compare_cnt, swap_cnt]

def bubbleSort_imp1(A, m):
    arr = A.copy()
    swap_cnt = 0
    compare_cnt = 0
    for p in range(1,m):
        swapped = False
        for i in range(1,m-p+1):
            compare_cnt+=1
            if(arr[i-1]>arr[i]):
                k = arr[i-1]
                arr[i-1] = arr[i]
                arr[i]=k
                swapped= True
                swap_cnt+=1
        if(swapped == False):
            break;
    return[compare_cnt, swap_cnt]

def bubbleSort_imp2(A , m):
    arr = A.copy()
    swap_cnt = 0
    compare_cnt = 0
    lastswappedpos = m
    while(lastswappedpos > 0):
        swappedpos = 0
        for i in range(1,lastswappedpos):
            compare_cnt+=1
            if(arr[i-1]>arr[i]):
                k = arr[i-1]
                arr[i-1] = arr[i]
                arr[i]=k
                swappedpos = i
                swap_cnt+=1
        lastswappedpos = swappedpos
    return[compare_cnt, swap_cnt]






n = int(sys.stdin.readline())

for i in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    m = arr[0]
    arr = arr[1:]
    A = bubbleSort(arr, m)
    B = bubbleSort_imp1(arr, m)
    C = bubbleSort_imp2(arr, m)
    print(A[0]," ",A[1]," ",B[0]," ", B[1]," ",C[0]," ",C[1])
