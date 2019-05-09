//Ho ten: Nguyen Xuan Hai
//MaSV: 596743
//Lop: K59THA
//De: 
#include <iostream>

using namespace std;

//Khai bao cau truc Node
struct Node
{
    char Infor;
    Node *LPTR, *RPTR;
};

//Khai bao ham
void PreOrder(Node *T);
void InOrder(Node *T);
void PostOrder(Node *T);

//===chuong trinh chinh===
int main()
{
    //Khai bao cay nhi phan rong
    Node *T = NULL;
    Node *N, *P;
    
    //Tao nut goc(nut 1)
    N = new Node;
    N->Infor = '-';
    N->LPTR = N->RPTR = NULL;
    T = N;
    
    //Tao nut 2
    N = new Node;
    N->Infor = '*';
    N->LPTR = N->RPTR = NULL;
    T->LPTR = N;
    
    //Tao nut 3
    N = new Node;
    N->Infor = '/';
    N->LPTR = N->RPTR = NULL;
    T->RPTR = N;
    
    //Tao nut 4
    P = T->LPTR;
    N = new Node;
    N->Infor = '+';
    N->LPTR = N->RPTR = NULL;
    P->LPTR = N;
    
    //Tao nut 5
    N = new Node;
    N->Infor ='2';
    N->LPTR = N->RPTR = NULL;
    P->RPTR = N;
    
    //Tao nut 8
    P = P->LPTR;
    N = new Node;
    N->Infor = 'a';
    N->LPTR = N->RPTR = NULL;
    P->LPTR = N;
    
    //Tao nut 9
    N = new Node;
    N->Infor = 'b';
    N->LPTR = N->RPTR = NULL;
    P->RPTR = N;
    
    //Tao nut 6
    P = T->RPTR;
    N = new Node;
    N->Infor = 'c';
    N->LPTR = N->RPTR = NULL;
    P->LPTR = N;
    
    //Tao nut 7
    N = new Node;
    N->Infor = 'd';
    N->LPTR = N->RPTR = NULL;
    P->RPTR = N;
    
    cout<<"Duyet cay tien thu tu la: ";
    PreOrder(T);
    
    cout<<"\nDuyet cay trung thu tu: ";
    InOrder(T);
    
    cout<<"\nDuyet cay hau thu tu: ";
    PostOrder(T);
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void PreOrder(Node *T)
{
    if(T==NULL) return;
    
    cout<<T->Infor<<"   ";
    
    //Lap lai duyet cay con ben trai
    PreOrder(T->LPTR);
    
    //Lap lai duyet cay con ben phai
    PreOrder(T->RPTR);
}
//----------------------
void InOrder(Node *T)
{
    if(T==NULL) return;
    
    //Duyet cay con ben trai
    InOrder(T->LPTR);
    
    //Dua ra
    cout<<T->Infor<<"  ";
    
    //Duyet cay con ben phai
    InOrder(T->RPTR);
}
//----------------------
void PostOrder(Node *T)
{
    if(T==NULL) return;
    
    //Duyet cay con ben trai
    PostOrder(T->LPTR);
    
    //Duyet cay con ben phai
    PostOrder(T->RPTR);
    
    //Dua ra
    cout<<T->Infor<<"   ";
}










