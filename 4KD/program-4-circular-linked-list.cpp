//4. Sukurti ciklinį vienkryptį sąrašą, realizuojant duomenų įvedimą, įterpimą prieš ir po nurodyto
//elemento, norimo elemento pašalinimą bei didžiausio elemento radimą. Realizuoti funkcijas,
//kurios:

//a. Visus skaičius nuo mažiausio perkelia iš ciklinio sąrašo į steką, realizuotą kaip
//vienkryptis sąrašas.

//b. Įterpia skaičius iš ciklinio sąrašo nuo pirmojo nelyginio iki antrojo nelyginio į steką.

//c. Panaikina visus steko elementus, juos atspausdinant ekrane.

/*******REQUIREMENTS IN ENGLISH*******/
// 4. Create a circular singly linked list, implementing data insertion, insertion before and after a given 
// element, removal of a desired element, and finding the maximum element. Implement the following functions:

// a. Move all numbers from the smallest to the stack, which is implemented as a singly linked list.

// b. Insert numbers from the circular list from the first odd number to the second odd number into the stack.

// c. Remove all elements from the stack and print them on the screen.

#include <iostream>
using namespace std;

struct List {
    int data;
    struct List *next;
};
List *head = NULL;
List *tail = NULL;

struct Stack {
    int data;
    struct Stack *next;
};
Stack *start = NULL;

void addListData(int x) {
    List *newNode = new List;
    newNode->data = x;
    newNode->next = head;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    tail->next = head;
}

void insertBeforeElement(int x, int y) {
    List *newNode = new List;
    newNode->data = x;
    newNode->next = NULL;
    if (head->data == y) {
        newNode->next = head;
        head = newNode;
        return;
    }
    List *current = head;
    while (current->next != NULL) {
        if (current->next->data == y) {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void insertAfterElement(int x, int y) {
    List *newNode = new List;
    newNode->data = x;
    newNode->next = NULL;
    List *current = head;
    while (current != NULL) {
        if (current->data == y) {
            newNode->next = current->next;
            current->next = newNode;
            if (current == tail) {
                tail = newNode;
            }
            return;
        }
        current = current->next;
    }
}

void insertBeforeAndAfterElem(int x, int y) {
    if (head == NULL) {
        cout << "sarasas tuscias, negalima iterpti" << endl;
        return;
    }
    insertBeforeElement(x, y);
    insertAfterElement(x, y);
}

void listRemoveElem(int x) {
    if (head == NULL) {
        cout << "sarasas tuscias, negalima panaikinti" << endl;
    }
    List *current = head;
    List *prev = NULL;
    do {
        if (current->data == x) {
            if (current->next == head && prev == NULL) {
                head = NULL;
                tail = NULL;
                delete current;
                return;
            }
            if (current == head) {
                head = current->next;
                delete current;
                current = head;
                tail->next = current;
                return;
            } else {
                prev->next = current->next;
                List *temp = current;
                current = current->next;
                delete temp;
                return;
            }
        } else {
            prev = current;
            current = current->next;
        }
    } while (current != head);
}

int listFindBiggestOrSmallestElem(string value) {
    int biggestInt;
    int smallestInt;
    if (head == NULL) {
        cout << "sarasas yra tuscias" << endl;
        return -5768;
    } else {
        List *current = head;
        do {
            if (current->data > biggestInt && value == "biggest") {
                biggestInt = current->data;
            }
            if (current->data < smallestInt && value == "smallest") {
                smallestInt = current->data;
            }
            current = current->next;
        } while (current != head);
    }
    if (value == "biggest") {
        return biggestInt;
    } else {
        return smallestInt;
    }
}

void printLinkedList() {
    if (head == NULL && tail == NULL) {
        cout <<"---------------------------" << endl;
        cout << "sarasas yra tuscias" << endl;
        cout <<"---------------------------" << endl;
    } else {
        List *current = head;
        cout <<"---------------------------" << endl;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "head" << endl;
        cout <<"---------------------------" << endl;
    }
}

void addStackData(int x) {
    Stack *temp = new Stack;
    temp->data = x;
    temp->next = start;
    start = temp;
}

void addElemToStackFromList() {
    int smallest;
    do {
        smallest = listFindBiggestOrSmallestElem("smallest");
        addStackData(smallest);
        listRemoveElem(smallest);
    } while (smallest != -5768);
    cout << "elementai perkelti is saraso i steka" << endl;
}

int findFirstOdd() {
    if (head == NULL && tail == NULL) {
        cout <<"---------------------------" << endl;
        cout << "sarasas yra tuscias" << endl;
        cout <<"---------------------------" << endl;
        return -987987;
    } else {
        List *current = head;
        do {
            if (current->data % 2 != 0) {
                return current->data;
            }
            current = current->next;
        } while (current != head);
    }
}

int findSecondOdd(int o) {
        List *current = head;
        do {
            if (current->data % 2 != 0 && current->data != o) {
                return current->data;
            }
            current = current->next;
        } while (current != head);
}

void addElemBetweenOdd() {
    int firstOdd = findFirstOdd();
    int secondOdd = findSecondOdd(firstOdd);
    bool firstOddReached = false;
    bool secondOddReached = false;
    List *current = head;
    while (secondOddReached == false) {
        if (firstOdd == -987987) {
            break;
        }
        if (current->data == firstOdd) {
            firstOddReached = true;
        }
        if (current->data == secondOdd) {
            secondOddReached = true;
        }
        if (firstOddReached == true) {
            addStackData(current->data);
        }
        current = current->next;
    }
}

void stackRemoveAllElem() {
    if (start == NULL) {
        cout << "stekas yra tuscias" << endl;
        return;
    } else {
        cout <<"---------------------------" << endl;
        cout << "panaikinti elementai: ";
        while (start != NULL) {
            Stack *temp = start;
            cout << temp->data << " - ";
            start = start->next;
            delete temp;
        } 
        cout << "" << endl;
        cout <<"---------------------------" << endl;
    }
}

void printStack() {
    Stack *current = start;
    if (start == NULL) {
        cout << "stekas yra tuscias" << endl;
    }
    while (current != NULL) {
        cout << current->data << " - ";
        current = current->next;
    }
    cout << "" << endl;
}

int main() {
    int choice, x, y;
    do {
        cout << "pasirinkite, koki veiksma norite vykdyti" << endl;
        cout << "1 - iterpti elementa i vienkrypti ciklini sarasa" << endl;
        cout << "2 - iterpti elementa pries ir po nurodyto elemento sarase" << endl;
        cout << "3 - pasalinti norima elementa is vienkrypcio ciklinio saraso" << endl;
        cout << "4 - rasti didziausia elementa sarase" << endl;
        cout << "5 - spausdinti sarasa" << endl;
        cout << "6 - perkelti visus skaicius nuo maziausio i steka" << endl;
        cout << "7 - perkelti skaicius i steka nuo pirmojo nelyginio iki antrojo nelyginio sarase" << endl;
        cout << "8 - panaikinti ir atspausdinti visus steko elementus" << endl;
        cout << "9 - spausdinti steka" << endl;
        cout << "0 - baigti programa" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1: 
                cout << "iveskite, koki elementa norite prideti, pvz.: 3" << endl;
                cin >> x;
                addListData(x);
                cout << "elementas pridetas: " << x << endl;
                break;
            case 2:
                cout << "iveskite norima iterpti elementa" << endl;
                cin >> x;
                cout << "iveskite elementa, pries ir po kurio norite iterpti" << endl;
                cin >> y;
                insertBeforeAndAfterElem(x, y);
                break;
            case 3:
                cout << "iveskite, kuri elementa norite salinti" << endl;
                cin >> x;
                listRemoveElem(x);
                break;
            case 4:
                cout <<"---------------------------" << endl;
                cout << "didziausias elementas sarase: " << listFindBiggestOrSmallestElem("biggest") << endl;
                cout <<"---------------------------" << endl;
                break;
            case 5:
                printLinkedList();
                break;
            case 6:
                addElemToStackFromList();
                break;    
            case 7:
                addElemBetweenOdd();
                break;
            case 8: 
                stackRemoveAllElem();
                break;
            case 9: 
                printStack();
                break;
            case 0: 
                break;
            default:
                cout <<"---------------------------" << endl;
                cout << "negalimas pasirinkimas" << endl;
                cout <<"---------------------------" << endl;
        }
    } while (choice != 0);

    return 0;
}