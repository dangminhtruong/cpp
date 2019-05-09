//Ho ten: 
//MaSV: 
//Lop: 
//De: Bài 10(ctdlgtbai10.cpp). Viết chương trình C/C++ cài đặt cấu trúc dữ liệu hàng đợi sử dụng cấu trúc lưu trữ phân tán
    //với các phép toán sau:
    //1)Bổ sung phần tử dữ liệu x vào hàng đợi (QInsert).
    //2)Loại bỏ phần tử khỏi hàng đợi (QDelete).
    //3)Kiểm tra hàng đợi rỗng (QEmpty).
    //4)Trả về phần tử đầu hàng đợi (Front).
    //5)Trả về phần tử cuối hàng đợi (Rear).
    //Sử dụng hàng đợi cho bài toán: Cho tệp văn bản dayso.txt chứa dãy số nguyên đã sắp xếp tăng dần. Đọc dãy số từ tệp
    //rồi đưa ra màn hình một dòng dãy số chẵn tăng dần, một dòng dãy số lẽ tăng dần.
#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int Infor;
    Node *Link;
} *F = NULL, *R = NULL;

//Khai bao cac ham
void QInsert(Node* &F, Node* &R, int x);
int QDelete(Node* &F, Node* &R);
int QEmpty(Node *F, Node *R);
int Front(Node* F, Node* R);
int Rear(Node* F, Node* R);

//===chuong trinh chinh===
int main()
{
    ifstream fin("daysobai10.txt");
    int n,i,x;
    
    //Doc so phan tu cua day so tu tep
    fin>>n;

    //Doc va dua ra day so ban dau
    for(i=0;i<n;i++)
    {
        fin>>x;
        QInsert(F,R,x);
    }
    cout<<"Day so ban dau la:\n";
    while(!QEmpty(F,R)) cout<<QDelete(F,R)<<"   ";
    
    //Tach thanh dong chan
    fin.seekg(0);
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>x;
        if(x%2==0) QInsert(F,R,x);
    }
    cout<<"\n\nDong so chan tang dan la:\n";
    while(!QEmpty(F,R)) cout<<QDelete(F,R)<<"   ";

    //Tach thanh dong le
    fin.seekg(0);
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>x;
        if(x%2==1) QInsert(F,R,x);
    }
    cout<<"\n\nDong so le tang dan la:\n";
    while(!QEmpty(F,R)) cout<<QDelete(F,R)<<"   ";
     
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void QInsert(Node* &F, Node* &R, int x)
{
    //1. Tao nut moi
    Node *N = new Node;
    N->Infor = x;
    N->Link = NULL;
    
    //2,3. Noi nut moi vao sau R va cho R tro vao nut moi
    if(F==NULL) F = R = N;
    else
    {
        R->Link = N;
        R = N;
    }
}
//----------------------------
int QDelete(Node* &F, Node* &R)
{
    //1. Kiem tra hang doi rong
    if(F==NULL)
    {
        cout<<"Hang doi da rong!";
        return -1;
    }
    
    //2. Giu lai giu lieu va dia chi nut F
    int Tg = F->Infor;
    Node *P = F;
    
    //3. Thay doi F
    if(F==R) F = R = NULL;
    else F = F->Link;
    
    //4. Huy nut va tra ve gia tri
    delete P;
    return Tg;
}
//----------------------------
int QEmpty(Node *F, Node *R)
{
    if(F==NULL) return 1;
    
    return 0;
}
//----------------------------
int Front(Node* F, Node* R)
{
    //1. Kiem tra hang doi rong
    if(F==NULL)
    {
        cout<<"Hang doi da rong!";
        return -1;
    }
    
    //2. Tra ve phan tu dau hang doi
    return F->Infor;
}
//----------------------------
int Rear(Node* F, Node* R)
{
    //1. Kiem tra hang doi rong
    if(F==NULL)
    {
        cout<<"Hang doi da rong!";
        return -1;
    }
    
    //2. Tra ve phan tu cuoi hang doi
    return R->Infor;
}










                