//Ho ten: 
//MaSV: 
//Lop:
//De: (ctdlgtbai07.cpp). Viết chương trình C/C++ cài đặt cấu trúc dữ liệu danh sách liên kết đơn
    //với các phép toán:
    //1)Bổ sung phần tử dữ liệu x vào sau nút M trong danh sách
    //2)Bổ sung phần tử dữ liệu x vào trước nút M trong danh sách
    //3)Loại bỏ nút M khỏi danh sách, trả về phần tử dữ liệu trong nút M.
    //4)Duyệt và đưa ra các phần tử dữ liệu trong danh sách.
    //5Sử dụng danh sách liên kết đơn trên để chứa một dãy số nguyên nhập vào từ bàn phím. Đưa dãy số nguyên trong
    //danh sách ra màn hình. Xóa một phần tử có giá trị bằng x.
#include <iostream>

using namespace std;

//Cai dat cau truc Nut
struct Node
{
    int Infor;
    Node *Link;
} *F = NULL;

//Khai bao cac ham
void PostInsert(Node* &F, Node* M, int x);
void PreInsert(Node* &F, Node* M, int x);
int Delete(Node* &F, Node* M);
void Display(Node *F);
int DeleteX(Node* &F, int x);

//===chuong trinh chinh===
int main()
{
    int n, i, x;
    
    cout<<"Nhap so luong phan tu cua day so: ";
    cin>>n;
    
    cout<<"Nhap vao day so:\n";
    for(i=0;i<n;i++)
    {
        cout<<"\tNhap so thu "<<i+1<<": ";
        cin>>x;
        PreInsert(F,F,x);
    }
    
    cout<<"\nDay so da nhap la:\n";
    Display(F);
    
    cout<<"Nhap vao so can xoa: ";
    cin>>x;
    
    if(DeleteX(F,x)==1)
    {
        cout<<"Xoa thanh cong!\nDay so sau khi xoa la:\n";
        Display(F);
    }
    else
        cout<<"Khong tim thay so can xoa trong danh sach!";

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void PostInsert(Node* &F, Node* M, int x)
{
    //1. Tao nut moi
    Node *N = new Node;
    N->Infor = x;
    N->Link = NULL;
    
    //2.Bo xung x vao sau M
    if(F==NULL) F=N;
    else
    {
        N->Link = M->Link;
        M->Link = N;
    }
}
//------------------------
void PreInsert(Node* &F, Node* M, int x)
{
    //1. Tao nut moi
    Node *N = new Node;
    N->Infor = x;
    N->Link = NULL;
    
    //2. Truong hop danh sach rong
    if(F==NULL) 
    {
        F=N;
        return;
    }
    
    //3. Truong hop M la nut dau
    if(M==F)
    {
        N->Link = M;
        F = N;
        return;
    }
    
    //4.Truong hop con lai
    Node *P = F;
    //Cho P tro toi truoc M
    while(P->Link != M) P = P->Link;
        
    //Thay doi lien ket
    P->Link = N;
    N->Link = M;
}
//------------------------
int Delete(Node* &F, Node* M)
{
    //1. TH Danh sach rong
    if(F==NULL)
    {
        cout<<"Danh sach da rong!";
        return -1;
    }
    
    //2.Giu lai phan tu loai bo
    int Tg = M->Infor;
    
    //3.Thay doi lien ket
    if(F==M) F = F->Link;
    else
    {
        Node *P = F;
        while(P->Link != M) P=P->Link;
        P->Link = M->Link;
    }
    
    //4. Huy nut M
    delete M;
    
    //5. Tra ve phan tu bi loai bo
    return Tg;
}
//------------------------
void Display(Node *F)
{
    while(F)
    {
        cout<<F->Infor<<"  ";
        F = F->Link;
    }
}
//------------------------
int DeleteX(Node* &F, int x)
{
    //Kiem tra rong
    if(F==NULL)
    {
        cout<<"Danh sach da rong!";
        return -1;
    }
    
    Node *P = F, *Q = F;
    while(P)
    {
        if(P->Infor == x)
        {
            if(P==F) F=F->Link;
            else Q->Link = P->Link;
            
            delete P;
            return 1;
        }
        else 
        {
            Q = P;//Giu lai Q = P de Q luon tro toi truoc P
            P=P->Link;//Cho P tro sang nut tiep theo
        }
    }
    
    return 0;    
}
//------------------------







            