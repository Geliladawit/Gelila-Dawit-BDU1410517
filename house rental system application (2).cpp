#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct house{
	int house_no;
	char owner_name[20];
	char tenant_name[20];
	int no_of_floors;
	int no_of_rooms;
	float payment_amount;
	char state[20];
	char city[20];
	house *next;
	house *prev;
};
house *start=NULL;
house *back=NULL;
//question 1
void insertAtBeginningFromFile() {
	char txtFile[20];
	cout<<"enter the file name you want to insert from.\nBECAREFUL YOU HAVE TO INSERT A .TXT FILE WITH A PROPER FORMAT: ";
	cin>>txtFile;
    ifstream file(txtFile);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    house* newHouse=new house;
    while (file >> newHouse->house_no >> newHouse->owner_name >> newHouse->tenant_name >> newHouse->no_of_floors >> newHouse->no_of_rooms >> newHouse->payment_amount >> newHouse->state >> newHouse->city) {
        newHouse->next = start;
        newHouse->prev = NULL;
        if (start != NULL) {
            start->prev = newHouse;
        }
        else {
            back = newHouse;
        }
        start = newHouse;
        newHouse = new house;
    }

    file.close();
    cout << "Nodes inserted at the beginning of the linked list from the file" << endl;
}
void insertAtEnd() { //question 2
	int numberOfnodes;
	cout<<"how many houses do you want to enter: ";
	cin>>numberOfnodes;
    for(int i=1;i<=numberOfnodes;i++){
		house *newNode = new house();
    	cout << "Enter house number: ";
    	cin >> newNode->house_no;

    	while (true) {
        	bool duplicateHouseNo = false;
        	house *current = start;
        	while (current != NULL) {
            	if (current->house_no == newNode->house_no) {
                	cout << "House number " << newNode->house_no << " already exists in the list!" << endl;
                	duplicateHouseNo = true;
                	break;
            	}
            	current = current->next;
        	}
        	if (!duplicateHouseNo) {
            	break;
        	}
        	cout << "Enter a new house number: ";
        	cin >> newNode->house_no;
    	}

    	cout << "Enter owner name: ";
    	cin >> newNode->owner_name;
    	cout << "Enter tenant name: ";
    	cin >> newNode->tenant_name;
    	cout << "Enter number of floors: ";
    	cin >> newNode->no_of_floors;
    	cout << "Enter number of rooms: ";
    	cin >> newNode->no_of_rooms;
    	cout << "Enter payment amount: ";
    	cin >> newNode->payment_amount;
    	cout << "Enter state: ";
    	cin >> newNode->state;
    	cout << "Enter city: ";
    	cin >> newNode->city;

    newNode->next = NULL;
    newNode->prev = NULL;
    if (start == NULL) {
        start = back = newNode;
    } else {
        back->next = newNode;
        newNode->prev = back;
        back = newNode;
    }
    cout << "New house added to the back of the list!" << endl;
	}
}
void addNodeAfterHouseNo() {//question 3
	int houseNo;
	cout<<"enter house number to enter the new information after: ";
	cin>>houseNo;
    house *current = start;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            house *newNode = new house();
            cout << "Enter new house number: ";
            cin >> newNode->house_no;
            while (true) {
                bool foundHouseNo = false;
                house *current2 = start;
                while (current2 != NULL) {
                    if (current2->house_no == newNode->house_no) {
                        cout << "House number " << newNode->house_no << " already exists in the list!" << endl;
                        foundHouseNo = true;
                        break;
                    }
                    current2 = current2->next;
                }
                if (!foundHouseNo) {
                    break;
                }
                cout << "Enter a new house number: ";
                cin >> newNode->house_no;
            }

            cout << "Enter owner name: ";
            cin >> newNode->owner_name;
            cout << "Enter tenant name: ";
            cin >> newNode->tenant_name;
            cout << "Enter number of floors: ";
            cin >> newNode->no_of_floors;
            cout << "Enter number of rooms: ";
            cin >> newNode->no_of_rooms;
            cout << "Enter payment amount: ";
            cin >> newNode->payment_amount;
            cout << "Enter state: ";
            cin >> newNode->state;
            cout << "Enter city: ";
            cin >> newNode->city;

            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            } else {
                back = newNode;
            }
            current->next = newNode;
            cout << "New house added after house number " << houseNo << "!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "House number " << houseNo << " not found in the list!" << endl;
}
void deleteFirstNode() {//question 4
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    house *nodeToDelete = start;
    start = nodeToDelete->next;
    if (start != NULL) {
        start->prev = NULL;
    } else {
        back = NULL;
    }
    delete nodeToDelete;

    cout << "The first house node has been deleted!" << endl;
}
void deleteLastNode() {//question 5
    if (back == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    house *nodeToDelete = back;
    back = nodeToDelete->prev;
    if (back != NULL) {
        back->next = NULL;
    } else {
        start = NULL;
    }
    delete nodeToDelete;

    cout << "The last house node has been deleted!" << endl;
}
void deleteByHouseNo() {//question 6.1
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    int houseNo;
    cout << "Enter house number to delete: ";
    cin >> houseNo;

    house *current = start;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            if (current == start) {
                start = current->next;
                if (start != NULL) {
                    start->prev = NULL;
                } else {
                    back = NULL;
                }
            } else if (current == back) {
                back = current->prev;
                if (back != NULL) {
                    back->next = NULL;
                } else {
                    start = NULL;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "House with house number " << houseNo << " has been deleted!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "House with house number " << houseNo << " not found in the list!" << endl;
}
void deleteByOwnerName() {//question 6.2
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    string ownerName;
    cout << "Enter owner name to delete: ";
    cin >> ownerName;

    house *current = start;
    while (current != NULL) {
        if (current->owner_name == ownerName) {
            if (current == start) {
                start = current->next;
                if (start != NULL) {
                    start->prev = NULL;
                } else {
                    back = NULL;
                }
            } else if (current == back) {
                back = current->prev;
                if (back != NULL) {
                    back->next = NULL;
                } else {
                    start = NULL;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "House with owner name " << ownerName << " has been deleted!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "House with owner name " << ownerName << " not found in the list!" << endl;
}
void deleteByTenantName() {// question 6.3
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    string tenantName;
    cout << "Enter tenant name to delete: ";
    cin >> tenantName;

    house *current = start;
    while (current != NULL) {
        if (current->tenant_name == tenantName) {
            if (current == start) {
                start = current->next;
                if (start != NULL) {
                    start->prev = NULL;
                } else {
                    back = NULL;
                }
            } else if (current == back) {
                back = current->prev;
                if (back != NULL) {
                    back->next = NULL;
                } else {
                    start = NULL;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "House with tenant name " << tenantName << " has been deleted!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "House with tenant name " << tenantName << " not found in the list!" << endl;
}
void deleteByNumberOfFloors() {//quesiton 6.4
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    int numFloors;
    cout << "Enter number of floors to delete: ";
    cin >> numFloors;

    house *current = start;
    while (current != NULL) {
        if (current->no_of_floors == numFloors) {
            if (current == start) {
                start = current->next;
                if (start != NULL) {
                    start->prev = NULL;
                } else {
                    back = NULL;
                }
            } else if (current == back) {
                back = current->prev;
                if (back != NULL) {
                    back->next = NULL;
                } else {
                    start = NULL;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "House with " << numFloors << " floors has been deleted!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "House with " << numFloors << " floors not found in the list!" << endl;
}
void deleteByNumberOfRooms() {//question 6.5
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    int numRooms;
    cout << "Enter number of rooms to delete: ";
    cin >> numRooms;

    house *current = start;
    while (current != NULL) {
        if (current->no_of_rooms == numRooms) {
            if (current == start) {
                start = current->next;
                if (start != NULL) {
                    start->prev = NULL;
                } else {
                    back = NULL;
                }
            } else if (current == back) {
                back = current->prev;
                if (back != NULL) {
                    back->next = NULL;
                } else {
                    start = NULL;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "House with " << numRooms << " rooms has been deleted!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "House with " << numRooms << " rooms not found in the list!" << endl;
}
void deleteByPaymentAmount() {//question 6.6
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    double paymentAmount;
    cout << "Enter payment amount to delete: ";
    cin >> paymentAmount;

    house *current = start;
    while (current != NULL) {
        if (current->payment_amount == paymentAmount) {
            if (current == start) {
                start = current->next;
                if (start != NULL) {
                    start->prev = NULL;
                } else {
                    back = NULL;
                }
            } else if (current == back) {
                back = current->prev;
                if (back != NULL) {
                    back->next = NULL;
                } else {
                    start = NULL;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "House with payment amount " << paymentAmount << " has been deleted!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "House with payment amount " << paymentAmount << " not found in the list!" << endl;
}

void deleteByState() {//question 6.7
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    string state;
    cout << "Enter state to delete: ";
    cin >> state;

    house *current = start;
    while (current != NULL) {
        if (strcmp(current->state, state.c_str()) == 0) {
            if (current == start) {
                start = current->next;
                if (start != NULL) {
                    start->prev = NULL;
                } else {
                    back = NULL;
                }
            } else if (current == back) {
                back = current->prev;
                if (back != NULL) {
                    back->next = NULL;
                } else {
                    start = NULL;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "House in " << state << " has been deleted!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "House in " << state << " not found in the list!" << endl;
}
void deleteByCity() {//question 6.8
    if (start == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    string city;
    cout << "Enter city to delete: ";
    cin >> city;

    house *current = start;
    while (current != NULL) {
        if (strcmp(current->city, city.c_str()) == 0) {
            if (current == start) {
                start = current->next;
                if (start != NULL) {
                    start->prev = NULL;
                } else {
                    back = NULL;
                }
            } else if (current == back) {
                back = current->prev;
                if (back != NULL) {
                    back->next = NULL;
                } else {
                    start = NULL;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "House in " << city << " has been deleted!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "House in " << city << " not found in the list!" << endl;
}
//question 7
void deleteNthNode() {
    int n;
    cout << "Enter the node number you want to delete: ";
    cin >> n;
    if (start == NULL) {
        return;
    }
    if (n == 1) {
        house* temp = start;
        start = start->next;
        if (start) {
            start->prev = NULL;
        }
        delete temp;
        return;
    }
    house* prev_node = NULL;
    house* i = start;
    int count = 1;
    while (i && count != n) {
        prev_node = i;
        i = i->next;
        count++;
    }
    if (i == NULL) {
        return;
    }
    prev_node->next = i->next;
    if (i->next) {
        i->next->prev = prev_node;
    }
    delete i;
}
//question 8
void minpayment(){
	struct house *current=start;
	for(struct house *i=start->next;i!=NULL;i=i->next){ 
	if(current->payment_amount>i->payment_amount)	
		current=i;
	}
	cout<<"The house that costs minimum payment  is:"<<endl;
	cout << "House Number: " << current->house_no << endl;
    cout << "Owner Name: " << current->owner_name << endl;
    cout << "Tenant Name: " << current->tenant_name << endl;
    cout << "Number of Floors: " << current->no_of_floors << endl;
    cout << "Number of Rooms: " << current->no_of_rooms << endl;
    cout << "Payment Amount: " << current->payment_amount << endl;
    cout << "State: " << current->state << endl;
    cout << "City: " << current->city << endl;
    cout << endl;
}
// question 9
void maxpayment(){
	struct house *current=start;
	for(struct house *i=start->next;i!=NULL;i=i->next)
	{ 
	if(current->payment_amount<i->payment_amount)	
		current=i;
	}
	cout<<"The house that costs minimum payment  is:"<<endl;
	cout << "House Number: " << current->house_no << endl;
    cout << "Owner Name: " << current->owner_name << endl;
    cout << "Tenant Name: " << current->tenant_name << endl;
    cout << "Number of Floors: " << current->no_of_floors << endl;
    cout << "Number of Rooms: " << current->no_of_rooms << endl;
    cout << "Payment Amount: " << current->payment_amount << endl;
    cout << "State: " << current->state << endl;
    cout << "City: " << current->city << endl;
    cout << endl;
}
// Question 10
void averageroom(){
    cout << "The average number of rooms is: ";
    double ave, n = start->no_of_rooms, j = 1;
    for(struct house *i = start->next; i != NULL; i = i->next) {
        n = i->no_of_rooms + n;
        j++;
    }
    ave = n / j;
    cout << ave;
}

// Question 11
void avepayment() {
    cout << "The average payment amount is: ";
    double ave, n = start->payment_amount, j = 1;
    for(struct house *i = start->next; i != NULL; i = i->next) {
        n = i->payment_amount + n;
        j++;
    }
    ave = n / j;
    cout << ave;
}
//question 12
void deleteminfloor() {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    struct house *min = start;
    for (struct house *i = start->next; i != NULL; i = i->next) {
        if (min->no_of_floors > i->no_of_floors) {
            min = i;
        }
    }
    if (min == start) {
        start = min->next;
        if (start != NULL) {
            start->prev = NULL;
        }
    } 
	else if (min == back) {
        back = min->prev;
        if (back != NULL) {
            back->next = NULL;
        }
    } 
	else{
	    min->prev->next = min->next;
	    min->next->prev = min->prev;
	}
	delete min;
	cout<<"deleted the house with the minimum floors";
}
//question 13
void deletemaxfloor() {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    struct house *max = start;
    for (struct house *i = start->next; i != NULL; i = i->next) {
        if (max->no_of_floors < i->no_of_floors) {
            max = i;
        }
    }
    if (max == start) {
        start = max->next;
        if (start != NULL) {
            start->prev = NULL;
        }
    } 
	else if (max == back) {
        back = max->prev;
        if (back != NULL) {
            back->next = NULL;
        }
    } 
	else {
        max->prev->next = max->next;
        max->next->prev = max->prev;
    }
    delete max;
    cout<<"deleted the house with the maximum floors";
}
//question 14.1
void searchbyhouse_no() {
    if (start == NULL) {
        cout << "DLL is empty";
    } else {
        int found = 0;
        int key;
        cout << endl << "Enter the house number you want to search: ";
        cin >> key;
        house *i=new house;
        for (i = start; i != NULL; i = i->next) {
            if (key == i->house_no) {
                found = 1;
            }
        }
        if (found == 0) {
            cout << "It is not found in the list";
        } else if (found == 1) {
            cout << "Here is the information about the house:" << endl;
            cout << "-----------------" << endl;
            cout << i->house_no << endl;
            cout << i->owner_name << endl;
            cout << i->tenant_name << endl;
            cout << i->no_of_floors << endl;
            cout << i->no_of_rooms << endl;
            cout << i->payment_amount << endl;
            cout << i->state << endl;
            cout << i->city << endl;
            cout << "----------------" << endl;
        }
    }
}
//question 14.2
void searchbyowner_name() {
    if (start == NULL) {
        cout << "DLL is empty";
    } else {
        int found = 0;
        char key[20];
        cout << endl << "Enter name to be searched: ";
        cin >> key;
        house *i=new house;
        for (i = start; i != NULL; i = i->next) {
            if (strcmp(key, i->owner_name) == 0) {
                found = 1;
            }
        }
        if (found == 0) {
            cout << "It is not found in the list";
            
        } else if (found == 1) {
        	cout << "Here is the information about the house:" << endl;
            cout << "-----------------" << endl;
            cout << i->house_no << endl;
            cout << i->owner_name << endl;
            cout << i->tenant_name << endl;
            cout << i->no_of_floors << endl;
            cout << i->no_of_rooms << endl;
            cout << i->payment_amount << endl;
            cout << i->state << endl;
            cout << i->city << endl;
            cout << "----------------" << endl;
        }
    }
}
//question 14.3
void searchbytenant_name() {
    if (start == NULL) {
        cout << "DLL is empty";
    } else {
        int found = 0;
        char key[20];
        cout << endl << "Enter name to be searched: ";
        cin >> key;
        house *i=new house;
        for (i = start; i != NULL; i = i->next) {
            if (strcmp(key, i->tenant_name) == 0) {
                found = 1;
            }
        }
        if (found == 0) {
            cout << "It is not found in the list";
        } else if (found == 1) {
        	cout << "Here is the information about the house:" << endl;
            cout << "-----------------" << endl;
            cout << i->house_no << endl;
            cout << i->owner_name << endl;
            cout << i->tenant_name << endl;
            cout << i->no_of_floors << endl;
            cout << i->no_of_rooms << endl;
            cout << i->payment_amount << endl;
            cout << i->state << endl;
            cout << i->city << endl;
            cout << "----------------" << endl;
        }
    }
}
//question 14.4
void searchbyno_of_floors() {
    if (start == NULL) {
        cout << "DLL is empty";
    } else {
        int found = 0;
        int key;
        cout << endl << "Enter the number of floors you wish to have: ";
        cin >> key;
        house *i=new house;
        for (i = start; i != NULL; i = i->next) {
            if (key == i->no_of_floors) {
                found = 1;
            }
        }
        if (found == 0) {
            cout << "It is not found in the list";
        } else if (found == 1) {
        	cout << "Here is the information about the house:" << endl;
            cout << "-----------------" << endl;
            cout << i->house_no << endl;
            cout << i->owner_name << endl;
            cout << i->tenant_name << endl;
            cout << i->no_of_floors << endl;
            cout << i->no_of_rooms << endl;
            cout << i->payment_amount << endl;
            cout << i->state << endl;
            cout << i->city << endl;
            cout << "----------------" << endl;
        }
    }
}
//qyestion 14.5
void searchbyno_of_rooms() {
    if (start == NULL) {
        cout << "DLL is empty";
    } else {
        int found = 0;
        int key;
        cout << endl << "Enter the number of rooms you wish to have: ";
        cin >> key;
        for (house *i = start; i != NULL; i = i->next) {
            if (key == i->no_of_rooms) {
                found = 1;
                if (found == 0) {
                    cout << "It is not found in the list";
                } else if (found == 1) {
                	cout << "Here is the information about the house:" << endl;
                    cout << "-----------------" << endl;
                    cout << i->house_no << endl;
                    cout << i->owner_name << endl;
                    cout << i->tenant_name << endl;
                    cout << i->no_of_floors << endl;
                    cout << i->no_of_rooms << endl;
                    cout << i->payment_amount << endl;
                    cout << i->state << endl;
                    cout << i->city << endl;
                    cout << "----------------" << endl;
                }
            }
        }
    }
}
//qyestion 14.6
void searchbypayment_amount() {
    if (start == NULL) {
        cout << "DLL is empty";
    } else {
        int found = 0;
        float key;
        cout << endl << "Enter the amount you wish to pay: ";
        cin >> key;
        for (house *i = start; i != NULL; i = i->next) {
            if (key == i->payment_amount) {
                found = 1;
                if (found == 0) {
                    cout << "It is not found in the list";
                } else if (found == 1) {
                	cout << "Here is the information about the house:" << endl;
                    cout << "-----------------" << endl;
                    cout << i->house_no << endl;
                    cout << i->owner_name << endl;
                    cout << i->tenant_name << endl;
                    cout << i->no_of_floors << endl;
                    cout << i->no_of_rooms << endl;
                    cout << i->payment_amount << endl;
                    cout << i->state << endl;
                    cout << i->city << endl;
                    cout << "----------------" << endl;
                }
            }
        }
    }
}
//qyestion 14.7
void searchbystate() {
    if (start == NULL) {
        cout << "DLL is empty";
    } else {
        int found = 0;
        char key[20];
        cout << endl << "Enter name to be searched: ";
        cin >> key;
        for (house *i = start; i != NULL; i = i->next) {
            if (strcmp(key, i->state) == 0) {
                found = 1;
                if (found == 0) {
                    cout << "It is not found in the list";
                } else if (found == 1) {
                	cout << "Here is the information about the house:" << endl;
                    cout << "-----------------" << endl;
                    cout << i->house_no << endl;
                    cout << i->owner_name << endl;
                    cout << i->tenant_name << endl;
                    cout << i->no_of_floors << endl;
                    cout << i->no_of_rooms << endl;
                    cout << i->payment_amount << endl;
                    cout << i->state << endl;
                    cout << i->city << endl;
                    cout << "----------------" << endl;
                }
            }
        }
    }
}
//qyestion 14.8
void searchbycity() {
    if (start == NULL) {
        cout << "DLL is empty";
    } else {
        int found = 0;
        char key[20];
        cout << endl << "Enter the name of the city to be searched: ";
        cin >> key;
        for (house *i = start; i != NULL; i = i->next) {
            if (strcmp(key, i->city) == 0) {
                found = 1;
                if (found == 0) {
                    cout << "It is not found in the list";
                } else if (found == 1) {
                	cout << "Here is the information about the house:" << endl;
                    cout << "-----------------" << endl;
                    cout << i->house_no << endl;
                    cout << i->owner_name << endl;
                    cout << i->tenant_name << endl;
                    cout << i->no_of_floors << endl;
                    cout << i->no_of_rooms << endl;
                    cout << i->payment_amount << endl;
                    cout << i->state << endl;
                    cout << i->city << endl;
                    cout << "----------------" << endl;
                }
            }
        }
    }
}
//question 15.1
void displayHousesForward() {
    house *current = start;
    if(start==NULL && back==NULL){
    	cout<<"No houses entered"<<endl;
	} 
    while (current != NULL) {
        cout << "House Number: " << current->house_no << endl;
        cout << "Owner Name: " << current->owner_name << endl;
        cout << "Tenant Name: " << current->tenant_name << endl;
        cout << "Number of Floors: " << current->no_of_floors << endl;
        cout << "Number of Rooms: " << current->no_of_rooms << endl;
        cout << "Payment Amount: " << current->payment_amount << endl;
        cout << "State: " << current->state << endl;
        cout << "City: " << current->city << endl;
        cout << endl;
        current = current->next;
    }
}
//question 15.2
void displayHousesBackward() {
    house *current = back;
    if(start==NULL && back==NULL){
    	cout<<"No houses Entered"<<endl;
	} else{
	    while (current != NULL) {
	        cout << "House No: " << current->house_no << endl;
	        cout << "Owner Name: " << current->owner_name << endl;
	        cout << "Tenant Name: " << current->tenant_name << endl;
	        cout << "No. of Floors: " << current->no_of_floors << endl;
	        cout << "No. of Rooms: " << current->no_of_rooms << endl;
	        cout << "Payment Amount: " << current->payment_amount << endl;
	        cout << "State: " << current->state << endl;
	        cout << "City: " << current->city << endl << endl;
	        current = current->prev; // move to the previous node
	    }
    }
}
//question 16
void writeToFile() {
    char txtFile[30];
    cout << "Enter the text file you want to write to: ";
    cin >> txtFile;
    ofstream outFile(txtFile);

    house* i = start;
    while (i != NULL) {
        cout << i->house_no << ","
            << i->owner_name << ","
            << i->tenant_name << ","
            << i->no_of_floors << ","
            << i->no_of_rooms << ","
            << i->payment_amount << ","
            << i->state << ","
            << i->city << endl;

        outFile << i->house_no << ","
            << i->owner_name << ","
            << i->tenant_name << ","
            << i->no_of_floors << ","
            << i->no_of_rooms << ","
            << i->payment_amount << ","
            << i->state << ","
            << i->city << endl;

        i = i->next;
    }
    outFile.close();
}
//question 17
int countHouses() {
	house* head=new house;
    int count = 0;

    house* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    cout<<"there are "<<count<<" houses registered";
    return count;
}
//question 18.1
void countByOwnerName() {
    char ownerName[20];
    cout << "Enter the owner's name to count occurrences of: ";
    cin >> ownerName;

    int count = 0;
    house* i = start;
    while (i != NULL) {
        if (strcmp(i->owner_name, ownerName) == 0) {
            count++;
        }
        i = i->next;
    }
    cout << "Number of occurrences of " << ownerName << ": " << count << endl;
}
//question 18.2
void countByTenantName() {
    char tenantName[20];
    cout << "Enter the tenant name to count occurrences of: ";
    cin >> tenantName;

    int count = 0;
    house* i = start;
    while (i != NULL) {
        if (strcmp(i->tenant_name, tenantName) == 0) {
            count++;
        }
        i = i->next;
    }
    cout << "Number of occurrences of " << tenantName << ": " << count << endl;
}
//question 18.3
void countByNoOfFloors() {
    int noOfFloors;
    cout << "Enter the number of floors to count occurrences of: ";
    cin >> noOfFloors;

    int count = 0;
    house* i = start;
    while (i != NULL) {
        if (i->no_of_floors == noOfFloors) {
            count++;
        }
        i = i->next;
    }
    cout << "Number of occurrences of " << noOfFloors << " floors: " << count << endl;
}
//question 18.4
void countByNoOfRooms() {
    int noOfRooms;
    cout << "Enter the number of rooms to count occurrences of: ";
    cin >> noOfRooms;

    int count = 0;
    house* i = start;
    while (i != NULL) {
        if (i->no_of_rooms == noOfRooms) {
            count++;
        }
        i = i->next;
    }
    cout << "Number of occurrences of " << noOfRooms << " rooms: " << count << endl;
}
//question 18.5
void countByAmountOfPayment() {
    float amountOfPayment;
    cout << "Enter the amount of payment to count occurrences of: ";
    cin >> amountOfPayment;

    int count = 0;
    house* i = start;
    while (i != NULL) {
        if (i->payment_amount == amountOfPayment) {
            count++;
        }
        i = i->next;
    }
    cout << "Number of occurrences of " << amountOfPayment << " payment: " << count << endl;
}
//question 18.6
void countByState() {
    char states[20];
    cout << "Enter the state to count occurrences of : ";
    cin >> states;

    int count = 0;
    house* i = start;
    while (i != NULL) {
        if (strcmp(i->state, states) == 0) {
            count++;
        }
        i = i->next;
    }
    cout << "Number of occurrences in " << states << ": " << count << endl;
}
//question 18.7
void countByCity() {
    char cities[20];
    cout << "Enter the city to count occurrences of : ";
    cin >> cities;
    int count = 0;
    house* i = start;
    while (i != NULL) {
        if (strcmp(i->city, cities) == 0) {
            count++;
        }
        i = i->next;
    }
    cout << "Number of occurrences in " << cities << ": " << count << endl;
}
// question 19.1
void updateHouseNo() {
    int houseNo, newHouseNo;
    cout << "Enter house number: ";
    cin >> houseNo;
    cout << "Enter new house number: ";
    cin >> newHouseNo;
    house* current = start;
    bool houseExists = false;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            current->house_no = newHouseNo;
            houseExists = true;
            break;
        }
        current = current->next;
    }
    if (!houseExists) {
        cout << "House with house number " << houseNo << " does not exist. Please enter a valid house number." << endl;
        // Call the function again with the correct house number
        updateHouseNo();
    }
}

// question 19.2
void updateOwnerName() {
    int houseNo;
    char newOwnerName[50];
    cout << "Enter house number: ";
    cin >> houseNo;
    cout << "Enter new owner name: ";
    cin >> newOwnerName;
    house* current = start;
    bool houseExists = false;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            strncpy(current->owner_name, newOwnerName, sizeof(current->owner_name));
            houseExists = true;
            break;
        }
        current = current->next;
    }
    if (!houseExists) {
        cout << "House with house number " << houseNo << " does not exist. Please enter a valid house number." << endl;
        // Call the function again with the correct house number
        updateOwnerName();
    }
}

// question 19.3
void updateTenantName() {
    int houseNo;
    char newTenantName[50];
    cout << "Enter house number: ";
    cin >> houseNo;
    cout << "Enter new tenant name: ";
    cin >> newTenantName;
    house* current = start;
    bool houseExists = false;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            strncpy(current->tenant_name, newTenantName, sizeof(current->tenant_name));
            houseExists = true;
            break;
        }
        current = current->next;
    }
    if (!houseExists) {
        cout << "House with house number " << houseNo << " does not exist. Please enter a valid house number." << endl;
        // Call the function again with the correct house number
        updateTenantName();
    }
}

// question 19.4
void updateNoOfFloors() {
    int houseNo, newNoOfFloors;
    cout << "Enter house number: ";
    cin >> houseNo;
    cout << "Enter new number of floors: ";
    cin >> newNoOfFloors;
    house* current = start;
    bool houseExists = false;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            current->no_of_floors = newNoOfFloors;
            houseExists = true;
            break;
        }
        current = current->next;
    }
    if (!houseExists) {
        cout << "House with house number " << houseNo << " does not exist. Please enter a valid house number." << endl;
        // Call the function again with the correct house number
        updateNoOfFloors();
    }
}

// question 19.5
void updateNoOfRooms() {
    int houseNo, newNoOfRooms;
    cout << "Enter house number: ";
    cin >> houseNo;
    cout << "Enter new number of rooms: ";
    cin >> newNoOfRooms;
    house* current = start;
    bool houseExists = false;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            current->no_of_rooms = newNoOfRooms;
            houseExists = true;
            break;
        }
        current = current->next;
    }
    if (!houseExists) {
        cout << "House with house number " << houseNo << " does not exist. Please enter a valid house number." << endl;
        // Call the function again with the correct house number
        updateNoOfRooms();
    }
}

// question 19.6
void updatePaymentAmount() {
    int houseNo;
    float newPaymentAmount;
    cout << "Enter house number: ";
    cin >> houseNo;
    cout << "Enter new payment amount: ";
    cin >> newPaymentAmount;
    house* current= start;
    bool houseExists = false;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            current->payment_amount = newPaymentAmount;
            houseExists = true;
            break;
        }
        current = current->next;
    }
    if (!houseExists) {
        cout << "House with house number " << houseNo << " does not exist. Please enter a valid house number." << endl;
        // Call the function again with the correct house number
        updatePaymentAmount();
    }
}
// question 19.7
void updateState() {
    int houseNo;
    char newState[50];
    cout << "Enter house number: ";
    cin >> houseNo;
    cout << "Enter new state: ";
    cin >> newState;
    house* current = start;
    bool houseExists = false;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            strncpy(current->state, newState, sizeof(current->state));
            houseExists = true;
            break;
        }
        current = current->next;
    }
    if (!houseExists) {
        cout << "House with house number " << houseNo << " does not exist. Please enter a valid house number." << endl;
        // Call the function again with the correct house number
        updateState();
    }
}

// question 19.8
void updateCity() {
    int houseNo;
    char newCity[50];
    cout << "Enter house number: ";
    cin >> houseNo;
    cout << "Enter new city: ";
    cin >> newCity;
    house* current = start;
    bool houseExists = false;
    while (current != NULL) {
        if (current->house_no == houseNo) {
            strncpy(current->city, newCity, sizeof(current->city));
            houseExists = true;
            break;
        }
        current = current->next;
    }
    if (!houseExists) {
        cout << "House with house number " << houseNo << " does not exist. Please enter a valid house number." << endl;
        // Call the function again with the correct house number
        updateCity();
    }
}
//question 20.1
void sortByHouseNo() {
    if (start == NULL && back==NULL) {
        // list is empty, nothing to sort
        return;
    }

    bool swapped;
    house* curr;

    do {
        swapped = false;
        curr = start;

        while (curr->next != NULL) {
            // compare house_no of current node with next node
            if (curr->house_no > curr->next->house_no) {
                // swap nodes
                house* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;

                if (curr->prev != NULL) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }

                temp->prev = curr->prev;
                curr->prev = temp;
                if (curr->next != NULL) {
                    curr->next->prev = curr;
                }

                // set swapped flag to true
                swapped = true;
            } else {
                curr = curr->next;
            }
        }

        // move back pointer to the previous node
        back = curr->prev;
    } while (swapped);
}
//question 20.2
void sortByOwnerName() {
    if (start == NULL && back==NULL) {
        // list is empty, nothing to sort
        return;
    }

    bool swapped;
    house* curr;

    do {
        swapped = false;
        curr = start;

        while (curr->next != NULL) {
            // compare owner_name of current node with next node
            if (strcmp(curr->owner_name, curr->next->owner_name) > 0) {
                // swap nodes
                house* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;

                if (curr->prev != NULL) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }

                temp->prev = curr->prev;
                curr->prev = temp;
                if (curr->next != NULL) {
                    curr->next->prev = curr;
                }

                // set swapped flag to true
                swapped = true;
            } else {
                curr = curr->next;
            }
        }

        // move back pointer to the previous node
        back = curr->prev;
    } while (swapped);
}
//question 20.3
void sortByTenantName() {
    if (start == NULL && back==NULL) {
        // list is empty, nothing to sort
        return;
    }

    bool swapped;
    house* curr;

    do {
        swapped = false;
        curr = start;

        while (curr->next != NULL) {
            // compare tenant_name of current node with next node
            if (strcmp(curr->tenant_name, curr->next->tenant_name) > 0) {
                // swap nodes
                house* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;

                if (curr->prev != NULL) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }

                temp->prev = curr->prev;
                curr->prev = temp;
                if (curr->next != NULL) {
                    curr->next->prev = curr;
                }

                // set swapped flag to true
                swapped = true;
            } else {
                curr = curr->next;
            }
        }

        // move back pointer to the previous node
        back = curr->prev;
    } while (swapped);
}
//question 20.4
void sortByNoOfFloors() {
    if (start == NULL && back==NULL) {
        // list is empty, nothing to sort
        return;
    }

    bool swapped;
    house* curr;

    do {
        swapped = false;
        curr = start;

        while (curr->next != NULL) {
            // compare no_of_floors of current node with next node
            if (curr->no_of_floors > curr->next->no_of_floors) {
                // swap nodes
                house* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;

                if (curr->prev != NULL) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }

                temp->prev = curr->prev;
                curr->prev = temp;
                if (curr->next != NULL) {
                    curr->next->prev = curr;
                }

                // set swapped flag to true
                swapped = true;
            } else {
                curr = curr->next;
            }
        }

        // move back pointer to the previous node
        back = curr->prev;
    } while (swapped);
}
//question 20.5
void sortByNoOfRooms() {
    if (start == NULL && back==NULL) {
        // list is empty, nothing to sort
        return;
    }

    bool swapped;
    house* curr;

    do {
        swapped = false;
        curr = start;

        while (curr->next != NULL) {
            // compare no_of_rooms of current node with next node
            if (curr->no_of_rooms > curr->next->no_of_rooms) {
                // swap nodes
                house* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;

                if (curr->prev != NULL) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }

                temp->prev = curr->prev;
                curr->prev = temp;
                if (curr->next != NULL) {
                    curr->next->prev = curr;
                }

                // set swapped flag to true
                swapped = true;
            } else {
                curr = curr->next;
            }
        }

        // move back pointer to the previous node
        back = curr->prev;
    } while (swapped);
}
//question 20.6
void sortByPaymentAmount() {
    if (start == NULL && back==NULL) {
        // list is empty, nothing to sort
        return;
    }

    bool swapped;
    house* curr;

    do {
        swapped = false;
        curr = start;

        while (curr->next != NULL) {
            // compare payment_amount of current node with next node
            if (curr->payment_amount > curr->next->payment_amount) {
                // swap nodes
                house* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;

                if (curr->prev != NULL) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }

                temp->prev = curr->prev;
                curr->prev = temp;
                if (curr->next != NULL) {
                    curr->next->prev = curr;
                }

                // set swapped flag to true
                swapped = true;
            } else {
                curr = curr->next;
            }
        }

        // move back pointer to the previous node
        back = curr->prev;
    } while (swapped);
}
//question 20.7
void sortByState() {
    if (start == NULL && back==NULL) {
        // list is empty, nothing to sort
        return;
    }

    bool swapped;
    house* curr;

    do {
        swapped = false;
        curr = start;

        while (curr->next != NULL) {
            // compare state of current node with next node
            if (strcmp(curr->state, curr->next->state) > 0) {
                // swap nodes
                house* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;

                if (curr->prev != NULL) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }

                temp->prev = curr->prev;
                curr->prev = temp;
                if (curr->next != NULL) {
                    curr->next->prev = curr;
                }

                // set swapped flag to true
                swapped = true;
            } else {
                curr = curr->next;
            }
        }

        // move back pointer to the previous node
        back = curr->prev;
    } while (swapped);
}
//question 20.8
void sortByCity() {
    if (start == NULL && back==NULL) {
        // list is empty, nothing to sort
        return;
    }

    bool swapped;
    house* curr;

    do {
        swapped = false;
        curr = start;

        while (curr->next != NULL) {
            // compare city of current node with next node
            if (strcmp(curr->city, curr->next->city) > 0) {
                // swap nodes
                house* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;

                if (curr->prev != NULL) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }

                temp->prev = curr->prev;
                curr->prev = temp;
                if (curr->next != NULL) {
                    curr->next->prev = curr;
                }

                // set swapped flag to true
                swapped = true;
            } else {
                curr = curr->next;
            }
        }

        // move back pointer to the previous node
        back = curr->prev;
    } while (swapped);
}
//question 21.1
void displayFirstHouseNumbers() {
	sortByHouseNo();cout<<endl;
    house *current = start;
    int count = 0;
    if(start==NULL && back==NULL){
    	cout<<"No houses Entered"<<endl;
	}
    while (current != NULL && count < 10) {
        cout << "House No: " << current->house_no << endl;
        cout << "Owner Name: " << current->owner_name << endl;
        cout << "Tenant Name: " << current->tenant_name << endl;
        cout << "No. of Floors: " << current->no_of_floors << endl;
        cout << "No. of Rooms: " << current->no_of_rooms << endl;
        cout << "Payment Amount: " << current->payment_amount << endl;
        cout << "State: " << current->state << endl;
        cout << "City: " << current->city << endl << endl;
        current = current->next;
        count++;
    }
	cout<<"first 10 house information sorted in ascending order of house numbers"; 
}
//question 21.2
void displayTopOwnerNames() {
	sortByOwnerName();cout<<endl;
    house *current = start;
    int count = 0;
	if(start==NULL && back==NULL){
    	cout<<"No houses Entered"<<endl;
	}
    while (current != NULL && count < 7) {
        cout << "House No: " << current->house_no << endl;
        cout << "Owner Name: " << current->owner_name << endl;
        cout << "Tenant Name: " << current->tenant_name << endl;
        cout << "No. of Floors: " << current->no_of_floors << endl;
        cout << "No. of Rooms: " << current->no_of_rooms << endl;
        cout << "Payment Amount: " << current->payment_amount << endl;
        cout << "State: " << current->state << endl;
        cout << "City: " << current->city << endl << endl;
        current = current->next;
        count++;
    }
	cout<<"first 7 house information sorted by alphabetical order of the owner names"; 
}
//question 21.3
void displayTopNoOfFloors() {
	sortByNoOfFloors();cout<<endl;
    house *current = start;
    int count = 0;
    if(start==NULL && back==NULL){
    	cout<<"No houses Entered"<<endl;
	}
    while (current != NULL && count < 10) {
        cout << "House No: " << current->house_no << endl;
        cout << "Owner Name: " << current->owner_name << endl;
        cout << "Tenant Name: " << current->tenant_name << endl;
        cout << "No. of Floors: " << current->no_of_floors << endl;
        cout << "No. of Rooms: " << current->no_of_rooms << endl;
        cout << "Payment Amount: " << current->payment_amount << endl;
        cout << "State: " << current->state << endl;
        cout << "City: " << current->city << endl << endl;
        current = current->next;
        count++;
    }
	cout<<"first 10 house information sorted in ascending order of number of floors"; 
}
//question 21.4
void displayTopNoOfRooms() {
	sortByNoOfRooms();cout<<endl;
    house *current = start;
    int count = 0;
    if(start==NULL && back==NULL){
    	cout<<"No houses Entered"<<endl;
	}
    while (current != NULL && count < 20) {
        cout << "House No: " << current->house_no << endl;
        cout << "Owner Name: " << current->owner_name << endl;
        cout << "Tenant Name: " << current->tenant_name << endl;
        cout << "No. of Floors: " << current->no_of_floors << endl;
        cout << "No. of Rooms: " << current->no_of_rooms << endl;
        cout << "Payment Amount: " << current->payment_amount << endl;
        cout << "State: " << current->state << endl;
        cout << "City: " << current->city << endl << endl;
        current = current->next;
        count++;
    }
	cout<<"first 10 house information sorted in ascending order of number of rooms"; 
}
//question 21.5
void displayTopPaymentAmount() {
	sortByPaymentAmount();cout<<endl;
    house *current = start;
    int count = 0;
    if(start==NULL && back==NULL){
    	cout<<"No houses Entered"<<endl;
	}
    while (current != NULL && count < 20) {
        cout << "House No: " << current->house_no << endl;
        cout << "Owner Name: " << current->owner_name << endl;
        cout << "Tenant Name: " << current->tenant_name << endl;
        cout << "No. of Floors: " << current->no_of_floors << endl;
        cout << "No. of Rooms: " << current->no_of_rooms << endl;
        cout << "Payment Amount: " << current->payment_amount << endl;
        cout << "State: " << current->state << endl;
        cout << "City: " << current->city << endl << endl;
        current = current->next;
        count++;
    }
	cout<<"first 10 house information sorted in ascending order of amount of payment"; 
}
//prototypes
void displayDeleteByMenu();
void displaySearchByMenu();
void displayForAndBack();
void displayCountByMenu();
void displayUpdateByMenu();
void displaySortByMenu();
void displayTopByMenu();

void displayOperations(){
	cout << "\n********** Main Menu **********" << endl;
	cout << "******** The following list of operations are available: ********" << endl;
	cout << "(1): Insert to the list from a notepad file" << endl;
	cout << "(2): Insert at the end of the list" << endl;
	cout << "(3): Insert at the middle of the list after a given house" << endl;
	cout << "(4): Delete the first house in the list" << endl;
	cout << "(5): Delete the last house in the list" << endl;
	cout << "(6): Delete a house number based on a given attribute" << endl;
	cout << "(7): Delete a house found at nth position" << endl;
	cout << "(8): Find a house with minimum amount of payment " << endl;
	cout << "(9): Find a house with maximum amount of paymnet" << endl;	
	cout << "(10): Calculate average number of rooms of houses registered in the list" << endl;
	cout << "(11): Calculate average amount of payment of houses registered in the list" << endl;
	cout << "(12): Delete a house with a minimum number of floors" << endl;
	cout << "(13): Delete a house with a maximum number of floors" << endl;
	cout << "(14): Search for an entry based of different attributes of the house" << endl;
	cout << "(15): Display house data" << endl;	
	cout << "(16): write the information in the list to a notepad file" << endl;
	cout << "(17): Count total number of entries" << endl;
	cout << "(18): Count number of houses based on given attributes" << endl;
	cout << "(19): update houses information based on given attribute" << endl;
	cout << "(20): sort the houses by different attributes" << endl;	
	cout << "(21): Display top results based on different attributes" << endl;	
	cout << "(0): Exit" << endl;
	cout << "Make your selection: ";
}
void displayMainMenu(){
	int choice;
	
	do{
		displayOperations();
		cin >> choice;
		
		switch(choice){
			case 0:
				cout << "Exiting the application ... " << endl;
				break;
			case 1:
				insertAtBeginningFromFile();
				break;
			case 2:
				insertAtEnd();
				break;
			case 3:
				addNodeAfterHouseNo();
				break;
			case 4:
				deleteFirstNode();
				break;
			case 5:
				deleteLastNode();
				break;
			case 6:
				displayDeleteByMenu();//needs another func
				break;
			case 7:
				deleteNthNode();
				break;
			case 8:
				minpayment();
				break;
			case 9:
				maxpayment();
				break;
			case 10:
				averageroom();
				break;
			case 11:
				avepayment();;
				break;
			case 12:
				deleteminfloor();
				break;
			case 13:
				deletemaxfloor();
				break;
			case 14:
				displaySearchByMenu();// another func
				break;
			case 15:
				displayForAndBack();
				break;
			case 16:
				writeToFile();
				break;
			case 17:
				countHouses();
				break;
			case 18:
				displayCountByMenu();
				break;
			case 19:
				displayUpdateByMenu();
				break;
			case 20:
				displaySortByMenu();
				break;
			case 21:
				displayTopByMenu();
				break;
			default:
				cout << "ERROR! You have selected an invalid choice." << endl;
				break;
		}
	}
	while(choice != 0);
}
void displayAttributes(){ //for 6th question
	cout << "\n********** Attributes of a House**********" << endl;
	cout << "(1): House Number" << endl;
	cout << "(2): Owner Name" << endl;
	cout << "(3): Tenant Name" << endl;
	cout << "(4): Number of floors" << endl;
	cout << "(5): Number of rooms" << endl;
	cout << "(6): Amount of payment" << endl;
	cout << "(7): State" << endl;
	cout << "(8): City" << endl;
	cout << "(0): <- Back to Main Menu" << endl;
}
void displayDeleteByMenu(){//for 6th question
	int choice;
	
	do{
		displayAttributes();
		cout<<"Enter an attribute to delete by: ";
		cin>>choice;
		cout<<"-------------------------------------"<<endl;
		
		switch(choice){
			case 1:
				deleteByHouseNo();
				break;
			case 2:
				deleteByOwnerName();
				break;
			case 3:
				deleteByTenantName();
				break;
			case 4:
				deleteByNumberOfFloors();
				break;
			case 5:
				deleteByNumberOfRooms();
				break;
			case 6:
				deleteByPaymentAmount();
				break;
			case 7:
				deleteByState();
				break;
			case 8:
				deleteByCity();
				break;	
			case 0:
				displayMainMenu();
				break;
			default:
				cout << "ERROR! You have selected an invalid choice." << endl;
				break;
		}
	}
	while(choice != 0);
}
void displaySearchByMenu(){
	int choice;
	do{
		displayAttributes();
		cout<<"Enter an attribute to insert by: ";
		cin>>choice;
		cout<<"-------------------------------------"<<endl;
		
		switch(choice){
			case 1:
				searchbyhouse_no();
				break;
			case 2:
				searchbyowner_name();
				break;
			case 3:
				searchbytenant_name();
				break;
			case 4:
				searchbyno_of_floors();
				break;
			case 5:
				searchbyno_of_rooms();
				break;
			case 6:
				searchbypayment_amount();
				break;
			case 7:
				searchbystate();
				break;
			case 8:
				searchbycity();
				break;	
			case 0:
				displayMainMenu();
				break;
			default:
				cout << "ERROR! You have selected an invalid choice." << endl;
				break;
		}
	}
		while(choice != 0);
}
void displayForAndBack(){ //question 15
	int choice;
	do{
		cout<<"Which way do you want to display? 1: for forward...............2: for backward 0: back to main menu";
		cin>>choice;
		cout<<"-------------------------------------"<<endl;

		switch(choice){
			case 0:
				displayMainMenu();
			case 1:
				displayHousesForward();
				break;
			case 2:
				
				displayHousesBackward();
				break;	
			default:
				cout << "ERROR! You have selected an invalid choice." << endl;
				break;
		}
	}
		while(choice != 0);
}
void displayCountByMenu(){
	int choice;
	do{
		displayAttributes();
		cout<<"Enter an attribute to count by: ";
		cin>>choice;
		cout<<"-------------------------------------"<<endl;
		
		switch(choice){
			case 1:
				cout<<"house number is unique.";
				break;
			case 2:
				countByOwnerName();
				break;
			case 3:
				countByTenantName();
				break;
			case 4:
				countByNoOfFloors();
				break;
			case 5:
				countByNoOfRooms();
				break;
			case 6:
				countByAmountOfPayment();
				break;
			case 7:
				countByState();
				break;
			case 8:
				countByCity();
				break;	
			case 0:
				displayMainMenu();
				break;
			default:
				cout << "ERROR! You have selected an invalid choice." << endl;
				break;
		}
	}
		while(choice != 0);
}
void displayUpdateByMenu(){//question 19
	int choice;
	do{
		displayAttributes();
		cout<<"Enter an attribute to update by: ";
		cin>>choice;
		cout<<"-------------------------------------"<<endl;
		
		switch(choice){
			case 1:
				updateHouseNo();
				break;
			case 2:
				updateOwnerName();
				break;
			case 3:
				updateTenantName();
				break;
			case 4:
				updateNoOfFloors();
				break;
			case 5:
				updateNoOfRooms();
				break;
			case 6:
				updatePaymentAmount();
				break;
			case 7:
				updateState();
				break;
			case 8:
				updateCity();
				break;	
			case 0:
				displayMainMenu();
				break;
			default:
				cout << "ERROR! You have selected an invalid choice." << endl;
				break;
		}
	}
		while(choice != 0);
}
void displaySortByMenu(){//question 20
	int choice;
	do{
		displayAttributes();
		cout<<"Enter an attribute to sort by: ";
		cin>>choice;
		cout<<"-------------------------------------"<<endl;
		
		switch(choice){
			case 1:
				sortByHouseNo();
				break;
			case 2:
				sortByOwnerName();
				break;
			case 3:
				sortByTenantName();
				break;
			case 4:
				sortByNoOfFloors();
				break;
			case 5:
				sortByNoOfRooms();
				break;
			case 6:
				sortByPaymentAmount();
				break;
			case 7:
				sortByState();
				break;
			case 8:
				sortByCity();
				break;	
			case 0:
				displayMainMenu();
				break;
			default:
				cout << "ERROR! You have selected an invalid choice." << endl;
				break;
		}
	}
		while(choice != 0);	
}
void displayTopByMenu(){
	int choice;
	do{
		cout<<"Enter an attribute to find top values by: \n 1: House NUNmber \n 2: Owner Name \n 3: Number of floors \n 4:Number of rooms \n 5: Amount of payment \n 0: main menu"<<endl;
		cin>>choice;
		cout<<"-------------------------------------"<<endl;
		
		switch(choice){
			case 0:
				displayMainMenu();
			case 1:
				displayFirstHouseNumbers();
				break;
			case 2:
				displayTopOwnerNames();
				break;
			case 3:
				displayTopNoOfFloors();
				break;
			case 4:
				displayTopNoOfRooms();
				break;
			case 5:
				displayTopPaymentAmount();
				break;
			}
		}
			while(choice != 0);	
}
int main(){
	displayMainMenu();
}





