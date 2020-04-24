#include<stdio.h>

#if  0
void InsertSort(int arr[], int len)
{
	int i = 1;
	int j = i - 1;
	int tmp;
	for (i; i < len; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; j--)//j >= 0 已排序部分还没有遍历完成，  
		{
			arr[j + 1] = arr[j];
		}//j == -1 0   arr[j] <= tmp  j+1
		arr[j + 1] = tmp;
	}
}



void ShowArr(int arr[], int len)
{
	int i = 0;
	for (; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 12, 3, 21, 32, 1, 34, 12, 35, 34, 18 };
	int len = sizeof(arr) / sizeof(arr[0]);
	ShowArr(arr, len);
	InsertSort(arr, len);
	ShowArr(arr, len);
	return 0;
}
#endif