n = 8
A = [8, 7, 6, 5, 4, 3, 2, 1]
def ShellSort( A ):
    shrinkRatio = 2
    gap = int(n / shrinkRatio)
    while( gap > 0 ):
        i = gap
        while(i < n):
            tmp = A[i]
            j = i
            while((j >= gap)and(A[j - gap] > tmp)):
                A [j] = A[j - gap]
                j -= gap
            A [j] = tmp
            i += 1

        gap /= shrinkRatio
        gap = int(gap)
ShellSort(A)
print(A)
