//LAB 1 ALVA, Michelle T TH

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//structure
struct InventoryStruct {
	string itemId;
	string itemName;
	int itemQuantity;
	double itemPrice;

};

bool ReadFile(InventoryStruct tempStorage[]);

int main() {

	InventoryStruct invStorage[10];
	InventoryStruct tempStorage[11];

	ReadFile(tempStorage);

	cout << tempStorage[0].itemId << " " << tempStorage[0].itemName << " " << tempStorage[0].itemQuantity << " " << tempStorage[0].itemPrice << endl;

	system("pause");
	return 0;
}

bool ReadFile(InventoryStruct tempStorage[]) {
	int inventoryCounter = 0;
	int storageSize = 10; 

	//opens file
	ifstream fin;
	fin.open("Inventory.txt");

	if (!fin) {
		cout << "Error in opening file" << endl;
		return 1;
	}

	//reads file and stores into temp struct
	while (!fin.eof() && (inventoryCounter <= storageSize)) {

			fin >> tempStorage[inventoryCounter].itemId;
			fin >> tempStorage[inventoryCounter].itemName;
			fin >> tempStorage[inventoryCounter].itemQuantity;
			fin >> tempStorage[inventoryCounter].itemPrice;

			if (!fin.eof())
			inventoryCounter++;
		}



	cout << "Inventory Size: " << inventoryCounter << endl;

	return 0;
}
