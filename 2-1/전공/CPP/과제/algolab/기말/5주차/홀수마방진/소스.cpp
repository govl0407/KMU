/**************************
홀수 마방진 by 20203152최정민 23.05.09
**********************/

#include<iostream>
#include<fstream>
using namespace std;

void cal(const int n)
{
    //초기화
    int arr[49][49];
    int pos_x = n/2;
    int pos_y = 0;
    for (int i = 0; i < 49; i++)
        for (int j = 0; j < 49; j++)
            arr[i][j] = 0;
    arr[pos_y][pos_x] = 1;
    //삽입
    for (int i = 1; i < n * n; i++)
    {
        int origin_pos_x = pos_x++;
        int origin_pos_y = pos_y--; //오른쪽 위로 증가
        if (pos_y < 0)//위로 벗어나면 
            pos_y = n - 1;//맨 밑으로

        if (pos_x > n - 1)//오른쪽으로 벗어나면
            pos_x = 0;//왼쪽으로
        if (arr[pos_y][pos_x] != 0)//이미 차 있으면
        {
            pos_y = origin_pos_y+1; //한칸 아래에 추가
            pos_x = origin_pos_x;
        }
            
        if (pos_y > n-1)//오른쪽으로 벗어나면 
            pos_y = 0;//왼쪽으로
        if (pos_x < 0)//위로 벗어나면 
            pos_x = n-1;//아래로
        arr[pos_y][pos_x] = i + 1;//추가
        /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }*/
    }

    //출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    
}

int main()
{
    ifstream fin;
    fin.open("input.txt");//파일 열기

    int cases;
    fin >> cases; //case 개수 받기

    while(cases--)
    {
        int n;
        fin >> n; //한줄씩 받기

        cal(n);//함수 실행
    }


    return 0;
}