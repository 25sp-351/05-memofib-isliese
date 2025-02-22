#include <stdio.h>

#define MAX_N 100  // Maximum size for storing Fibonacci numbers

// Cache array, initialized to -1 to indicate uncomputed values
int fib_cache[MAX_N];

// Fibonacci function with memoization
int memoized_fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    // If the value is already cached, return it
    if (fib_cache[n] != -1) {
        return fib_cache[n];
    }

    else {
    // Otherwise, compute it, store it in the cache, and return the result
    fib_cache[n] = memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2);
    return fib_cache[n];
    }
}

// Function to initialize the cache array
void init_cache() {
    for (int i = 0; i < MAX_N; i++) {
        fib_cache[i] = -1;  // Mark all values as uncomputed
    }
}

// Test function to verify the correctness of memoized_fibonacci
void test_fibonacci() {
    int test_values[] = {0, 1, 2, 5, 10};
    int expected_results[] = {0, 1, 1, 5, 55};  // Expected Fibonacci values

    for (int i = 0; i < 5; i++) {
        int n = test_values[i];
        int result = memoized_fibonacci(n);
        printf("fib(%d) = %d (expected: %d) %s\n", n, result, expected_results[i],
               result == expected_results[i] ? "✅ Passed" : "❌ Failed");
    }
}

int main() {
    init_cache();  // Initialize cache
    test_fibonacci();  // Run test cases
    return 0;
}
