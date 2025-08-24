#include<iostream>
 using namespace std;
  int main()
  {
    bool issort=false;
    cout <<"enter size of array";
     int n;
     cin>>n;
      int arr[n];
      cout<<"enter elements of array";
        for(int i=0;i<n;i++)
        { 
             cin>>arr[i];
        }
        for(int i=0;i<=n-1;i++)
        {   issort=false;
            for(int j=0;j<=n-1;j++)
            {
                    if(arr[j]>arr[j+1])
                    {
                      int temp=arr[j];
                      arr[j]=arr[j+1];
                      arr[j+1]=temp;
                      issort=true;



                    }
                 
            }

      if (!issort){
        break;
      }

        }
        cout<<"the sorted array is:";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }

    }











  