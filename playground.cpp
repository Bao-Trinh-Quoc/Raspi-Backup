#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

void printArray(int n) {
    if (n == 0) {
        cout << n;
        return;
    }
    printArray(n - 1);
    cout << ", " << n;
}

void printBackward(int n) {
    if (n <= 0) {
        cout << n;
        return;
    }
    cout << n << " ";
    printBackward(n - 5);
}

void printForward(int n ) {
    if (n <= 0)
        return;
    
    printForward(n - 5);
    cout << " " << n;
}

void printPattern(int n) {
    printBackward(n);
    printForward(n);
}

int findMax(int* arr, int length) {
    if (length == 1)
        return *arr;

    return max(*(arr + length - 1), findMax(arr, length - 1));
}

bool isPalindrome(string str) 
{   
    size_t found = str.find_first_of(' ');
    if (found != string::npos) {
        // Removing the white-spaces 
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
    }
 
    if (str.length() == 0 || str.length() == 1)
        return true;
    return str[0] == str[str.length() - 1] && isPalindrome(str.substr(1, str.length() - 2));
}

int calcSum(vector<int> arr, int start, int end) {
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += arr[i];
    }
    return sum;
}

int equalSumIndex(vector<int>& nums) {
    int size = nums.size();
    int index = size / 2;
    int leftSum = calcSum(nums, 0, index);
    int rightSum = calcSum(nums, index + 1, size); 

    if (leftSum == rightSum)
        return index;

    while (leftSum > rightSum) {
        leftSum -= nums[index - 1];
        rightSum += nums[index];
        index--;

        if (leftSum == rightSum)
            return index;
        else if (leftSum < rightSum)
            return -1;
    }
    while (leftSum < rightSum) {
        leftSum += nums[index + 1];
        rightSum -= nums[index];
        index++;

        if (leftSum == rightSum)
            return index;
        else if (leftSum > rightSum)
            return -1;
    }

    return -1;
}



int main() {
    // test equalSumIndex
    vector<int> nums = {1, 2, 3, 4, 5, 5, 2, 1};
    cout << equalSumIndex(nums) << endl; 

    return 0;
}