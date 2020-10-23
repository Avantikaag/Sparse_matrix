#include<iostream>
using namespace std;
// using coordinate format
int main()
{
  int m2,n2,nnz2=0,l=0;
  cout<<"Enter the dimensions of the matrix: ";
  cin>>m2>>n2;
  int b[m2][n2];
  cout<<"Enter the matrix: ";
  for(int i=0;i<m2;i++)//taking the matrix
  {
    for(int j=0;j<n2;j++)
    {
      cin>>b[i][j];
      if(b[i][j]!=0)
      {
        ++nnz2;
      }
    }
  }
  int d2[nnz2],r2[nnz2],c2[nnz2];
  for(int i=0;i<n2;i++)//making triplets
  {
    for(int j=0;j<m2;j++)
    {
      if(b[j][i]!=0)
      {
        d2[l]=b[j][i];
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

  return 0;
}
