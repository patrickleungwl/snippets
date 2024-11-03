#include <iostream>
#include <cassert>
#include <cstring>
#include <chrono>
#include <array>

static void MemCopy(int size) {
    char source[size];
    char target[size];
    memset(source, 0x00, size);
    source[size-1] = 'A';
    target[size-1] = 'B';

    for (int i=0; i<1000000; i++) {
        memcpy(target, source, size);
    }
    // place an assert here or compiler may optimize away copy
    assert(target[size-1] == 'A');
}

static void LoopCopy(int size) {
    char source[size];
    char target[size];
    memset(source, 0x00, size);
    source[size-1] = 'A';
    target[size-1] = 'B';

    for (int i=0; i<1000000; i++) {
        // make the copy manually
        for (int j=0; j<size; j++) {
            target[j] = source[j];
        }
    }
    // place an assert here or compiler may optimize away copy
    assert(target[size-1] == 'A');
}

// get average time of copying arrays of sizes 1,10,100,1000,10000
static void RunTests(void (*test_func)(int), const char *msg) {
    std::array<int, 6> sizes{1,10,100,1000,10000,100000};
    std::cout << msg << '\n';
    for (const auto size : sizes) {
        const auto start = std::chrono::high_resolution_clock::now(); 
        test_func(size);
        const auto stop = std::chrono::high_resolution_clock::now();
        const auto time_us = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        std::cout << "copy " << size << " elements took " << time_us.count() << " microsecs\n";
    }
}


int main() {
    RunTests(LoopCopy, "timing manual copy of varying array sizes 1,000,000 times");
    RunTests(MemCopy,  "timing mem copy of varying array sizes 1,000,000 times");
}
