// Assignment3.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <cstring>

class String {
public:
	// Constructor
	String();
	String(const char* str);

	// Destructor
	~String(); 

	// Implement = operator
	String& operator=(const String& other);

	// Implement + operator
	String operator+(const String& other) const; 

	// Implement [] operator
	char& operator[](int index) const;

	// Get the size of the string
	int size() const { return size_; }

	// Implement << operator
	friend std::ostream& operator<<(std::ostream& out, const String& str) {
		out << str.data_;
		return out;
	}

private:
	char* data_; // Pointer to the character array
	int size_;   // Size of the string
};


// Constructor with no arguments
String::String()
{
	data_ = nullptr;
	size_ = 0;
}

// Constructor with initial string
String::String(const char* str) {
	if (str == nullptr) {
		data_ = nullptr;
		size_ = 0;
		return;
	}
	size_ = std::strlen(str) + 1;
	data_ = new char[size_];
	strcpy_s(data_, size_, str);
	data_[size_ - 1] = '\0';
}

// Destructor
String::~String() {
	delete[] data_;
}

// Implement = operator
String& String::operator=(const String& newStr) {
	if (this != &newStr) { // Avoid self-assignment
		delete[] data_;
		size_ = newStr.size_;
		data_ = new char[size_];
		strcpy_s(data_, size_, newStr.data_);
		data_[size_ - 1] = '\0';
	}
	return *this;
}

// Implement + operator
String String::operator+(const String& addStr) const {
	int newSize = size_ + addStr.size_ - 1;
	char* newData = new char[newSize];
	strncpy_s(newData, newSize, data_, size_);
	strncat_s(newData, newSize, addStr.data_, addStr.size_);
	return String(newData);
}

// Implement [] operator
char& String::operator[](int index) const {
	if (index >= 0 && index < size_) {
		return data_[index];
	}
	throw std::out_of_range("Index out of bounds");
}


int main() {
	String s1("Hello World.");
	String s2("Goodbye!");
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	String s3 = s1 + s2;
	std::cout << "s3: " << s3 << std::endl;
	std::cout << "The last char of s3: " << s3[s3.size() - 1] << std::endl;
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
