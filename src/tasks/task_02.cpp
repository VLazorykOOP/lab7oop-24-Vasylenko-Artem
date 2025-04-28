#include <iostream>
#include <cstring>

#include "console.h"
#include "taskManager.h"

template <typename T>
void quicksort(T *arr, int left, int right)
{
	if (left >= right)
		return;

	T pivot = arr[(left + right) / 2];
	int i = left, j = right;

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		quicksort(arr, left, j);
	if (i < right)
		quicksort(arr, i, right);
}

template <>
void quicksort<const char *>(const char **arr, int left, int right)
{
	if (left >= right)
		return;

	const char *pivot = arr[(left + right) / 2];
	int i = left, j = right;

	while (i <= j)
	{
		while (std::strcmp(arr[i], pivot) < 0)
			i++;
		while (std::strcmp(arr[j], pivot) > 0)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		quicksort<const char *>(arr, left, j);
	if (i < right)
		quicksort<const char *>(arr, i, right);
}

using namespace std;

void task_02()
{
	int arr[] = {5, 2, 9, 1, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	quicksort(arr, 0, n - 1);

	for (int x : arr)
		std::cout << x << " ";
	std::cout << std::endl;

	const char *strArr[] = {
		"cherry",
		"date",
		"banana",
		"apple",
	};
	int m = sizeof(strArr) / sizeof(strArr[0]);

	quicksort(strArr, 0, m - 1);

	for (int i = 0; i < m; i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;
}
