//Ho ten: 
//MaSV: 
//Lop: 
//De:(ctdlgtbai08.cpp). Viết chương trình C/C++ cài đặt cấu trúc dữ liệu danh sách liên kết kép
    //với các phép toán:
    //1)Bổ sung phần tử dữ liệu x vào sau nút M trong danh sách.
    //2)Bổ sung phần tử dữ liệu x vào trước nút M trong danh sách.
    //3)Bổ sung phần tử dữ liệu x vào cuối danh sách.
    //4)Loại bỏ nút M khỏi danh sách, trả về phần tử dữ liệu trong nút M.
    //5)Loại bỏ một phần tử trong danh sách có giá trị bằng x.
    //6)Hủy cả danh sách.
    //7)Duyệt và đưa ra các phần tử dữ liệu trong danh sách.
    //Sử dụng danh sách liên kết kép trên để chứa một dãy số nguyên nhập vào từ bàn phím. Đưa dãy số nguyên trong
    //danh sách ra màn hình theo đúng thứ tự đã nhập. Xóa một phần tử có giá trị bằng x.
#include <iostream>
#include <fstream>

using namespace std;

//Cat dat cau truc du lieu danh sach lien ket kep
struct Node
{
    int Infor;
    Node *LPTR, *RPTR;
} *L = NULL, *R = NULL;

//Khai bao cac ham
void PostInsert(Node* &L, Node* &R, Node* M, int x); // ý 1
void PreInsert(Node* &L, Node* &R, Node* M, int x); // ý 2
void LastInsert(Node* &L, Node* &R, int x); //ý 3
int Delete(Node* &L, Node* &R, Node* M); // ý 4
int DeleteX(Node* &L, Node* &R, int x); // ý 5
void DeleteAll(Node* &L, Node* &R); // ý 6
void Display(Node *L, Node *R); // ý 7

//===chuong trinh chinh===
int main()
{
    /*
    int n,i,x;
    
    cout<<"Nhap so luong phan tu cua day so: ";
    cin>>n;
    
    cout<<"Nhap vao day so:\n";
    for(i=0;i<n;i++)
    {
        cout<<"\tNhap so thu "<<i+1<<": ";
        cin>>x;
        //Them vao cuoi danh sach
        LastInsert(L,R,x);
    }
    
    cout<<"\nDay so da nhap theo dung thu tu la:\n";
    Display(L,R);
    
    cout<<"\n\nNhap so can xoa: ";
    cin>>x;
    if(DeleteX(L,R,x)==1)
    {
        cout<<"Xoa thanh cong!\nDay so sau khi xoa "<<x<<" la:\n";
        Display(L,R);    
    }
    else
        cout<<"Khong tim thay phan tu can xoa!";
    */
    ifstream fin("dayso.txt");
    int n,i,x;
    
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>x;
        LastInsert(L,R,x);
    }
    
    cout<<"Day so trong tep la:\n";
    Display(L,R);
    
    cout<<"\nNhap so can xoa: ";
    cin>>x;
    if(DeleteX(L,R,x)==1)
    {
        cout<<"Xoa thanh cong!\nDay so sau khi xoa "<<x<<" la:\n";
        Display(L,R);
    }
    else
        cout<<"Khong tim thay phan tu can xoa!";
    
    //Xoa nut dau cua danh sach
    Delete(L,R,L);
    cout<<"\nDay sau khi xoa nut dau la:\n";
    Display(L,R);
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void PostInsert(Node* &L, Node* &R, Node* M, int x)
{
    //1. Tao nut moi
    Node *N = new Node;
    N->Infor = x;
    N->LPTR = N->RPTR = NULL;
    
    //2. T/H Danh sach rong
    if(L==NULL)
    {
        L=R=N;
        return;
    }
    //3. T/H M la nut cuc phai
    if(R==M)
    {
        M->RPTR = N;
        N->LPTR = M;
        R=N;
        return;
    }
    //4. T/H con lai
    N->RPTR = M->RPTR;
    N->RPTR->LPTR = N;
    N->LPTR = M;
    M->RPTR = N;    
}
//-----------------------------
void PreInsert(Node* &L, Node* &R, Node* M, int x)
{
    //1. Tao nut moi
    Node *N = new Node;
    N->Infor = x;
    N->LPTR = N->RPTR = NULL;
    
    //2. T/H Danh sach rong
    if(L==NULL)
    {
        L = R = N;
        return;
    }
    
    //3. T/H M la nut cuc trai
    if(L==M)
    {
        N->RPTR = M;
        M->LPTR = N;
        L=N;
        return;
    }
    
    //4. T/H con lai
    N->LPTR = M->LPTR;
    N->RPTR = M;
    M->LPTR->RPTR = N;
    M->LPTR = N;
}
//-----------------------------
void LastInsert(Node* &L, Node* &R, int x)
{
    //1. Tao nut moi
    Node *N = new Node;
    N->Infor = x;
    N->LPTR = N->RPTR = NULL;
    
    //2. T/H Danh sach sach rong
    if(L==NULL)
    {
        L=R=N;
        return;
    }
    
    //3. T/H con lai
    R->RPTR = N;
    N->LPTR = R;
    R=N;
}
//-----------------------------
int Delete(Node* &L, Node* &R, Node* M)
{
    //1. Kiem tra danh sach rong
    if(L==NULL)
    {
        cout<<"Danh sach da rong!";
        return -1;
    }
    
    //2. Giu lai gia tri nut bi loai bo
    int Tg = M->Infor;
    
    //3. Thay doi lien ket
    if(M==L && L==R) L = R = NULL;
    else if(L==M)
    {
        L = L->RPTR;
        L->LPTR = NULL;
    }
    else if(R==M)
    {
        R = R->LPTR;
        R->RPTR = NULL;
    }
    else
    {
        M->LPTR->RPTR = M->RPTR;
        M->RPTR->LPTR = M->LPTR;
    }
    
    //4.Huy nut M
    delete M;
    
    //5. Tra ve gia tri cua nut bi loai bo
    return Tg;
}
//-----------------------------
int DeleteX(Node* &L, Node* &R, int x)
{
    //1. Kiem tra danh sach rong
    if(L==NULL)
    {
        cout<<"Danh sach da rong!";
        return -1;
    }
    
    Node *P = L;
    while(P)
    {
        if(P->Infor == x)
        {
            if(L==P)
            {
                L = L->RPTR;
                L->LPTR = NULL;
            }
            else if(R==P)
            {
                R = R->LPTR;
                R->RPTR = NULL;
            }
            else
            {
                P->LPTR->RPTR = P->RPTR;
                P->RPTR->LPTR = P->LPTR;
            }
            delete P;
            return 1;
        }
        else P = P->RPTR;
    }
    return 0;
}
//-----------------------------
void DeleteAll(Node* &L, Node* &R)
{
    Node *P;
    while(L)
    {
        P = L;
        L=L->RPTR;
        delete P;
    }
}
//-----------------------------
void Display(Node *L, Node *R)
{
    while(L)
    {
        cout<<L->Infor<<"   ";
        L = L->RPTR;
    }
}



















                        
