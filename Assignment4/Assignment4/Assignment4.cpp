// Assignment4.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>

class Product {
public:
	// Constructor to initialize
	Product(const std::string& name, float price, int type, int units = 0, float kgs = 0.0)
		: selling(name), unitPrice(price), unitType(type), amount(units), weight(kgs) {}

	// Display product
	void displayInfo() const {
		std::cout << "\n" << selling << std::endl;
		switch (unitType) {
		case 1:
			std::cout << "We have " << amount << " units for sale\n";
			break;
		case 2:
			std::cout << "We have " << weight << " kgs for sale\n";
			break;
		default:
			std::cout << "Invalid unitType\n";
		}
	}

private:
	std::string selling;
	float unitPrice;
	int unitType;
	int amount;
	float weight;
};

int main() {
	Product dieselMotorBike("A Diesel Motor Cycle", 5488.00, 1, 4);
	Product apples("Granny duBois", 0.78, 2, 0, 0.5);
	Product* myEbayStore[2] = { &dieselMotorBike, &apples };

	for (int i = 0; i < 2; ++i) {
		myEbayStore[i]->displayInfo();
	}

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
