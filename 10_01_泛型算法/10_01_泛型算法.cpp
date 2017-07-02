// 10_01_�����㷨.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//����find�ҵ�����ָ��Ԫ��Index
	auto it = v.cbegin();
	for (; it != v.cend();)
	{
		it = find(it, v.cend(), 1); //find���ص�һ��=1�ĵ�����
		cout << (it - v.cbegin()) << endl;
		it++;
	}
#pragma endregion
	//find_if
	it = v.cbegin();
	for (; it != v.cend();)
	{
		it = find_if(it, v.cend(), [](int i) {return i >= 2 && i <= 3; }); //find_if���ص�һ�����������ĵ�����
		cout << (it - v.cbegin()) << endl;
		if(it==v.cend()) break;
		it++;
	}


	//count
	cout << count(v.begin(), v.end(), 1) << endl; //4

	//accumulate
	cout << accumulate(v.begin(), v.end(), 0) << endl; //��ʼֵ0���������ɼ�
	vector<string> v1 = { "a","b","c" };
	cout << accumulate(v1.begin(), v1.end(), string("")) << endl; //��ֵһ��Ҫ�Ƕ���Ȼ����ֵ���ܼ�

	vector<int> v2 = { 1,2,3,4,556,1,1,2,1 ,1,1,1 };
	cout << equal(v.cbegin(), v.cend(), v2.cbegin()) << endl; //���1����ǰһ������ȵ�

	//fill��fill_n
	fill(v2.begin(), v2.end(), 0); //�ϵ�鿴
	fill_n(v2.begin(), 2, 1); //��begin()��������ֵ��Ϊ1

	//back_inserter
	vector<int> v3; //������
	//fill_n(v3.begin(), 10, 0); //ֱ��fill�ᱨ��
	fill_n(back_inserter(v3), 10, 0); //


	//copy �� copy_if
	vector<int> v4,v4_1;
	copy(v3.cbegin(), v3.cend(), back_inserter(v4)); //���ؿ�����ȥ�����һ��Ԫ�صĺ���
	v3[1] = 5; v3[2] = 6; v3[7] = 10;
	copy_if(v3.begin(), v3.end(), back_inserter(v4_1), [](int i) {return i >= 5; });


	//replace
	vector<int> v5 = { 1,2,3,4,556,1,1,2,1 ,1,1,1 };
	replace(v5.begin(), v5.end(), 1, 11); //�滻����1Ϊ11
	//replace_if()

	//sort,unique
	vector<int> v6 = { 3,4,1,2,5,1,3,2,5,3};
	//sort(v6.begin(), v6.end());
	sort(v6.begin(), v6.end(), [](int a1, int a2) {return a1 > a2; }); //���Դ���һ��ν�ʣ��������ȽϷ�ʽ���������Ϊ����
	auto firstRepeat = unique(v6.begin(), v6.end()); //unique��vector������ظ���Ԫ���Ƶ�����(�Ƚ���sort����)��ǰ��ֻ�������ظ���Ԫ��
	cout << firstRepeat - v6.begin() << endl;//���ص��ǵ�һ���ظ�Ԫ�ص�iterator
	v6.erase(firstRepeat, v6.end()); //��Ҫ�ٸ�erase����ɾ��
	//unique���÷���remove,remove_ifһ��������ֻ�ƶ�Ԫ�أ���û������ɾ��

	//sortʹ��ν��
	vector<int> v7 = { 3,4,1,2,5,1,3,2,5,3 };
	sort(v7.begin(), v7.end(), isBigger);

	//lambda���ʽ
	vector<int> v8 = { 3,4,1,2,5,1,3,2,5,3 };
	sort(v8.begin(), v8.end(), [] (int a, int b) {return a > b; });

	vector<string> v9 = { "abc","defg","hdsaddas" };
	int sz = 3;
	auto it9 = find_if(v9.begin(), v9.end(), [sz](const string &a) {return a.size() > sz; });//���Բ���ͬ������ı���
	cout << it9 - v9.begin() << endl;

	//for_each���lambda���ʽʵ�ָ��ֹ��ܣ�Ҳ����ʵ���޸�,�������ã�
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
	auto it_11  = count(v11.begin(), v11.end(), 3); // 3��
	auto it_11_1 = count_if(v11.begin(), v11.end(), [](int i) {return i == 3; });

	//min_element
	auto it_11_2 = min_element(v11.begin(), v11.end());//���ص�����
	auto it_11_3 = max_element(v11.begin(), v11.end());

	//transform ��һ�������ƶ�����һ������ȥ���ڼ���Խ��б任�����Ǻ�copy��ͬ�ĵط�

	system("pause");
    return 0;
}



