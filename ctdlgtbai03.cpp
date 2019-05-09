//Ho ten:
//MaSV:
//Lop:
//De:
#include <iostream>

using namespace std;

//Khai bao hang
#define SIZE 50

//Cai dat cau truc luu tru ngan xep
struct Stack
{
    int T;
    int S[SIZE];
} ST = {-1};

//Khai bao cac ham
void Push(Stack &ST, int x);
int Pop(Stack &ST);
int Empty(Stack ST);

///===chuong trinh chinh===
int main()
{
    int n,thuong;
    
    cout<<"Nhap vao 1 so nguyen duong: ";
    cin>>n;
    
    //Chuyen he 10->he2
    thuong = n;
    while(thuong)
    {
        Push(ST,thuong%2);
        thuong/=2;
    }
    
    cout<<"So nhi phan cua so "<<n<<" la: ";
    while(!Empty(ST)) cout<<Pop(ST);

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void Push(Stack &ST, int x)
{
    //Kiem tra ngan xep day
    if(ST.T==SIZE-1)
    {
        cout<<"Ngan xep da day!";
        return;
    }
    
    //Bo sung x vao ngan xep
    ST.S[++ST.T] = x;
}
//------------------------
int Pop(Stack &ST)
{
    //Kiem tra ngan xep rong
    if(ST.T==-1)
    {
        cout<<"Ngan xep da rong!";
        return -1;
    }
    
    //Loai bo phan tu dinh va tra ve gia tri
    return ST.S[ST.T--];
}
//------------------------
int Empty(Stack ST)
{
    if(ST.T==-1) return 1;
    
    return 0;
}












