//Lop:
//De: Cai dat giai thuat sap xep chen
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//khai bao ham
void InsertSort(int *a,int n);

//===chuong trinh chinh===
int main()
{
	int a[100];
	int n,i;
	ifstream fin("daysosapxepchen.txt");

	//Doc vao n
	fin>>n;
	
	//Doc vao day khoa, luu trong mang a
	//va dua ra man hinh
	cout<<"Day khoa ban dau la:\n";
	for(i=0;i<n;i++)
	{
		fin>>a[i];
		cout<<a[i]<<"  ";
	}
 
	//sap xep day
	InsertSort(a,n);
	
	//dua day da sap xep ra man hinh
	cout<<"\n\nDay khoa sau khi sap xep la:\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<"  ";

	cout<<endl;
	return 0;
}
//===dinh nghia ham===
void InsertSort(int *a,int n)
{
	int tg,i,j;
	
	for(i=1;i<n;i++)
	{
		tg = a[i];
		j = i-1;
		while(tg<a[j] && j > -1)
		{
			a[j+1] = a[j--];
		}
		a[j+1] = tg;
	}
}