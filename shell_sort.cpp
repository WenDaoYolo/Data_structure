#include<iostream>

void PrintArr(int* arr,int len)
{
	for(int i=0;i<len;i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

void MySwap(int& a,int& b)
{
	a=a^b;
	b=a^b;
	a=a^b;
}

void ShellSort(int* arr,int len,int flag)
{
	int temp;
	if(flag)
	{
		for(int gap=len/2;gap>0;gap/=2)
        {
            for(int i=0;i<len-1;i+=gap)
		    {
			    temp=arr[i+gap];
			    for(int j=i;j>=0;j-=gap)
			    {
				    if(temp<arr[j])
					    arr[j+gap]=arr[j];
				    else
				    {
					    arr[j+gap]=temp;
					    break;
				    }

				    if(j==0)
					    arr[j]=temp;
			    }
		    }
        }
	}
	else
	{
		for(int gap=len/2;gap>0;gap/=2)
        {
            for(int i=0;i<len-1;i+=gap)
		    {
			    temp=arr[i+gap];
			    for(int j=i;j>=0;j-=gap)
			    {
				    if(temp>arr[j])
					    arr[j+gap]=arr[j];
				    else
				    {
					    arr[j+gap]=temp;
					    break;
				    }

				    if(j==0)
					    arr[j]=temp;
			    }
		    }
        }
	}
}

int main()
{
	int arr[]={-4,3,2,1,4,-2,17,14,122};
	int len=sizeof(arr)/sizeof(int);

	std::cout<<"before:";
	PrintArr(arr,len);

	ShellSort(arr,len,0);

	std::cout<<"after:";
	PrintArr(arr,len);

	return 0;
}