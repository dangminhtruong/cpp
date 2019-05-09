#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//khai bao ham
void SelectionSort(int* a,int n);

//===chuong trinh chinh===
int main()
{
	int a[100];
	int n,i;
	ifstream fin("daysosapxepchon.txt");

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
	SelectionSort(a,n);
	
	//dua day da sap xep ra man hinh
	cout<<"\n\nDay khoa sau khi sap xep la:\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<"  ";

	cout<<endl;
	return 0;
}
//===dinh nghia ham===
void SelectionSort(int* a,int n)
{
	int i,j,k,tg;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[k]) k=j;
		//Doi cho ai va ak
		if(k!=i)
		{
			tg=a[i];
			a[i]=a[k];
			a[k]=tg;
		}
	}
}