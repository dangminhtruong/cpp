//Ho ten: 
//MaSV: 
//Lop: 
//De: 
#include <iostream>

using namespace std;

//Khai bao hang
#define SIZE 50

//Cai dat cau truc hang doi luu tru bang mang
struct CQueue
{
    int F,R;
    int Q[SIZE];
} CQ = {-1,-1};

//Khai bao cac ham
void CQInsert(CQueue &CQ, int x);
int CQDelete(CQueue &CQ);
int CQEmpty(CQueue CQ);

//===chuong trinh chinh===
int main()
{
    int n,a[SIZE],i;
    
    cout<<"Nhap vao so luong phan tu cua day so: ";
    cin>>n;
    
    cout<<"Nhap vao day so:\n";
    for(i=0;i<n;i++)
    {
        cout<<"Nhap so thu "<<i+1<<": ";
        cin>>a[i];
    }
    
    cout<<"Day so da nhap la:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<"   ";
    
    for(i=0;i<n;i++)
        if(a[i]%2==1)
            CQInsert(CQ,a[i]);
    for(i=0;i<n;i++)
        if(a[i]%2==0)
            CQInsert(CQ,a[i]);
            
    cout<<"\nDay so da dua cac so le ve dau, cac so chan ve cuoi la:\n";
    while(!CQEmpty(CQ)) cout<<CQDelete(CQ)<<"   ";


    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void CQInsert(CQueue &CQ, int x)
{
    //1. Kiem tra hang doi day
    if(CQ.F==0 && CQ.R == SIZE-1 || CQ.R+1==CQ.F)
    {
        cout<<"Hang doi da day!";
        return;
    }
    
    //2. Thay doi chi so R
    if(CQ.R==-1) CQ.F = CQ.R = 0;
    else if(CQ.R==SIZE-1) CQ.R = 0;
    else CQ.R++;
    
    //3. Bo sung x
    CQ.Q[CQ.R] = x;
}
//--------------------------
int CQDelete(CQueue &CQ)
{
    //1. Kiem tra hang doi rong
    if(CQ.F==-1)
    {
        cout<<"Hang doi da rong!";
        return -1;
    }
    
    //2. Luu lai phan tu loai bo
    int Tg = CQ.Q[CQ.F];
    
    //3. Thay doi chi so F
    if(CQ.F==CQ.R) CQ.F = CQ.R = -1;
    else if(CQ.F==SIZE-1) CQ.F = 0;
    else CQ.F++;
    
    //4. Tra ve phan tu bi loai bo
    return Tg;
}
//--------------------------
int CQEmpty(CQueue CQ)
{
    if(CQ.F==-1) return 1;
    
    return 0;
}













