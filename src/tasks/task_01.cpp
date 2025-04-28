#include <iostream>
#include <cstring>

#include "console.h"
#include "taskManager.h"

using namespace std;

template <typename T>
double average(T arr[], size_t size)
{
	if (size == 0)
		return 0.0;

	double sum = 0;
	for (size_t i = 0; i < size; ++i)
		sum += arr[i];

	return sum / size;
}

template <>
double average<const char *>(const char *arr[], size_t size)
{
	if (size == 0)
		return 0.0;

	double sum = 0;
	for (size_t i = 0; i < size; ++i)
		sum += strlen(arr[i]);

	return sum / size;
}

void task_01()
{
	int arrInt[] = {1, 2, 3, 4, 5};
	size_t sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);
	std::cout << "Average for int array: " << average(arrInt, sizeInt) << std::endl;

	const char *strs[] = {"Hello", "World"};
	size_t sizeStrs = sizeof(strs) / sizeof(strs[0]);
	std::cout << "Average for string array*: " << average(strs, sizeStrs) << std::endl;
}