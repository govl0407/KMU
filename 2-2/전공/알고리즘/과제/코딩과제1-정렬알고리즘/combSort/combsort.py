import sys
def combSort(A,m):
    swap_cnt = 0
    compare_cnt = 0
    gap = m
    shrink = 1.3
    sorted = False
    while(sorted==False):
        gap = int(gap/shrink)
        if(gap<=1):
            gap = 1
            sorted = True
        i = 0
        while(i+gap< m):
            compare_cnt+=1
            if(A[i]>A[i+gap]):
                swap_cnt+=1
                k = A[i]
                A[i] = A[i+gap]
                A[i+gap] = k
                sorted= False
            i +=1

    print(compare_cnt, " ", swap_cnt)

n = int(sys.stdin.readline())

for i in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    m = arr[0]
    arr = arr[1:]
    combSort(arr, m)
