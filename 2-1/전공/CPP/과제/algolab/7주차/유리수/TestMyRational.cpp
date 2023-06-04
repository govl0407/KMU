/***************************
유리수 by 20203152 최정민 23.05.24
****************************/
#include <fstream> 
#include <cstdlib> 
#include "MyRational.h" 
using namespace std;
void testSimpleCase();
void testDataFromFile();
int main()
{
    testSimpleCase();
    testDataFromFile();
    return 0;
}
void testSimpleCase()
{
    myRational frac(2, 3);
    cout << frac << frac++ << frac << ++frac <<endl;
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " "
        << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
    // Check arithmetic operators 
    cout << frac1 * frac2 << " "
        << frac1 + frac3 << " "
        << frac2 - frac1 << " "
        << frac3 / frac2 << endl;
    // Check comparison operators
    cout << ((frac1 < frac2) ? 1 : 0) << " "
        << ((frac1 <= frac2) ? 1 : 0) << " "
        << ((frac1 > frac2) ? 1 : 0) << " "
        << ((frac1 >= frac2) ? 1 : 0) << " "
        << ((frac1 == frac2) ? 1 : 0) << " "
        << ((frac1 != frac2) ? 1 : 0) << " "
        << ((frac2 < frac3) ? 1 : 0) << " "
        << ((frac2 <= frac3) ? 1 : 0) << " "
        << ((frac2 > frac3) ? 1 : 0) << " "
        << ((frac2 >= frac3) ? 1 : 0) << " "
        << ((frac2 == frac3) ? 1 : 0) << " "
        << ((frac2 != frac3) ? 1 : 0) << endl;
    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;
    cout << -frac6 << endl;
    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    cout << 2 * frac3 << " " << frac3 * 2 << " "
        << 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile()
{
    ifstream inStream;
    int numTestCases;
    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }

    inStream >> numTestCases;
    while (numTestCases--)
    {
        myRational rat[100];
        int cases;
        inStream >> cases;
        for(int i = 0; i < cases; i++)
        {
            long a, b;
            inStream >> a >> b;
            rat[i] = myRational(a, b);
        }
        myRational result[100];
        myRational min;// 임시 최솟값
        int key = 0;//rat에서 최솟값의 위치
        for (int i = 0; i < cases; i++)
        {
            for (int j = 0; j < cases; j++)
            {
                if (rat[j] != myRational(NULL,NULL))
                {
                    min = rat[j];//임시 최솟값 초기값
                    key = j;
                }
            }
            for (int h = 0; h < cases; h++)
            {
                if(rat[h]== myRational(NULL, NULL)){}
                else if (rat[h] < min)
                {
                    min = rat[h];
                    key = h;
                }
            }
            result[i] = min;
            rat[key] = myRational(NULL, NULL);
        }
        for(int i=0;i<cases;i++)
        {
            cout << result[i] <<" ";
        }
        cout << endl;
    }
}