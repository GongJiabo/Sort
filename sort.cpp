#include"sort.h"

void Sort_Solution::swap(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

//冒泡排序
// 1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
// 2.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
// 3.针对所有的元素重复以上的步骤，除了最后一个。
// 4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
void Sort_Solution::BubbleSort(vector<int> &data)
{
	int n = data.size();
	for (int i = 0; i < n; i++)
	{
		//设定标记，如果没有发生交换，则排序结束
		bool flag = false;
		for (int j = i + 1; j < n; j++)
		{
			if (data[j] < data[i])
			{
				swap(data[i], data[j]);
				flag = true;
			}
		}
		if (!flag) break;
	}
}


//选择排序
// 1.首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
// 2.再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
// 3.重复第二步，直到所有元素均排序完毕。
void Sort_Solution::SelectionSort(vector<int> &data)
{
	int n = data.size();
	for (int i = 0; i < n; i++)
	{
		int min = data[i];
		int min_index = i;
		//找后面的最小值
		for (int j = i + 1; j < n; j++)
		{
			if (data[j] < min)
			{
				min = data[j];
				min_index = j;
			}
		}
		if (i != min_index)
		{
			//将当前值与最小值交换位置
			swap(data[i], data[min_index]);
		}
	}
}


//插入排序
// 1.将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
// 2.从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。
//  （如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
void Sort_Solution::InsertSort(vector<int> &data)
{
	int n = data.size();
	for (int i = 1; i < n; i++)
	{
		int temp = data[i];
		//向前比较
		int j = i;
		while (j > 0 && temp < data[j-1]) 
		{
			//后移位置
			data[j] = data[j - 1];
			j--;
		}
		//存在比其小的数则插入
		if (j != i) data[j] = temp;
	}
}

//希尔排序(缩小增量排序)
// 1.选择一个增量序列 t1，t2，……，tk，其中 ti > tj, tk = 1；
// 2.按增量序列个数 k，对序列进行 k 趟排序；
// 3.每趟排序，根据对应的增量 ti，将待排序列分割成若干长度为 m 的子序列，分别对各子表进行直接插入排序。仅增量因子为 1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
void Sort_Solution::ShellSort(vector<int> &data)
{
	int n = data.size();
	int gap = n;
	do
	{
		//每次减小增量，直到gap为1
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			//对每个划分进行直接插入排序
			//注意：对各个组进行插入时并不是先对一个组进行排序完，再对另一个组排序，而是轮流对每个组进行插入排序！！
			if (data[i - gap] > data[i])
			{
				int temp = data[i];
				int j = i - gap;
				//移动元素并寻找位置
				do
				{
					data[j + gap] = data[j];
					j = j - gap;
				} while (j >= 0 && data[j] > temp);
				//插入元素
				data[j + gap] = temp;
			}
		}
	} while (gap > 1);
}

void Sort_Solution::ShellSort2(vector<int> &data)
{
	int n = data.size();
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		//对各个分组进行插入排序
		for (int i = gap; i < n; i++)
		{
			//将data[i]插入到分组的正确位置上
			int inserted = data[i];
			//插入的时候按组进行插入(组内元素两两相隔gap)
			int j;
			for (j = i - gap; j >= 0 && inserted < data[j]; j -= gap) data[j + gap] = data[j];
			data[j + gap] = inserted;
		}
	}
}


//归并排序
// 1.申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
// 2,设定两个指针，最初位置分别为两个已经排序序列的起始位置；
// 3.比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
// 4.重复步骤 3 直到某一指针达到序列尾；
// 5.将另一序列剩下的所有元素直接复制到合并序列尾。
void Sort_Solution::MergeSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1)return;
	else
		merge_fenzu(data, 0, n - 1);
}

void Sort_Solution::merge_fenzu(vector<int> &data, int l, int r)
{
	if (l == r) return;
	else
	{
		//取中间数，进行拆分
		int m = (l + r) / 2;
		//left
		merge_fenzu(data, l, m);
		//right
		merge_fenzu(data, m + 1, r);
		//合并
		merge(data, l, m + 1, r);
	}
}

void Sort_Solution::merge(vector<int> &data, int l, int m, int r)
{
	vector<int> leftarray(data.begin() + l, data.begin() + m);
	vector<int> rightarray(data.begin() + m, data.begin() + r +1);
	//比较
	int i = 0, j = 0;
	int k = l;
	while (i < leftarray.size() && j < rightarray.size())
	{
		if (leftarray[i] < rightarray[j])
		{
			data[k] = leftarray[i];
			i++;
			k++;
		}
		else
		{
			data[k] = rightarray[j];
			j++;
			k++;
		}
	}
	//left有多的数
	while (i < leftarray.size())
	{
		data[k] = leftarray[i];
		i++;
		k++;
	}
	//right有多的数
	while (j < rightarray.size())
	{
		data[k] = rightarray[j];
		j++;
		k++;
	}
}
//快速排序1
// 1.从数列中挑出一个元素，称为 “基准”（pivot）;
// 2.重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
// 3.递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
void Sort_Solution::QuickSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1) return;
	quicksort(data, 0, n - 1);
}

void Sort_Solution::__quicksort(vector<int> &data, int l, int r)
{
	if (l > r) return;
	int temp = data[l];
	int i = l, j = r;
	while (i != j)
	{
		//先从右边开始找
		while (data[j] >= temp && i < j)
			j--;
		//找左边
		while (data[i] <= temp && i < j)
			i++;
		//交换位置
		swap(data[i], data[j]);
	}
	//基数归位
	data[l] = data[i];
	data[i] = temp;
	//继续处理
	quicksort(data, l, i - 1);
	quicksort(data, i + 1, r);
}

//快速排序2
int Sort_Solution::partition(vector<int> &data, int l,int r)
{
	int v = data[l];
	int j;
	j = l;
	for(int i = l+1; l<=r; i++)
	{
		if(data[i] < v)
		{
			swap(data[j+1],data[i]);
			j++;
		}
	}
	swap(data[l],data[j]);
	return j;
}

void Sort_Solution::__quicksort2(vector<int> &data, int l, int r)
{
	if(l >= r) return;
	int p = partition(data, l, r);
	__quicksort2(data, l, p-1);
	__quicksort2(data, p+1, r);
}

void Sort_Solution::Quicksort2(vector<int> &data)
{
	int n = data.size();
	__quicksort2(data, 0, n-1);
}

//双路快速排序
void Sort_Solution::Quicksort_db(vector<int> &data)
{
	int n = data.size();
	__quicksort_db(data, 0, n-1);
}

int  Sort_Solution::partition_db(vector<int> &data, int l, int r)
{
	int v = data[l];
	int i,j;
	i = l+1;
	j = r;
	while(true)
	{
		while(data[i] < v && i <= r) i++;
		while(data[j] > v && j >= l) j--;
		if(i > j) break;
		swap(data[i], data[j]);
		return j;
	}
}

void Sort_Solution::__quicksort_db(vector<int> &data, int l,int r)
{
	if(l >= r) return;
	int p = partition_db(data, l, r);
	__quicksort_db(data, l, p-1);
	__quicksort_db(data, p+1, r);
}

//三路快速排序
void Quicksort_tri(vector<int> &data)
{
	int n = data.size();
	__quicksort_tri(data, 0, n-1);
}

void __quicksort_tri(vector<int> &data,int l,int r)
{
	if(l >= r) return;
	v = data[l];
	int lt = l;
	int gt = r + 1;
	int i = l + 1;
	while(i < gt)
	{
		if(data[i] < v)
		{
			swap(data[i] ,data[lt +1]);
			lt++;
			i++;
		}
		else if(data[i] > v)
		{
			swap(data[i], data[gt-1])
			gt--;
		}
		else i++;
	}
	swap(data[l], data[lt]);
	__quicksort_tri(data, l, lt-1);
	__quicksort_tri(data, gt, r);
}

//堆排序
// 1.创建一个堆 H[0……n-1]；
// 2.把堆首（最大值）和堆尾互换；
// 3.把堆的尺寸缩小 1，并调用 shift_down(0)，目的是把新的数组顶端数据调整到相应位置；
// 4.重复步骤 2，直到堆的尺寸为 1。
void Sort_Solution::HeapSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1) return;
	//构造大根堆
	heapinsert(data);
	while (n > 1)
	{
		//固定最大值
		swap(data[0], data[n-1]);
		n--;
		//固定后重新构造大根堆
		heapify(data, 0, n);
	}
}

void Sort_Solution::heapinsert(vector<int> &data)
{
	int n = data.size();
	//初始化，构造大根堆，通过插入的数不断比较至堆顶
	for (int i = 0; i < n; i++)
	{
		int cur_index = i;
		int father_index = (cur_index - 1) / 2;
		//如果当前插入的值大于其父结点的值,则交换值，并且将索引指向父结点
        //然后继续和上面的父结点值比较，直到不大于父结点，则退出循环
		while (data[cur_index] > data[father_index])
		{
			swap(data[cur_index], data[father_index]);
			//将当前索引指向父结点
			cur_index = father_index;
			//重新计算当前索引的父结点
			father_index = (cur_index - 1) / 2;
		}
	}
}

void Sort_Solution::heapify(vector<int> &data, int index, int size)
{
	//将固定后剩余的数构造成大根堆
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	while (left < size)
	{
		int largeindex;
		//判断孩子中较大的索引值(要确保右孩子在索引范围内)
		if (data[left] < data[right] && right < size) largeindex = right;
		else largeindex = left;
		//与父结点进行比较
		if (data[index] > data[largeindex])
			largeindex = index;
		//如果父结点索引是最大值的索引，那已经是大根堆了，则退出循环
		if (index == largeindex) break;
		//如果父结点不是最大值，与孩子中较大的一个交换
		swap(data[largeindex], data[index]);
		//并将索引指向孩子中较大的索引值
		index = largeindex;
		//重新计算
		left = 2 * index + 1;
		right = 2 * index + 2;
	}

}

//计数排序
// 1.花O(n)的时间扫描一下整个序列 A，获取最小值 min 和最大值 max
// 2.开辟一块新的空间创建新的数组 B，长度为(max - min + 1)
// 3.数组 B 中 index 的元素记录的值是 A 中某元素出现的次数
// 4.最后输出目标整数序列，具体的逻辑是遍历数组 B，输出相应元素以及对应的个数
void Sort_Solution::CountingSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1)return;
	//保存最大值与最小值
	int vmax = *max_element(data.begin(), data.end());
	int vmin = *min_element(data.begin(), data.end());
	//开辟计数的容器
	vector<int> count(vmax - vmin + 1, 0);
	for (auto it = data.begin(); it != data.end(); it++)
		count[*it - vmin]++;
	//按顺序存放
	int pos = 0;
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i] == 0) continue;
		else
		{
			for (int j = 0; j < count[i]; j++)
			{
				data[pos] = i + vmin;
				pos++;
			}
		}
	}
}

//桶排序
// 1.设置固定数量的空桶。
// 2.把数据放到对应的桶中。
// 3.对每个不为空的桶中数据进行排序。
// 4.拼接不为空的桶中数据，得到结果
void Sort_Solution::BucketSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1)return;
	//保存最大值与最小值
	int vmax = *max_element(data.begin(), data.end());
	int vmin = *min_element(data.begin(), data.end());
	//确定映射规则、常量位
	int Bucket_number = vmax / 10 - vmin / 10 + 1;
	vector<vector<int>> bucket(Bucket_number);
	for (auto it = data.begin(); it != data.end(); it++)
		bucket[*it / Bucket_number - vmin / 10 ].push_back(*it);
	//排序，并重组data
	int pos = 0;
	for (int i = 0; i < Bucket_number; i++)
	{
		//InsertSort(bucket[i]);
		for (int j = 0; j < bucket[i].size(); j++)
		{
			data[pos] = bucket[i][j];
			pos++;
		}
	}
}

//基数排序
// 1.将所有待比较数值（正整数）统一为同样的数位长度，数位较短的数前面补零
// 2.从最低位开始，依次进行一次排序
// 3.从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列
void Sort_Solution::RadixSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1)return;
	vector<int> temp(n);
	//获得最大值的最高位数，即最大位数
	int vmax = *max_element(data.begin(), data.end());
	int digit = 0;
	int number = vmax;
	while (number != 0)
	{
		digit++;
		number /= 10;
	}
	//桶 -9到9
	vector<vector<int>> bucket(19);
	int i, j, k;
	int division = 1;
	//进行digit次排序
	for (i = 1; i <= digit; i++)
	{
		//分配前先清空
		for (j = 0; j < 19; j++)
			bucket[j].clear();
		//分配统计
		for (j = 0; j < n; j++)
		{
			k = (data[j] / division) % 10;
			bucket[k + 9].push_back(data[j]);
		}
		//重新分配至data
		int pos = 0;
		for (int m = 0; m < 19; m++)
		{
			for (int f = 0; f < bucket[m].size(); f++)
			{
				data[pos] = bucket[m][f];
				pos++;
			}
		}
		division *= 10;
	}
}