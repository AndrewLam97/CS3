#include "Suitor.h"
int Suitor::solve(int size, int k) {
    if (size == 1)
        return 1;
    else
        return (solve(size - 1, k) + k - 1) % size + 1;
}