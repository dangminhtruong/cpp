//Ho ten: 
//MaSV: 
//Lop: 
//De: Bài 09(ctdlgtbai09.cpp). Viết chương trình C/C++ cài đặt cấu trúc dữ liệu ngăn xếp sử dụng cấu trúc lưu trữ phân tán
    //với các phép toán sau:
    //1)Bổ sung phần tử dữ liệu x vào ngăn xếp (Push).
    //2)Loại bỏ phần tử khỏi ngăn xếp (Pop).
    //3)Kiểm tra ngăn xếp rỗng (Empty).
    //4)Trả về phần tử đỉnh ngăn xếp (Top).
    //5)Trả về số phần tử của ngăn xếp (Count).
    //Sử dụng ngăn xếp cho bài toán: Nhập vào một số nguyên dương có nhiều chữ số, đưa ra màn hình từng chữ số
    //của số nguyên đó, các chữ số từ trái sang phải, mỗi số trên một dòng.
#include <iostream>

using namespace std;

struct Node
{
    int Infor;
    Node *Link;
} *T = NULL;

//Khai bac cac ham
void Push(Node* &T, int x);
int Pop(Node* &T);
int Empty(Node *T);
int Top(Node *T);
int Count(Node *T);

//===chuong trinh chinh===
int main()
{
    int n,thuong;
    
    cout<<"Nhap vao 1 so nguyen duong: ";
    cin>>n;
    
    thuong = n;
    while(thuong)
    {
        Push(T,thuong%10);
        thuong/=10;
    }
    
    cout<<"So chu so cua so "<<n<<" la: "<<Count(T);
    
    cout<<"\nCac chu so cua so "<<n<<" la:\n";
    while(!Empty(T)) cout<<Pop(T)<<endl;
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void Push(Node* &T, int x)
{
    //1. Tao nut moi
    Node *N = new Node;
    N->Infor = x;
    N->Link = NULL;
    
    //2. Noi nut moi vao truoc T
    N->Link = T;
    
    //3. Cho T tro vao nut moi
    T = N;
}
//---------------------
int Pop(Node* &T)
{
    //1. Kiem tra ngan xep rong
    if(T==NULL)
    {
        cout<<"Ngan xep da rong!";
        return -1;
    }
    
    //2. Giu lai gia tri va dia chi cua nut dinh
    int Tg = T->Infor;
    Node *P = T;
    
    //3. Thay doi T
    T = T->Link;
    
    //4. Huy nut va tra ve
    delete P;
    return Tg;
}
//---------------------
int Empty(Node *T)
{
    if(T==NULL) return 1;
    
    return 0;
}
//---------------------
int Top(Node *T)
{
    //1. Kiem tra ngan xep rong
    if(T==NULL)
    {
        cout<<"Ngan xep da rong!";
        return -1;
    }
    
    //2. Tra ve gia tri nut dinh
    return T->Infor;
}
//---------------------
int Count(Node *T)
{
    int dem = 0;
    
    while(T)
    {
        dem++;
        T = T->Link;
    }
    
    return dem;
}


















                