#include <bits/stdc++.h>

using namespace std;

struct student
{
	int fn;
	string name;
	double grade;
};

bool cmp(const student& l, const student& r)
{
	if(l.grade > r.grade)return true;
	if(l.grade < r.grade)return false;
	return l.fn < r.fn;
}

int main()
{
	student arr[10];
	arr[0] = {405, "aa", 5.63};
	arr[1] = {303, "bb", 6.00};
	arr[2] = {407, "cc", 3.00};
	arr[3] = {603, "dd", 6.00};
	
	sort(arr, arr + 4, cmp);
	for(int i = 0; i < 4; i++)cout << arr[i].fn << " " << 
							arr[i].name << " " << arr[i]. grade << endl;
	
	return 0;
}
