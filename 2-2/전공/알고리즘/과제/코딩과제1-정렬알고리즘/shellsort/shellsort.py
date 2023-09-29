import sys
def ShellSort(A , n):
    shrinkRatio = 2
    gap = int(n / shrinkRatio)
    compare_cnt=0
    swap_cnt=0
    while( gap > 0 ):
        i = gap
        while(i < n):
            tmp = A[i]
            j = i
            while(True):
                if(j < gap):
                    break
                compare_cnt+=1
                if(A[j - gap] > tmp):
                    swap_cnt+=1
                    A [j] = A[j - gap]
                    j -= gap
                else :
                    break
            A [j] = tmp
            i += 1

        gap /= shrinkRatio
        gap = int(gap)
    print(compare_cnt, " ", swap_cnt)

n = int(sys.stdin.readline())

for i in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    m = arr[0]
    arr = arr[1:]
    ShellSort(arr, m)
