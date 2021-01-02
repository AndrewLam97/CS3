/*
    CS3
    Ch9_1
*/
#include <iostream>
#include <string>
using namespace std;

int maxSize = 50;
int arr1Size = 0;
int arr2Size = 0;
int pos;

void getReverseCharArr(char*& charArr1, char*& charArr2);
int* sumArrs(char*& charArr1, char*& charArr2);

int main()
{
    char* charArr1 = nullptr;
    char* charArr2 = nullptr;

    bool repeat;

    do {
        getReverseCharArr(charArr1, charArr2);

        int* result = sumArrs(charArr1, charArr2);

        if (pos >= 20) {
            cout << "Encountered integer overflow..." << endl;
            return 0;
        }

        cout << "The result is : ";
        for (int i = 0; i < pos; ++i) {
            cout << result[i];
        }

        delete[] charArr1;
        delete[] charArr2;
        delete[] result;
        charArr1 = nullptr;
        charArr2 = nullptr;
        result = nullptr;
        pos = 0;

        cout << endl << "Enter 1 to repeat, 0 to end: " << endl;
        cin >> repeat;
    } while (repeat);

    return 0;
}

/*
PURPOSE: Takes user input and stores number as character array
PARAMETERS: character array pointer by reference 
RETURN VALUES: none
*/
void getReverseCharArr(char*& charArr1, char*& charArr2) {
    string numStr1, numStr2;

    cout << "Enter first num: " << endl;
    cin >> numStr1;
    cout << endl << "Enter second num: " << endl;
    cin >> numStr2;

    reverse(numStr1.begin(), numStr1.end());
    reverse(numStr2.begin(), numStr2.end());

    arr1Size = numStr1.length();
    arr2Size = numStr2.length();

    charArr1 = new char[arr1Size];
    charArr2 = new char[arr2Size];
    
    for (int i = 0; i < arr1Size; i++) {
        charArr1[i] = numStr1[i];
    }
    for (int i = 0; i < arr2Size; i++) {
        charArr2[i] = numStr2[i];
    }
}

/*
PURPOSE: sums character arrays and stores results in integer array
PARAMETERS: character array pointers
RETURN VALUES: integer array pointer
*/
int* sumArrs(char*& charArr1, char*& charArr2)
{
    if (arr1Size > arr2Size) {
        char* temp = charArr1;
        charArr1 = charArr2;
        charArr2 = temp;
        int tempSize = arr1Size;
        arr1Size = arr2Size;
        arr2Size = tempSize;
    }

    int* result = new int[maxSize];

    int diff = arr2Size - arr1Size, carry = 0;

    for (int i = 0; i < arr1Size; i++) {
        int sum = ((charArr1[i] - '0') + (charArr2[i] - '0') + carry);
        result[pos] = (sum % 10);
        carry = sum / 10;
        pos++;
    }

    for (int i = arr1Size; i < arr2Size; i++) {
        int sum = ((charArr2[i] - '0') + carry);
        result[pos] = (sum % 10);
        carry = sum / 10;
        pos++;
    }

    int start = 0, end = pos - 1;
    while (start < end)
    {
        int temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}