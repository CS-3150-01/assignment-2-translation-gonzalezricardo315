#include <stdio.h>
#include <stdlib.h>

int factorial(int num) {
    int fact = 1;
    if(num == 0) {
        return 1;
    } else {
        while (num > 1) {
            fact = fact * num;
            num--;
        }
        return fact;
    }
}

int numOfBST(int key) {
    int catalanNumber = factorial(2 * key) / (factorial(key + 1) * factorial(key));
    return catalanNumber;
}

int main() {
    int numberOfPossibleBST = numOfBST(5);
    printf("%s %d", "Total number of possible Binary Search Trees with given key: ", numberOfPossibleBST);
    return 0;
}