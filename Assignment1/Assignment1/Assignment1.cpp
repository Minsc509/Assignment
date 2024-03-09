// Assignment1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <cctype> 

// include other headers if needed
using namespace std;

bool isNumber(string str) {
	for (char c : str) {
		if (isdigit(c))
			return true;
	}
	return false;
}

void process(vector<string>& v) {
	// implement your code here

	if (v.empty())
	{
		return;
	}

	for (int count = v.size() - 1; count >= 0; count--) {
		// remove strings that contain digits
		if (isNumber(v[count])) {
			v.erase(v.begin() + count);
			continue;
		}

		// convert other characters into upper case
		transform(v[count].begin(), v[count].end(), v[count].begin(), ::toupper);
	}
}

void output(const vector<string>& v) {
	// implement your code here
	if (v.empty())
	{
		return;
	}

	// print the strings and separate them with comma
	for (size_t count = 0; count < v.size()-1; count++) {
		cout << v[count] << ", ";
	}
	cout << v[v.size() - 1] << endl;
}

int main()
{
	vector<string> v = { "456", "abc", "123", "456", "xyz", "123" };
	cout << "Before: "; output(v);
	process(v);
	cout << "After: "; output(v);
	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
