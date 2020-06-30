#include<stdio.h>
#include<stdbool.h>
#define arrMAXSIZE 10

int* binarySearch(int* pArr, int* pFirst, int* pLast, int key);
void PRINT(int* pArr, int num);

int main(void) {
	int key,first,last,index;
	int arr[arrMAXSIZE] = {5,9,13,17,21,28,37,46,55,88};
	int *num;

	printf("원시 데이터 :");
	PRINT(arr, arrMAXSIZE);
	while (true) {
		int first = 0,last = arrMAXSIZE-1;
		printf("검색 데이터 입력(검색 종료 : 0) : ");
		scanf_s("%d", &key);
		if (key == 0)
			break;
		num = binarySearch(arr, &first, &last, key);
		index = first;
		if(num == 0) printf("없음!!!!\n");
		else printf("검색 데이터 : %d의 위치 : %d\n",*num,index);
	
	}
	return 0;
}
int* binarySearch(int* pArr, int* pFirst, int* pLast, int key) {
	int mid;

	while (*pFirst <= *pLast) {
		mid = (*pFirst + *pLast) / 2;
		if (key == *(pArr + mid)) 	{*pFirst=mid;	return (pArr + mid);}
		else if (key < *(pArr + mid))	{*pLast = mid-1;} 
		else if (key > *(pArr + mid))	{*pFirst = mid+1;}
	}
	return 0;
}


	void PRINT(int* pArr, int num) {
		for (int i = 0; i < num; i++)
			printf("%3d", *(pArr + i));
		printf("\n");
		return;
	}
