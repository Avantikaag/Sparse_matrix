#include<iostream>
using namespace std;
// using compressed row format
int main()
{
  int m,n,nnz=0,k=0;
  cout<<"Enter the dimensions of the matrix: ";
  cin>>m>>n;
  int a[m][n];
  cout<<"Enter the matrix: ";
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>a[i][j];
      if(a[i][j]!=0)
      {
        ++nnz;
      }
    }
  }
  int d[nnz],r[m+1],c[nnz];
  r[0]=0;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(a[i][j]!=0)
      {
        d[k]=a[i][j];
        c[k]=j;
        ++k;
      }
    }
    r[i+1]=k;
  }
  cout<<"Data vector: ";
  for(int i=0;i<nnz;i++)
  {
    cout<<d[i]<<" ";
  }
  cout<<endl;
  cout<<"Column vector: ";
  for(int i=0;i<nnz;i++)
  {
    cout<<c[i]<<" ";
  }
  cout<<endl;
  cout<<"Row vector: ";
  for(int i=0;i<m+1;i++)
  {
    cout<<r[i]<<" ";
  }
  cout<<endl;
  return 0;
}
