//Ho ten: 
//MaSV:
//Lop: 
//De: bai04
#include <iostream>

using namespace std;

//Khai bao hang
#define SIZE 50

//Khai bao cau truc luu tru ngan xep bang mang
struct Stack
{
    int T;
    char S[SIZE];
} ST = {-1};

//Khai bao cac ham
void Push(Stack &ST, char x);
char Pop(Stack &ST);
int Empty(Stack ST);

//===chuong trinh chinh===
int main()
{
    int n,thuong;
    char ChuSoHex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    //Nhap n
    cout<<"Nhap vao 1 so nguyen duong: ";
    cin>>n;
    
    //Chuyen he 10 -> he 16
    thuong = n;
    while(thuong)
    {
        Push(ST,ChuSoHex[thuong%16]);
        thuong/=16;
    }
    
    cout<<"So hex tuong ung cua so "<<n<<" la: ";
    while(!Empty(ST)) cout<<Pop(ST);

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void Push(Stack &ST, char x)
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
//----------------------
char Pop(Stack &ST)
{
    //KIem tra ngan xep rong
    if(ST.T==-1)
    {
        cout<<"Ngan xep da rong!";
        return -1;
    }
    
    //Tra ve phan tu loai bo
    return ST.S[ST.T--];
}
//----------------------
int Empty(Stack ST)
{
    if(ST.T==-1) return 1;
    
    return 0;
}













