//          Binary Search 

#include <stdio.h>

int binarySearch(int arr[], int lb,int ub,int key)
{
	if (ub >= lb) {
		int mid = lb + (ub - lb) / 2;

		if (arr[mid] == key)
			return mid;

		if (arr[mid] > key)
			return binarySearch(arr, lb, mid- 1, key);

		return binarySearch(arr, mid + 1, ub, key);
	}

	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 109;
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}
