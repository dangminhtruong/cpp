//Ho ten: Dang Minh Truong
//MaSV: 588751
//Lop: K58QLTT
//De: Nhan ma tran su dung mang dong
#include <iostream>

using namespace std;

//Khai bao ham
void NhapMT(int *A, int m, int n);
void HienMT(int *A, int m, int n);
int* NhanMT(int *A, int *B, int m, int p, int n);

//===chuong trinh chinh===
int main()
{
    int A[100], B[100];
    int * f;
    int m,n,p;

    cout<<"Nhap m:"<<endl;
    cin>>m;

    cout<<"Nhap n:"<<endl;
    cin>>n;

    cout<<"Nhap p:"<<endl;
    cin>>p;

    NhapMT(A, m, p);
    HienMT(A, m, p);

    NhapMT(B, p, n);
    HienMT(B, p, n);
    
    f = NhanMT(A, B, m, p, n);
    cout<<"Ma tran tong la :"<<endl;
    HienMT(f, m, n);
    
    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void NhapMT(int *A, int m, int n)
{
    int i,j,k;
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            //Tinh chi so tai o nho thu i,j
            k = n*i + j;
            
            //Nhap 
            cout<<"\tNhap phan tu hang "<<i+1<<", cot "<<j+1<<": ";
            cin>>A[k];
        }
}
//----------------------
void HienMT(int *A, int m, int n)
{
    int i,j,k;
    
    for(i=0;i<m;i++)
    {
        //Dua ra cac phan tu tren hang thu i
        for(j=0;j<n;j++)
        {
            //Tinh chi so hang i, cot j
            k = n*i + j;
            
            //Dua ra
            cout<<A[k]<<"\t";
        }
        
        //Xuong dong
        cout<<endl;
    }
}
//----------------------
int* NhanMT(int *A, int *B, int m, int p, int n)
{
    //Tao mang dong chua ket qua
    int *C = new int[m*n];
    int i, j, k, tg, tg1, tg2;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            //Tinh o nho chua phan tu i,j
            tg = n*i + j;
            //Khoi tao phan tu tai vi tri tg = 0
            C[tg] = 0;
            
            for(k=0;k<p;k++)
            {
                tg1 = i*p + k;
                tg2 = k*p + j;
                
                //Nhan
                C[tg] = A[tg1] * B[tg2];
            }
        }
    }
    
    return C;
}



