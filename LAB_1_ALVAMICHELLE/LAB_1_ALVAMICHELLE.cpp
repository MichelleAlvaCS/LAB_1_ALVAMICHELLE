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

	//CheckData(tempStorage, 10, iCounter);
	
	cout << "------------------------------------------------------------------" << endl;
	cout << tempStorage[0].itemId << " " << tempStorage[0].itemName << " " << tempStorage[0].itemQuantity << " " << tempStorage[0].itemPrice << endl;
	cout << tempStorage[1].itemId << " " << tempStorage[1].itemName << " " << tempStorage[1].itemQuantity << " " << tempStorage[1].itemPrice << endl;
	cout << tempStorage[2].itemId << " " << tempStorage[2].itemName << " " << tempStorage[2].itemQuantity << " " << tempStorage[2].itemPrice << endl;
	cout << "------------------------------------------------------------------" << endl;
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
	while ((!fin.eof()) && (inventoryCounter <= storageSize) && (inventoryCounter !=-1)) {

			fin >> tempStorage[inventoryCounter].itemId;
			fin >> tempStorage[inventoryCounter].itemName;
	

		 if (!(fin >> tempStorage[inventoryCounter].itemQuantity)) {
			fin.clear();
			fin.ignore(200, '\n');
			cout << "Item Quantity Error" << endl;
			cout << "InventoryCounter" << inventoryCounter << endl;
			inventoryCounter = -1;
		}

		if (!(fin >> tempStorage[inventoryCounter].itemPrice)) {
			fin.clear();
			fin.ignore(200, '\n');
			cout << "Item Price Error" << endl;
			inventoryCounter = -1;
		}

		if (!fin.eof() && (inventoryCounter != -1)) {
			inventoryCounter++;
		}
	}

	if (inventoryCounter != -1)
		inventoryCounter++;

	return inventoryCounter;
}


//Returns a 1 if an error is discovered in the file. Returns 0 if no errors found.
bool CheckData(InventoryStruct tempStorage[], int size, int iCounter) {
	int errorFlag = 0;

	if (iCounter == 0) {
		cout << "Error: File is empty" << endl;
		errorFlag = -2;
	}
	if (iCounter == 11) {
		cout << "Error: File is too big" << endl;
		errorFlag = -2;
	}
	return 0;
}


/*
		if ((!fin.eof()) && inventoryCounter == 0) {
			cout << "Error: File is empty" << endl;
			inventoryCounter = -1;
		}*/

		//else if (!fin.eof() && inventoryCounter != 11) {
		//	cout << "Error: File is too big" << endl;
		//	inventoryCounter = -1;
		//}