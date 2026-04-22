#include <iostream>
#include <cstring>
using namespace std;

// Function to print array
void printArray(const char* arr[], int size, const char* label) {
    cout << label << " ";
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] " << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << endl;
}

// Function to search for a word and return its index
int searchWord(const char* arr[], int size, const char* target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            return i;
        }
    }
    return -1;  // Not found
}

// Function to update a word at specific index
void updateWord(const char* arr[], const char* newArr[], int size, int index, const char* newWord) {
    for (int i = 0; i < size; i++) {
        if (i == index) {
            newArr[i] = newWord;
        } else {
            newArr[i] = arr[i];
        }
    }
}

// Function to delete a word at specific index
int deleteWord(const char* source[], const char* destination[], int size, int deleteIndex) {
    int newIndex = 0;
    for (int i = 0; i < size; i++) {
        if (i != deleteIndex) {
            destination[newIndex++] = source[i];
        }
    }
    return newIndex;  // Return new size
}

int main() {
    // Initial array
    const char* words[] = {"alpha", "bravo", "charlie", "delta", "echo"};
    int size = 5;
    
    // Step 1: Print initial array
    printArray(words, size, "[Initial]");
    
    // Step 2: Search for 'delta'
    cout << "\n[Search Results]" << endl;
    int deltaIndex = searchWord(words, size, "delta");
    if (deltaIndex != -1) {
        cout << "Word 'delta' found at index: " << deltaIndex << endl;
    } else {
        cout << "Word 'delta' not found" << endl;
    }
    
    // Step 3: Modify 'bravo' to 'blueberry' at index 1
    const char* afterUpdate[5];
    updateWord(words, afterUpdate, size, 1, "blueberry");
    printArray(afterUpdate, size, "\n[After Update]");
    
    // Step 4: Delete 'charlie' at index 2
    const char* afterDelete[4];
    int newSize = deleteWord(afterUpdate, afterDelete, size, 2);
    printArray(afterDelete, newSize, "[After Delete]");
    
    // Bonus: Search for 'delta' again after modifications
    cout << "\n[Search 'delta' after modifications]" << endl;
    int finalDeltaIndex = searchWord(afterDelete, newSize, "delta");
    if (finalDeltaIndex != -1) {
        cout << "Word 'delta' found at index: " << finalDeltaIndex << endl;
    }
    
    return 0;
}