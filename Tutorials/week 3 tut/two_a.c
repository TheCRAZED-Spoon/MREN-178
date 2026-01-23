//implementation of binary search algorithm
int search_integers(const int* arr, int length, int target) {
    int halfLen = length / 2;
    // if middle element is target, we have found the integer
    if (*(arr+halfLen) == target) {
        return halfLen;
    } 
    //if the length is 1, we have already checked if the only element is target
    // so we know that the target is not in the array
    else if (length == 1) {
        return -1;
    } 
    // if the middle element is greater than target, search in the left half
    else if (*(arr+halfLen) > target) {
        return search_integers(arr, halfLen, target);
    } 
    // if middle element is less than target, search in the right half
    else {
        int result = search_integers(arr + halfLen, length - halfLen, target);
        if (result == -1) {
            return -1;
        } else {
            return halfLen + result;
        }
    }
}

int main () {
    // testing functionality
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    printf("%d\n", search_integers(arr, 10, 1));  // should return index 0
    printf("%d\n", search_integers(arr, 10, 19)); // should return index 9
    printf("%d\n", search_integers(arr, 10, 11)); // should return index 5
}