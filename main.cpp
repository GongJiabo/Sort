#include<iostream>
#include"sort.h"
#include<ctime>
#include<functional>
#include<iterator>
int main()
{
	time_t c_start, c_end;
	vector<int> vec = { -50, 55,12,423,3,1,0,22,-2,-1,-22,52 };
	Sort_Solution sol;
	//
	c_start = clock();
	sol.BucketSort(vec);
	c_end = clock();
	std::cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << std::endl;
	copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
 	return 0;
}