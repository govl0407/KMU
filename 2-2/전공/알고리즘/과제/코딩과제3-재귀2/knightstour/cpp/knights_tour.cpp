/***********************
20203152 √÷¡§πŒ knighs tour 10/04
***********************************/
#include<iostream>
#define swap(a, b) {char t = a; a = b; b = t;}
using namespace std;

#define MARK 1
#define UNMARK 0
#define MAXSIZE 9
struct point { int x, y; };
point direction[8] = { {1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2} };
int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

int knight_tour(int m, int n, point pos, int counter)
{
    int i;
    point next;
    if (counter == m * n)
        return 1;

    for (i = 0; i < 8; i++)
    {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;
        if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m && board[next.y][next.x] != MARK)
        {
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = counter + 1;
            if (knight_tour(m, n, next, counter + 1))
                return 1;
            board[next.y][next.x] = UNMARK;
        }
    }
    return 0;
}
void print_tour(int m, int n)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << path[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int i, j, m, n;
        point start;
        cin >> m >> n >> start.y >> start.x ;
        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                board[i][j] = UNMARK;
        board[start.y][start.x] = MARK;
        path[start.y][start.x] = 1;
        if (knight_tour(m, n, start, 1))
        {
            cout << 1 << "\n";
            print_tour(m, n);
        }
        else
            cout << 0 << "\n";

    }
    return 0;
}
