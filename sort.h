#pragma once
#include<vector>
#include<algorithm>
using std::vector;
class Sort_Solution
{
	//从小到大排序
public:

	void BubbleSort(vector<int> &data);

	void SelectionSort(vector<int> &data);

	void InsertSort(vector<int> &data);

	void ShellSort(vector<int> &data);
	void ShellSort2(vector<int> &data);

	void MergeSort(vector<int> &data);
	void merge_fenzu(vector<int> &data, int l, int r);
	void merge(vector<int> &data, int l, int m, int r);

	void QuickSort(vector<int> &data);
	void quicksort(vector<int> &data, int l, int r);

	void HeapSort(vector<int> &data);
	void heapinsert(vector<int> &data);
	void heapify(vector<int> &data, int index, int size);

	void CountingSort(vector<int>& data);
	
	void BucketSort(vector<int> &data);

	void RadixSort(vector<int> &data);

private:
	void swap(int &a, int &b);
};



