#include <iostream>
#include <cstring>
#include <iomanip>

void print_seat(int** seat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << std::setw(2) << std::setfill('0') << seat[i][j];
            if (j < col - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows = 10;
    int cols = 10;
    
    // 1. Dynamically allocate a 10x10 integer array
    int** seat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        seat[i] = new int[cols];
    }
    
    // Initialize the whole array to 0 using memset
    for (int i = 0; i < rows; i++) {
        memset(seat[i], 0, cols * sizeof(int));
    }
    
    // Assign the specified values
    seat[0][0] = 11;
    seat[0][3] = 24;
    seat[1][1] = 35;
    seat[2][5] = 47;
    seat[3][3] = 58;
    seat[4][9] = 69;
    seat[5][0] = 70;
    seat[5][5] = 81;
    seat[5][9] = 92;
    seat[6][4] = 13;
    seat[7][7] = 26;
    seat[8][2] = 39;
    seat[9][9] = 44;
    
    // 2. Print using print_seat()
    std::cout << "Original seat map:" << std::endl;
    print_seat(seat, rows, cols);
    std::cout << std::endl;
    
    // 3. Create backup and copy using memcpy
    int** backup = new int*[rows];
    for (int i = 0; i < rows; i++) {
        backup[i] = new int[cols];
        memcpy(backup[i], seat[i], cols * sizeof(int));
    }
    
    std::cout << "Backup seat map:" << std::endl;
    print_seat(backup, rows, cols);
    std::cout << std::endl;
    
    // 4. Clear row 5 in original seat map
    memset(seat[5], 0, cols * sizeof(int));
    
    std::cout << "Original after clearing row 5:" << std::endl;
    print_seat(seat, rows, cols);
    std::cout << std::endl;
    
    std::cout << "Backup (should be unchanged):" << std::endl;
    print_seat(backup, rows, cols);
    std::cout << std::endl;
    
    // 5. Find row with largest number of assigned seats
    int maxAssigned = -1;
    int bestRow = -1;
    
    for (int i = 0; i < rows; i++) {
        int assignedCount = 0;
        for (int j = 0; j < cols; j++) {
            if (backup[i][j] != 0) {
                assignedCount++;
            }
        }
        if (assignedCount > maxAssigned) {
            maxAssigned = assignedCount;
            bestRow = i;
        }
    }
    
    std::cout << "Row with largest number of assigned seats: " << bestRow << std::endl;
    std::cout << "Number of assigned seats in that row: " << maxAssigned << std::endl;
    
    // Release all dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] seat[i];
        delete[] backup[i];
    }
    delete[] seat;
    delete[] backup;
    
    return 0;
}