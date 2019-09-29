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

	//快速排序1
	void QuickSort(vector<int> &data);
	void __quicksort(vector<int> &data, int l, int r);
	//快速排序2
	void Quicksort_2(vector<int> &data);
	int  partition(vector<int> &data, int l, int r);
	void __quicksort2(vector<int> &data, int l,int r);
	//双路快速排序
	void Quicksort_db(vector<int> &data);
	int  partition_db(vector<int> &data, int l, int r);
	void __quicksort_db(vector<int> &data, int l,int r);
	//三路快速排序
	void Quicksort_tri(vector<int> &data)
	void __quicksort_tri(vector<int> &data,int l,int r);

	void HeapSort(vector<int> &data);
	void heapinsert(vector<int> &data);
	void heapify(vector<int> &data, int index, int size);

	void CountingSort(vector<int>& data);
	
	void BucketSort(vector<int> &data);

	void RadixSort(vector<int> &data);

private:
	void swap(int &a, int &b);
};



