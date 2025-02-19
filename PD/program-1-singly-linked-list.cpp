//Duotas sveikas skaičius n. Simboliai s1, s2, … , sn surašyti į sąrašą. Simbolių grupę
//atskirtą tarpu vadinsime žodžiu. Pakeisti sąrašą taip, kad būtų panaikintas pirmas ir
//paskutinis tarpas (jei tokie yra), o taip pat panaikinti daugiau nei vieną einantį iš
//eilės vidinį tarpą. Taip pat, jeigu paskutinis žodis prasideda raide „a“ ir žodžių
//skaičius yra nelyginis, tai perstatyti šį žodį sąrašo pradžioje, padarant jį pirmu.

#include <iostream>
using namespace std;

struct List {
    char data;
    struct List *next;
};
List *head = NULL;
List *tail = NULL;

void insertNodeToList(char data) {
    List* newNode = new List;
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = NULL;
        head->next = NULL;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void removeNodeFromList(List *curr, int index) {
    List *prev = NULL;
    for (int i = 0; i <= index; i++) {
        if (i == index) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            if (curr == tail) {
                tail = prev;
            }
            delete curr;
            return;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

bool checkSpaceCount(List *curr) {
    int spaceCount = 0;
    char space = ' ';
    while (curr != NULL) {
        char str = curr->data;
        if (str == space) {
            spaceCount++;
        }
        curr = curr->next;
    }
    return spaceCount > 1;
}

int findFirstSpaceIndex(List *curr) {
    int index = 0;
    char space = ' ';
    while (curr != NULL) {
        char str = curr->data;
        if (str == space) {
            return index;
        }
        curr = curr->next;
        index++;
    }
    return -1;
}

int findLastSpaceIndex(List *curr) {
    int index = 0;
    int lastIndex = -1;
    char space = ' ';
    while (curr != NULL) {
        char str = curr->data;
        if (str == space) {
            lastIndex = index;
        }
        curr = curr->next;
        index++;
    }
    return lastIndex;
}

void removeFirstAndLastSpace() {
    if (checkSpaceCount(head) == false) {
        cout << "--------------------------" << endl;
        cout << "sarase nera 2 tarpu" << endl;
        cout << "--------------------------" << endl;
    } else {
        int firstIndex = findFirstSpaceIndex(head);
        int secondIndex = findLastSpaceIndex(head);
        removeNodeFromList(head, firstIndex);
        removeNodeFromList(head, secondIndex - 1);
    }
}

void removeConsecutiveSpaces(List *curr) {
    if (curr == NULL || curr->next == NULL) {
        cout << "--------------------------------------------" << endl;
        cout << "sarasas per trumpas jog butu 2 tarpai is eiles" << endl;
        cout << "--------------------------------------------" << endl;
        return;
    }
    int index = 0;
    List *prev = curr;
    curr = curr->next;
    while (curr != NULL) {
        char p = prev->data;
        char c = curr->data;
        if (p == c) {
            List *nextNode = curr->next;
            removeNodeFromList(curr, index);
            curr = nextNode;
        }
        prev = curr;
        curr = curr->next;
        index++;
    }
}

string findLastWord(List *curr) {
    string word;
    while (curr != NULL) {
        char d = curr->data;
        cout << d << endl;
        if (d != ' ') {
            word += d;
        } else {
            word = "";
        }
        curr = curr->next;
    }
    cout << word << endl;
    return word;
}

bool checkFirstLetter(string word) {
    if (word[0] == 'a' || word[0] == 'A') {
        return true;
    } else {
        return false;
    }
}

int countWordsInList(List *curr) {
    int spaceCount = 0;
    while (curr != NULL) {
        char d = curr->data;
        if (d == ' ') {
            spaceCount++;
        }
        curr = curr->next;
    }
    return spaceCount + 1;
}

void moveLastWordToStart() {
    string lastWord = findLastWord(head);
    if (checkFirstLetter(lastWord) == true && countWordsInList(head) % 2 == 1) {
        //perkelti po viena simboli i pradzia nuo paskutinio
    }
}

void printLinkedList(List *curr) {
    cout << "--------------------------------------------" << endl;
    while (curr != NULL) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
    cout << "--------------------------------------------" << endl;
}

int main() {
    int choice;
    char data;
    do {
        cout << "ka norite daryti toliau? (iveskite pvz.: 2)" << endl;
        cout << "1 - iterpti simboli i sarasa" << endl;
        cout << "2 - spausdinti sarasa" << endl;
        cout << "3 - panaikinti pirma ir paskutini tarpa" << endl;
        cout << "4 - panaikinti daugiau nei 1 is eiles einanti tarpa" << endl;
        cout << "5 - panaikinti paskutini zodi jei jis prasideda raide 'a' ir jo simboliu skaicius nelyginis" << endl;
        cout << "6 - baigti programa" << endl;
        
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "iveskite koki simboli norite iterpti" << endl;
                cin >> data;
                insertNodeToList(data);
                break;
            case 2:
                printLinkedList(head);
                break;
            case 3:
                removeFirstAndLastSpace();
                break;
            case 4:
                removeConsecutiveSpaces(head);
                break;
            case 5:
                moveLastWordToStart();
                break;
            case 6:
                cout << "programa baigta" << endl;
                break;
            default:
                cout << "netinkamas pasirinkimas" << endl;
        }
    } while (choice != 6);

    return 0;
}
