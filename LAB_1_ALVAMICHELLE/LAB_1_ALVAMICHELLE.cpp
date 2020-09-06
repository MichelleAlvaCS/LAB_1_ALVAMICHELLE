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

int main() {
	int iCounter = 0;
	InventoryStruct invStorage[10];
	InventoryStruct tempStorage[11];

	iCounter = ReadFile(tempStorage, 10);
	cout << "FLag: " << iCounter << endl;

	cout << "------------------------------------------------------------------" << endl;

	cout << tempStorage[0].itemId << " " << tempStorage[0].itemName << " " << tempStorage[0].itemQuantity << " " << tempStorage[0].itemPrice << endl;
	cout << tempStorage[1].itemId << " " << tempStorage[1].itemName << " " << tempStorage[1].itemQuantity << " " << tempStorage[1].itemPrice << endl;
	cout << tempStorage[2].itemId << " " << tempStorage[2].itemName << " " << tempStorage[2].itemQuantity << " " << tempStorage[2].itemPrice << endl;
	cout << "------------------------------------------------------------------" << endl;
	system("pause");
	return 0;
}

//Returns 0 if file is read correctly. Returns -1 if file not read
int ReadFile(InventoryStruct tempStorage[], int size) {
	int inventoryCounter = 0;
	int storageSize = 10;
	string id;
	string name;
	int quantity;
	double price;
	int index = 0;
	int placeHolder = 0;
	
	//opens file
	ifstream fin;
	fin.open("Inventory.txt");

	if (!fin) {
		cout << "Error in opening file" << endl;
		return -1;
	}

	//Reads file 
	while ((fin >> id >> name >> quantity >> price) && inventoryCounter!=-1) {
		inventoryCounter++;		
	}
	placeHolder = inventoryCounter;

	if (inventoryCounter <= 0) {
		cout << "File empty or Corrupt" << endl;
		inventoryCounter = -1;
	}

	else if (inventoryCounter >= 11) {
		cout << "Too many entries" << endl;
		inventoryCounter = -1;
	}

	else {
		fin.clear();
		fin.seekg(0, ios::beg);

		while(index <= (placeHolder-1)) {
			
			fin >> tempStorage[index].itemId;
			fin >> tempStorage[index].itemName;
			if (!(fin >> tempStorage[index].itemQuantity)) {
				cout << "ItemQuantity Error" << endl;
				inventoryCounter = -1;
			}

			if (!(fin >> tempStorage[index].itemPrice)) {
				cout << "ItemPrice Error" << endl;
				inventoryCounter = -1;
			}

			index++;

		}
	}

	return inventoryCounter;
}



