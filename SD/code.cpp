#include <iostream>
#include <random>
#include <chrono>
using namespace std;

void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int getRandomNum(int maxNum) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, maxNum); 
    int randomNumber = dis(gen);
    return randomNumber;
}

int bubbleData(string type, int arrSize, string arrChoice) {
    int array[arrSize];
    
    if (type == "nesur") {

        for (int i = 0; i < arrSize; i++) {
            int randomNumber = getRandomNum(arrSize);
            array[i] = randomNumber;
        }
    } else if (type == "sur") {
        for (int i = 1; i <= arrSize; i++) {
            array[i] = i;
        }
    } else if (type == "atv") {
        int index = 0;
        for (int i = arrSize; i >= 1; i--) {
            array[index] = i;
            index++;
        }
    } else {
        cout << "netinkamas pasirinkimas " << "'" << type << "'" << endl;
    }
    
    if (arrChoice == "bubble") {
        auto startTime = chrono::high_resolution_clock::now();
        bubbleSort(array, arrSize);
        auto endTime = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
        cout << "bubble sort, " << arrSize << ", duomenys " << type << " - " << duration.count() << "ms" << endl;
        // cout << duration.count() << ", ";
        int ret = duration.count();
        return ret;
    } else if (arrChoice == "merge") {
        auto startTime = chrono::high_resolution_clock::now();
        mergeSort(array, 0, arrSize - 1);
        auto endTime = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
        cout << "merge sort, " << arrSize << ", duomenys " << type << " - " << duration.count() << "ms" << endl;
        int ret = duration.count();
        return ret;
    } else {
        cout << "tokio algoritmo pasirinkimo nera" << endl;
        return 0;
    }

}

int main() {
    int size;
    string data;
    int count;
    string choice;
    cout << "iveskite, koki rusiavimo algoritma norite naudoti - 'bubble' ar 'merge'" << endl;
    cin >> choice;
    cout << "iveskite, kokius duomenis norite rikiuoti - nesur (nesurikiuotus), sur (surikiuotus), atv (atvirksciai surikiuotus)" << endl;
    cin >> data;
    cout << "iveskite, kiek duomenu norite rikiuoti - 5000, 10000, 50000 ar 100000" << endl;
    cin >> size;
    cout << "iveskite, kiek kartu norite vykdyti rusiavima" << endl;
    cin >> count;
    cout << "----------------------------------------------" << endl;
    int arr[count];
    for (int i = 1; i <= count; i++) {
        int j = bubbleData(data, size, choice);
        arr[i - 1] = j;
    }
    cout << endl;
    double avg = 0;
    for (int i = 0; i < count; i++) {
        avg += arr[i];
    }
    if (count > 1) {
        cout << "siu laiku vidurkis yra " << avg / count << " ms" << endl;
    }

    return 0;
}