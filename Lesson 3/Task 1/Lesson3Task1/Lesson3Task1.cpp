#include <future>
#include <iostream>

void findMinimum(int* arr, int size, int index, std::promise<int> pr)
{
	int actual_index = index;

	for (int i = index; i < size; ++i)
	{
		if (arr[i] < arr[actual_index])
		{
			actual_index = i;
		}
	}

	pr.set_value(actual_index);
}

void asyncSort(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::promise<int> pr;
		std::future<int> ft = pr.get_future();
		auto async = std::async(findMinimum, arr, size, i, std::move(pr));
		ft.wait();
		int result = ft.get();

		if (result > i)
		{
			int temp = arr[i];
			arr[i] = arr[result];
			arr[result] = temp;
		}
	}
}

int main()
{
	int arr[] = { 1, -5, 23, 60, -8, 10, 0, 10, 2, 42 };
	int size = sizeof(arr) / sizeof(arr[0]);
	asyncSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}