import sys
import heapq
input = sys.stdin.readline


def find(x) :
    if nodes[x] != x :
        new_x = find(nodes[x])
        nodes[x] = new_x
        return nodes[x]
        return x

        def union(a, b) :
        a = find(a)
        b = find(b)

        if a > b :
nodes[a] = b
        else:
nodes[b] = a

T = int(input())

for _ in range(T) :
    node = int(input())
    nodes = [i for i in range(node + 1)]
    h = []
    for i in range(node) :
        l = list(map(int, input().split()))
        for j in range(1, l[1] + 1) :
            heapq.heappush(h, (l[2 * j + 1], l[0], l[2 * j]))
            cnt = 0
            while h :
                w, x, y = heapq.heappop(h)
                x = find(x)
                y = find(y)
                if x != y :
                    cnt += w
                    union(x, y)

                    print(cnt)