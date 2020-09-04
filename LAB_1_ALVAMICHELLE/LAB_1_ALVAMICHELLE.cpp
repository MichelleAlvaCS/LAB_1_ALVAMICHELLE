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


bool CheckData(InventoryStruct *passedStruct);

int main() {
	int inventorySize = 0; 


	InventoryStruct invStorage[10];
	InventoryStruct tempStorage[10];

	tempStorage[0].itemQuantity = 89;

	CheckData(tempStorage);

	cout << tempStorage[0].itemId << " " << tempStorage[0].itemName << " " << tempStorage[0].itemQuantity << " " << tempStorage[0].itemPrice << endl;


	system("pause");
	return 0;
}



bool CheckData(InventoryStruct tempStorage[]) {
	int inventorySize = 0;
	int valueCheck = 1;

	//opens file
	ifstream fin;
	fin.open("Inventory.txt");

	if (!fin) {
		cout << "Error in opening file" << endl;
		return 0;
	}

	//reads file and stores into temp struct
	while (!fin.eof()) {

		for (int i = 0; i < 10; i++) {

			fin >> tempStorage[i].itemId;
			fin >> tempStorage[i].itemName;
			fin >> tempStorage[i].itemQuantity;
			fin >> tempStorage[i].itemPrice;



			inventorySize++;

			//error checks part 1

			while (! (fin >> tempStorage[i].itemQuantity)) {
				cout << "ERROR: itemQuantity not entered correctly. " << endl;
				return 1;
			}

	/*		if ((fin >> tempStorage[i].itemPrice)) {
				cout << "ERROR: itemPrice not entered correctly. " << endl;
				return 1;
			}*/



		}
	}

    //error checks part 2
	if (inventorySize > 10) {
		cout << "WARNING: File size exceeded storage capability. Only first ten items stored." << endl;
		return 0;
	}
	else if (inventorySize == 0) {
		cout << "ERROR: No inventory items found << endl;" << endl;
		return 1;
	}

	return 0;
}

