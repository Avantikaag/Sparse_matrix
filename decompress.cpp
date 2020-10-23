#include<bits/stdc++.h>
using namespace std;
// using compressed row format
int main()
{
  int m,nnz,p=0;
  cout<<"Enter the length of row vector: ";
  cin>>m;
  cout<<"Enter the length of column vector: ";
  cin>>nnz;
  int r[m], c[nnz], d[nnz];
  int e[nnz];
  cout<<"Data vector: ";
  for(int i=0;i<nnz;i++)
  {
    cin>>d[i];
  }
  cout<<"Column vector: ";
  for(int i=0;i<nnz;i++)
  {
    cin>>c[i];
  }
  for(int i=0;i<nnz;i++)
  {
    e[i]=c[i];
  }
  cout<<"Row vector: ";
  for(int i=0;i<m;i++)
  {
    cin>>r[i];
  }
  sort(e,e+nnz);
  int n=e[nnz-1];
  int a[m-1][n+1];
  for(int i=0;i<m-1;i++)
  {
    for(int j=0;j<n+1;j++)
    {
      a[i][j]=0;
    }
  }
  for(int i=1;i<m;i++)
  {
    if((r[i]-r[i-1])!=0)
    {
      for(int j=p;j<p+r[i]-r[i-1];j++)
      {
        a[i-1][c[j]]=d[j];
      }
      p+=r[i]-r[i-1];
    }
  }
  for(int i=0;i<m-1;i++)
  {
    for(int j=0;j<n+1;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}
