#include"sort.h"

void Sort_Solution::swap(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

//ð������
// 1.�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
// 2.��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������
// 3.������е�Ԫ���ظ����ϵĲ��裬�������һ����
// 4.����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
void Sort_Solution::BubbleSort(vector<int> &data)
{
	int n = data.size();
	for (int i = 0; i < n; i++)
	{
		//�趨��ǣ����û�з������������������
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


//ѡ������
// 1.������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ��
// 2.�ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ��
// 3.�ظ��ڶ�����ֱ������Ԫ�ؾ�������ϡ�
void Sort_Solution::SelectionSort(vector<int> &data)
{
	int n = data.size();
	for (int i = 0; i < n; i++)
	{
		int min = data[i];
		int min_index = i;
		//�Һ������Сֵ
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
			//����ǰֵ����Сֵ����λ��
			swap(data[i], data[min_index]);
		}
	}
}


//��������
// 1.����һ���������е�һ��Ԫ�ؿ���һ���������У��ѵڶ���Ԫ�ص����һ��Ԫ�ص�����δ�������С�
// 2.��ͷ��β����ɨ��δ�������У���ɨ�赽��ÿ��Ԫ�ز����������е��ʵ�λ�á�
//  ������������Ԫ�������������е�ĳ��Ԫ����ȣ��򽫴�����Ԫ�ز��뵽���Ԫ�صĺ��档��
void Sort_Solution::InsertSort(vector<int> &data)
{
	int n = data.size();
	for (int i = 1; i < n; i++)
	{
		int temp = data[i];
		//��ǰ�Ƚ�
		int j = i;
		while (j > 0 && temp < data[j-1]) 
		{
			//����λ��
			data[j] = data[j - 1];
			j--;
		}
		//���ڱ���С���������
		if (j != i) data[j] = temp;
	}
}

//ϣ������(��С��������)
// 1.ѡ��һ���������� t1��t2��������tk������ ti > tj, tk = 1��
// 2.���������и��� k�������н��� k ������
// 3.ÿ�����򣬸��ݶ�Ӧ������ ti�����������зָ�����ɳ���Ϊ m �������У��ֱ�Ը��ӱ����ֱ�Ӳ������򡣽���������Ϊ 1 ʱ������������Ϊһ�������������ȼ�Ϊ�������еĳ��ȡ�
void Sort_Solution::ShellSort(vector<int> &data)
{
	int n = data.size();
	int gap = n;
	do
	{
		//ÿ�μ�С������ֱ��gapΪ1
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			//��ÿ�����ֽ���ֱ�Ӳ�������
			//ע�⣺�Ը�������в���ʱ�������ȶ�һ������������꣬�ٶ���һ�������򣬶���������ÿ������в������򣡣�
			if (data[i - gap] > data[i])
			{
				int temp = data[i];
				int j = i - gap;
				//�ƶ�Ԫ�ز�Ѱ��λ��
				do
				{
					data[j + gap] = data[j];
					j = j - gap;
				} while (j >= 0 && data[j] > temp);
				//����Ԫ��
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
		//�Ը���������в�������
		for (int i = gap; i < n; i++)
		{
			//��data[i]���뵽�������ȷλ����
			int inserted = data[i];
			//�����ʱ������в���(����Ԫ���������gap)
			int j;
			for (j = i - gap; j >= 0 && inserted < data[j]; j -= gap) data[j + gap] = data[j];
			data[j + gap] = inserted;
		}
	}
}


//�鲢����
// 1.����ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ�������У�
// 2,�趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ�ã�
// 3.�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ�ã�
// 4.�ظ����� 3 ֱ��ĳһָ��ﵽ����β��
// 5.����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β��
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
		//ȡ�м��������в��
		int m = (l + r) / 2;
		//left
		merge_fenzu(data, l, m);
		//right
		merge_fenzu(data, m + 1, r);
		//�ϲ�
		merge(data, l, m + 1, r);
	}
}

void Sort_Solution::merge(vector<int> &data, int l, int m, int r)
{
	vector<int> leftarray(data.begin() + l, data.begin() + m);
	vector<int> rightarray(data.begin() + m, data.begin() + r +1);
	//�Ƚ�
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
	//left�ж����
	while (i < leftarray.size())
	{
		data[k] = leftarray[i];
		i++;
		k++;
	}
	//right�ж����
	while (j < rightarray.size())
	{
		data[k] = rightarray[j];
		j++;
		k++;
	}
}
//��������
// 1.������������һ��Ԫ�أ���Ϊ ����׼����pivot��;
// 2.�����������У�����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ��棨��ͬ�������Ե���һ�ߣ�������������˳�֮�󣬸û�׼�ʹ������е��м�λ�á������Ϊ������partition��������
// 3.�ݹ�أ�recursive����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������
void Sort_Solution::QuickSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1) return;
	quicksort(data, 0, n - 1);
}

void Sort_Solution::quicksort(vector<int> &data, int l, int r)
{
	if (l > r) return;
	int temp = data[l];
	int i = l, j = r;
	while (i != j)
	{
		//�ȴ��ұ߿�ʼ��
		while (data[j] >= temp && i < j)
			j--;
		//�����
		while (data[i] <= temp && i < j)
			i++;
		//����λ��
		swap(data[i], data[j]);
	}
	//������λ
	data[l] = data[i];
	data[i] = temp;
	//��������
	quicksort(data, l, i - 1);
	quicksort(data, i + 1, r);
}

//������
// 1.����һ���� H[0����n-1]��
// 2.�Ѷ��ף����ֵ���Ͷ�β������
// 3.�Ѷѵĳߴ���С 1�������� shift_down(0)��Ŀ���ǰ��µ����鶥�����ݵ�������Ӧλ�ã�
// 4.�ظ����� 2��ֱ���ѵĳߴ�Ϊ 1��
void Sort_Solution::HeapSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1) return;
	//��������
	heapinsert(data);
	while (n > 1)
	{
		//�̶����ֵ
		swap(data[0], data[n-1]);
		n--;
		//�̶������¹�������
		heapify(data, 0, n);
	}
}

void Sort_Solution::heapinsert(vector<int> &data)
{
	int n = data.size();
	//��ʼ�����������ѣ�ͨ������������ϱȽ����Ѷ�
	for (int i = 0; i < n; i++)
	{
		int cur_index = i;
		int father_index = (cur_index - 1) / 2;
		//�����ǰ�����ֵ�����丸����ֵ,�򽻻�ֵ�����ҽ�����ָ�򸸽��
        //Ȼ�����������ĸ����ֵ�Ƚϣ�ֱ�������ڸ���㣬���˳�ѭ��
		while (data[cur_index] > data[father_index])
		{
			swap(data[cur_index], data[father_index]);
			//����ǰ����ָ�򸸽��
			cur_index = father_index;
			//���¼��㵱ǰ�����ĸ����
			father_index = (cur_index - 1) / 2;
		}
	}
}

void Sort_Solution::heapify(vector<int> &data, int index, int size)
{
	//���̶���ʣ���������ɴ����
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	while (left < size)
	{
		int largeindex;
		//�жϺ����нϴ������ֵ(Ҫȷ���Һ�����������Χ��)
		if (data[left] < data[right] && right < size) largeindex = right;
		else largeindex = left;
		//�븸�����бȽ�
		if (data[index] > data[largeindex])
			largeindex = index;
		//�����������������ֵ�����������Ѿ��Ǵ�����ˣ����˳�ѭ��
		if (index == largeindex) break;
		//�������㲻�����ֵ���뺢���нϴ��һ������
		swap(data[largeindex], data[index]);
		//��������ָ�����нϴ������ֵ
		index = largeindex;
		//���¼���
		left = 2 * index + 1;
		right = 2 * index + 2;
	}

}

//��������
// 1.��O(n)��ʱ��ɨ��һ���������� A����ȡ��Сֵ min �����ֵ max
// 2.����һ���µĿռ䴴���µ����� B������Ϊ(max - min + 1)
// 3.���� B �� index ��Ԫ�ؼ�¼��ֵ�� A ��ĳԪ�س��ֵĴ���
// 4.������Ŀ���������У�������߼��Ǳ������� B�������ӦԪ���Լ���Ӧ�ĸ���
void Sort_Solution::CountingSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1)return;
	//�������ֵ����Сֵ
	int vmax = *max_element(data.begin(), data.end());
	int vmin = *min_element(data.begin(), data.end());
	//���ټ���������
	vector<int> count(vmax - vmin + 1, 0);
	for (auto it = data.begin(); it != data.end(); it++)
		count[*it - vmin]++;
	//��˳����
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

//Ͱ����
// 1.���ù̶������Ŀ�Ͱ��
// 2.�����ݷŵ���Ӧ��Ͱ�С�
// 3.��ÿ����Ϊ�յ�Ͱ�����ݽ�������
// 4.ƴ�Ӳ�Ϊ�յ�Ͱ�����ݣ��õ����
void Sort_Solution::BucketSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1)return;
	//�������ֵ����Сֵ
	int vmax = *max_element(data.begin(), data.end());
	int vmin = *min_element(data.begin(), data.end());
	//ȷ��ӳ����򡢳���λ
	int Bucket_number = vmax / 10 - vmin / 10 + 1;
	vector<vector<int>> bucket(Bucket_number);
	for (auto it = data.begin(); it != data.end(); it++)
		bucket[*it / Bucket_number - vmin / 10 ].push_back(*it);
	//���򣬲�����data
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

//��������
// 1.�����д��Ƚ���ֵ����������ͳһΪͬ������λ���ȣ���λ�϶̵���ǰ�油��
// 2.�����λ��ʼ�����ν���һ������
// 3.�����λ����һֱ�����λ��������Ժ�, ���оͱ��һ����������
void Sort_Solution::RadixSort(vector<int> &data)
{
	int n = data.size();
	if (n <= 1)return;
	vector<int> temp(n);
	//������ֵ�����λ���������λ��
	int vmax = *max_element(data.begin(), data.end());
	int digit = 0;
	int number = vmax;
	while (number != 0)
	{
		digit++;
		number /= 10;
	}
	//Ͱ -9��9
	vector<vector<int>> bucket(19);
	int i, j, k;
	int division = 1;
	//����digit������
	for (i = 1; i <= digit; i++)
	{
		//����ǰ�����
		for (j = 0; j < 19; j++)
			bucket[j].clear();
		//����ͳ��
		for (j = 0; j < n; j++)
		{
			k = (data[j] / division) % 10;
			bucket[k + 9].push_back(data[j]);
		}
		//���·�����data
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