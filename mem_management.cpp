#include <iostream>

void allocateMemory() {
    int* data = new int(42); // Allocate memory
    delete data; // Explicitly deallocating memory
    data = nullptr; // clean up pointer
}

int main() {
    allocateMemory();
    return 0;
}
