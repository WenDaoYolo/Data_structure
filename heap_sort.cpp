#include<iostream>

void PrintArr(int* arr,int len)
{
	for(int i=0;i<len;i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

void MySwap(int& a,int& b)
{
    //注意：若两个数相同时，异或结果为0
    if(a==b) return;
	a=a^b;
	b=a^b;
	a=a^b;
}

void AdjustBigHeap(int* arr,int len,int parents)
{
	int max_index=parents,left=(parents*2+1),right=(parents*2+2);

	if(left<len&&arr[max_index]<arr[left])
		max_index=left;
	if(right<len&&arr[max_index]<arr[right])
		max_index=right;
	
	if(parents!=max_index)
	{
		MySwap(arr[max_index],arr[parents]);
		AdjustBigHeap(arr,len,max_index);
	}
}

void AdjustSmallHeap(int* arr,int len,int parents)
{
	int min_index=parents,left=(parents*2+1),right=(parents*2+2);

	if(left<len&&arr[min_index]>arr[left])
		min_index=left;
	if(right<len&&arr[min_index]>arr[right])
		min_index=right;
	
	if(parents!=min_index)
	{
		MySwap(arr[min_index],arr[parents]);
		AdjustSmallHeap(arr,len,min_index);
	}
}

void HeapSortUp(int* arr,int len)
{
	//从最后一个非叶子结点开始,构建初始最大堆
	for(int i=len/2-1;i>=0;i--)
		AdjustBigHeap(arr,len,i);

	//交换并继续调整堆,初始的最大堆交换后,树的长度从len变为len-1
	for(int i=len-1;i>0;i--)
	{
		MySwap(arr[0],arr[i]);
		AdjustBigHeap(arr,i,0);
	}
}

void HeapSortDown(int* arr,int len)
{
	//从最后一个非叶子结点开始,构建初始最小堆
	for(int i=len/2-1;i>=0;i--)
		AdjustSmallHeap(arr,len,i);

	//交换并继续调整堆,初始的最小堆交换后,树的长度从len变为len-1
	for(int i=len-1;i>0;i--)
	{
		MySwap(arr[0],arr[i]);
		AdjustSmallHeap(arr,i,0);
	}
}

int main()
{
    int arr[]={-4,3,2,1,4,-2,17,14,122};
	int len=sizeof(arr)/sizeof(int);

    std::cout<<"before:";
	PrintArr(arr,len);

	HeapSortUp(arr,len);
	std::cout<<"after:";
	PrintArr(arr,len);

    HeapSortDown(arr,len);
    std::cout<<"after:";
	PrintArr(arr,len);
    return 0;
}