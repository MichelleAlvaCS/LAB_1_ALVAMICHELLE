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

int ReadFile(InventoryStruct tempArray[], int size);
bool CheckData(InventoryStruct tempStorage[], int size, int iCounter);

int main() {
	int iCounter = 0;
	InventoryStruct invStorage[10];
	InventoryStruct tempStorage[11];

	iCounter = ReadFile(tempStorage, 10);
	cout << "FLag: " << iCounter << endl;

	CheckData(tempStorage, 10, iCounter);

	cout << tempStorage[0].itemId << " " << tempStorage[0].itemName << " " << tempStorage[0].itemQuantity << " " << tempStorage[0].itemPrice << endl;

	system("pause");
	return 0;
}

//Returns file inventory amount if file is read correctly. Returns -1 if file not read
int ReadFile(InventoryStruct tempStorage[], int size) {
	int inventoryCounter = 0;
	int storageSize = 10; 

	//opens file
	ifstream fin;
	fin.open("Inventory.txt");

	if (!fin) {
		cout << "Error in opening file" << endl;
		return -1;
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
	return inventoryCounter;
}

//Returns a 1 if an error is discovered in the file. Returns 0 if no errors found.
bool CheckData(InventoryStruct tempStorage[], int size, int iCounter) {
	int errorFlag = 0;

	if (iCounter == 0) {
		cout << "Error: File is empty" << endl;
		errorFlag = 1;
	}
	if (iCounter == 11) {
		cout << "Error: File is too big" << endl;
		errorFlag = 1;
	}


	// WORKING ON ERROR CHECKING IDCOUNTER AND ITEMPRICE****************************************************************

	return 0;
}


