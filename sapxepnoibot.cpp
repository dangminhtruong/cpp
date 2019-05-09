//Lop:
//De: Cai dat giai thuat sap xep chen
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

//khai bao ham
void BubbleSort(int *a, int n);

//===chuong trinh chinh===
int main()
{
    int a[100];
    int n, i;
    ifstream fin("daysosapxepsuibot.txt");

    //Doc vao n
    fin >> n;

    //Doc vao day khoa, luu trong mang a
    //va dua ra man hinh
    cout << "Day khoa ban dau la:\n";
    for (i = 0; i < n; i++)
    {
        fin >> a[i];
        cout << a[i] << "  ";
    }

    //sap xep day
    BubbleSort(a, n);

    //dua day da sap xep ra man hinh
    cout << "\n\nDay khoa sau khi sap xep la:\n";
    for (i = 0; i < n; i++)
        cout << a[i] << "  ";

    cout << endl;
    return 0;
}
//===dinh nghia ham===
void BubbleSort(int *a, int n)
{
    int i, j, tg;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                tg = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tg;
            }
        }
}
