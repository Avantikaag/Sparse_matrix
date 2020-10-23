#include<iostream>
using namespace std;
// using coordinate format
int main()
{
  int m1,m2,n1,n2,nnz1=0,nnz2=0,k=0,l=0,r=0,initial=0,sum,initial1=0,count,count1;
  cout<<"Enter the dimensions of the first matrix: ";
  cin>>m1>>n1;
  int a[m1][n1];
  cout<<"Enter the dimensions of the second matrix: ";
  cin>>m2>>n2;
  int b[m2][n2];
  if(n1!=m2)
  {
    cout<<"Matrices can't be multiplid"<<endl;
    return 0;
  }
  cout<<"Enter the 1 matrix: ";
  for(int i=0;i<m1;i++)//taking the 1 matrix
  {
    for(int j=0;j<n1;j++)
    {
      cin>>a[i][j];
      if(a[i][j]!=0)
      {
        ++nnz1;
      }
    }
  }
  int d1[nnz1],r1[nnz1],c1[nnz1];
  for(int i=0;i<m1;i++)//making vectors
  {
    for(int j=0;j<n1;j++)
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
  int r3[nnz2+nnz1], c3[nnz1+nnz2], d3[nnz1+nnz2];
  while(initial<nnz1)
  {
    count=0,initial1=0;
    for(int i=initial;i<nnz1;i++)
    {
      if(r1[i+1]==r1[i])
      {
        ++count;
      }
      else
      {
        break;
      }
    }
    while(initial1<nnz2)
    {
      sum=0,count1=0;
      for(int i=initial1;i<nnz2;i++)
      {
        if(r2[i+1]==r2[i])
        {
          ++count1;
        }
        else
        {
          break;
        }
      }
      for(int j=initial;j<initial+count+1;j++)
      {
        for(int k=initial1;k<initial1+count1+1;k++)
        {
          if(c1[j]==c2[k])
          {
            sum+=d1[j]*d2[k];
          }
        }
      }
      if(sum!=0)
      {
        d3[r]=sum;
        c3[r]=r2[initial1];
        r3[r]=r1[initial];
        ++r;
      }
      initial1=initial1+count1+1;
    }
    initial=initial+count+1;
  }
  cout<<"Multiplid matrix: "<<endl;
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
