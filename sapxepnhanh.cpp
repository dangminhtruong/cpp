//Lop:
//De: Cai dat giai thuat sap xep chen
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//khai bao ham
void QuickSort(int *a,int left,int right);

int main()
{
	int *a;
	int n,i;
	ifstream fin("daysosapxepnhanh.txt");

	//Doc vao n
	fin>>n;
	
	//Tao mang dong a chua n khoa
	a = new int[n];
	
	//Doc vao day khoa, luu trong mang a
	//va dua ra man hinh
	cout<<"Day khoa ban dau la:\n";
	for(i=0;i<n;i++)
	{
		fin>>a[i];
		cout<<a[i]<<"  ";
	}

	//sap xep day
	QuickSort(a,0,n-1);
	
	//dua day da sap xep ra man hinh
	cout<<"\n\nDay khoa sau khi sap xep la:\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<"  ";

	cout<<endl;
	return 0;
}
//===dinh nghia ham===
void QuickSort(int *a,int left,int right)
{
        int tg;
        int i=left;
        int j=right;
        int x=a[(i+j)/2];
        while(i<=j)
        {
	        while(a[i]<x)
	                i++;
	        while(a[j]>x)
	                j--;
	        if(i<=j)
	        {
	                tg=a[i];
	                a[i]=a[j];
	                a[j]=tg;
	                i++;
	                j--;
	        }
	    }
        if(left<j)
			QuickSort(a,left,j);
		if(i<right)
			QuickSort(a,i,right);
}