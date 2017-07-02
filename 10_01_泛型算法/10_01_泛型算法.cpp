// 10_01_泛型算法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric> //accumulate
#include <iterator> //back_inserter

using namespace std;
bool isBigger(int a, int b) { return a > b; }
int main()
{


#pragma region find
	vector<int> v = { 1,2,3,4,556,1,1,2,1 };

	//利用find找到所有指定元素Index
	auto it = v.cbegin();
	for (; it != v.cend();)
	{
		it = find(it, v.cend(), 1); //find返回第一个=1的迭代器
		cout << (it - v.cbegin()) << endl;
		it++;
	}
#pragma endregion
	//find_if
	it = v.cbegin();
	for (; it != v.cend();)
	{
		it = find_if(it, v.cend(), [](int i) {return i >= 2 && i <= 3; }); //find_if返回第一个满足条件的迭代器
		cout << (it - v.cbegin()) << endl;
		if(it==v.cend()) break;
		it++;
	}


	//count
	cout << count(v.begin(), v.end(), 1) << endl; //4

	//accumulate
	cout << accumulate(v.begin(), v.end(), 0) << endl; //初始值0，对象必须可加
	vector<string> v1 = { "a","b","c" };
	cout << accumulate(v1.begin(), v1.end(), string("")) << endl; //初值一定要是对象不然字面值不能加

	vector<int> v2 = { 1,2,3,4,556,1,1,2,1 ,1,1,1 };
	cout << equal(v.cbegin(), v.cend(), v2.cbegin()) << endl; //输出1，在前一段是相等的

	//fill和fill_n
	fill(v2.begin(), v2.end(), 0); //断点查看
	fill_n(v2.begin(), 2, 1); //从begin()后面两个值设为1

	//back_inserter
	vector<int> v3; //空容器
	//fill_n(v3.begin(), 10, 0); //直接fill会报错
	fill_n(back_inserter(v3), 10, 0); //


	//copy 和 copy_if
	vector<int> v4,v4_1;
	copy(v3.cbegin(), v3.cend(), back_inserter(v4)); //返回拷贝过去的最后一个元素的后面
	v3[1] = 5; v3[2] = 6; v3[7] = 10;
	copy_if(v3.begin(), v3.end(), back_inserter(v4_1), [](int i) {return i >= 5; });


	//replace
	vector<int> v5 = { 1,2,3,4,556,1,1,2,1 ,1,1,1 };
	replace(v5.begin(), v5.end(), 1, 11); //替换所有1为11
	//replace_if()

	//sort,unique
	vector<int> v6 = { 3,4,1,2,5,1,3,2,5,3};
	//sort(v6.begin(), v6.end());
	sort(v6.begin(), v6.end(), [](int a1, int a2) {return a1 > a2; }); //可以传递一个谓词，来调整比较方式，这里调整为降序
	auto firstRepeat = unique(v6.begin(), v6.end()); //unique把vector里面的重复的元素移到后面(先进行sort才行)，前面只保留不重复的元素
	cout << firstRepeat - v6.begin() << endl;//返回的是第一个重复元素的iterator
	v6.erase(firstRepeat, v6.end()); //需要再跟erase进行删除
	//unique的用法和remove,remove_if一样，都是只移动元素，并没有真正删除

	//sort使用谓词
	vector<int> v7 = { 3,4,1,2,5,1,3,2,5,3 };
	sort(v7.begin(), v7.end(), isBigger);

	//lambda表达式
	vector<int> v8 = { 3,4,1,2,5,1,3,2,5,3 };
	sort(v8.begin(), v8.end(), [] (int a, int b) {return a > b; });

	vector<string> v9 = { "abc","defg","hdsaddas" };
	int sz = 3;
	auto it9 = find_if(v9.begin(), v9.end(), [sz](const string &a) {return a.size() > sz; });//可以捕获同作用域的变量
	cout << it9 - v9.begin() << endl;

	//for_each结合lambda表达式实现各种功能（也可以实现修改,传递引用）
	vector<int> v10 = { 3,4,1,2,5,1,3,2,5,3 };
	for_each(v10.begin(), v10.end(), [](int a) {if (a > 3) cout << a << "|"; });
	for_each(v10.begin(), v10.end(), [](int& a) {a++; });
	for_each(v10.begin(), v10.end(), [](int a) {cout << a << "|"; });
	cout << endl;

	//random_shuffle
	random_shuffle(v10.begin(), v10.end());
	for_each(v10.begin(), v10.end(), [](int a) {cout << a << "|"; });
	cout << endl;


	//count
	vector<int> v11 = { 3,4,1,2,5,1,3,2,5,3 };
	auto it_11  = count(v11.begin(), v11.end(), 3); // 3个
	auto it_11_1 = count_if(v11.begin(), v11.end(), [](int i) {return i == 3; });

	//min_element
	auto it_11_2 = min_element(v11.begin(), v11.end());//返回迭代器
	auto it_11_3 = max_element(v11.begin(), v11.end());

	//transform 将一段数据移动到另一个容器去，期间可以进行变换，这是和copy不同的地方

	system("pause");
    return 0;
}



