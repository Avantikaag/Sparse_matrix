#include<iostream>
using namespace std;
// using coordinate format
int main()
{
  int m,n,nnz,nnz1=0,nnz2=0,k=0,l=0,p=0,q=0,r=0;
  cout<<"Enter the dimensions of the matrix: ";
  cin>>m>>n;
  int a[m][n],b[m][n],c[m][n];
  c[m][n]={0};
  cout<<"Enter the 1 matrix: ";
  for(int i=0;i<m;i++)//taking the matrix
  {
    for(int j=0;j<n;j++)
    {
      cin>>a[i][j];
      if(a[i][j]!=0)
      {
        ++nnz1;
      }
    }
  }
  int d1[nnz1],r1[nnz1],c1[nnz1];
  for(int i=0;i<m;i++)//making triplets
  {
    for(int j=0;j<n;j++)
    {
      if(a[i][j]!=0)
      {
        d1[k]=a[i][j];
        c1[k]=j;
        r1[k]=i;
        ++k;
      }
    }
  }
  cout<<"Data vector 1: ";
  for(int i=0;i<nnz1;i++)
  {
    cout<<d1[i]<<" ";
  }
  cout<<endl;
  cout<<"Column vector 1: ";
  for(int i=0;i<nnz1;i++)
  {
    cout<<c1[i]<<" ";
  }
  cout<<endl;
  cout<<"Row vector 1: ";
  for(int i=0;i<nnz1;i++)
  {
    cout<<r1[i]<<" ";
  }
  cout<<endl;
  cout<<"Enter the 2 matrix: ";
  for(int i=0;i<m;i++)//matrix 2
  {
    for(int j=0;j<n;j++)
    {
      cin>>b[i][j];
      if(b[i][j]!=0)
      {
        ++nnz2;
      }
    }
  }
  int d2[nnz2],r2[nnz2],c2[nnz2];
  for(int i=0;i<m;i++)//triplets
  {
    for(int j=0;j<n;j++)
    {
      if(b[i][j]!=0)
      {
        d2[l]=b[i][j];
        c2[l]=j;
        r2[l]=i;
        ++l;
      }
    }
  }
  cout<<"Data vector 2: ";
  for(int i=0;i<nnz2;i++)
  {
    cout<<d2[i]<<" ";
  }
  cout<<endl;
  cout<<"Column vector 2: ";
  for(int i=0;i<nnz2;i++)
  {
    cout<<c2[i]<<" ";
  }
  cout<<endl;
  cout<<"Row vector 2: ";
  for(int i=0;i<nnz2;i++)
  {
    cout<<r2[i]<<" ";
  }
  cout<<endl;
  int r3[nnz2+nnz1]={-1}, c3[nnz1+nnz2]={-1}, d3[nnz1+nnz2]={-1};
  while((p<nnz1)&&(q<nnz2))
  {
    while((r1[p]!=r2[q])&&(p<nnz1)&&(q<nnz2))
    {
      if(r1[p]>r2[q])
      {
        r3[r]=r2[q];
        c3[r]=c2[q];
        d3[r]=d2[q];
        ++r;++q;
      }
      else
      {
        r3[r]=r1[p];
        c3[r]=c1[p];
        d3[r]=d1[p];
        ++r;++p;
      }
    }
    while((r1[p]==r2[q])&&(p<nnz1)&&(q<nnz2))
    {
      if(c1[p]==c2[q])//if columns are equal
      {
        c3[r]=c1[p];
        r3[r]=r1[p];
        d3[r]=d1[p]+d2[q];
        ++p,++q,++r;
      }
      else if(c1[p]>c2[q])//if c1 is greater
      {
        c3[r]=c2[q];
        r3[r]=r2[q];
        d3[r]=d2[q];
        ++r,++q;
      }
      else//if c2 is greater
      {
        c3[r]=c1[p];
        r3[r]=r1[p];
        d3[r]=d1[p];
        ++r,++p;
      }
    }
  }
  if(p!=nnz1)
  {
    c3[r]=c1[p];
    r3[r]=r1[p];
    d3[r]=d1[p];
    ++r;
  }
  if(q!=nnz2)
  {
    c3[r]=c2[q];
    r3[r]=r2[q];
    d3[r]=d2[q];
    ++r;
  }
  cout<<"Data vector 3: ";
  for(int j=0;j<r;j++)
  {
    cout<<d3[j]<<" ";
  }
  cout<<endl;
  cout<<"Column vector 3: ";
  for(int j=0;j<r;j++)
  {
    cout<<c3[j]<<" ";
  }
  cout<<endl;
  cout<<"Row vector 3: ";
  for(int j=0;j<r;j++)
  {
    cout<<r3[j]<<" ";
  }
  cout<<endl;
  return 0;
}
