#include <iostream>
using namespace std;

int main() {
    typedef int* IntArrayPtr;

    int rows, cols;

    cout << "Enter rows: " << endl;
    cin >> rows;

    cout << endl << "Enter cols: " << endl;
    cin >> cols;

    //Initialize 2D Dynamic Array
    IntArrayPtr* multiArr = new IntArrayPtr[rows];
    for (int i = 0; i < rows; i++) {
        multiArr[i] = new int[cols];
    }
    
    //Fill array with 0s
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            multiArr[i][j] = 0;
        }
    }
    
    //Print array
    cout << "Printing array: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << multiArr[i][j] << " ";
        }
        cout << endl;
    }

    //Delete sub-dynamic arrays
    for (int i = 0; i < rows; i++) {
        delete[] multiArr[i];
    }
    delete []multiArr;

    return 0;
}

//#include <iostream>
//using namespace std;
//
//typedef int* IntArrayPtr;
//
//int main()
//{
//	int d1, d2;
//	std::cout << "Enter the row and column dimensions of the array:\n";
//	cin >> d1 >> d2;
//
//	IntArrayPtr* m = new IntArrayPtr[d1];
//	int i, j;
//	for (i = 0; i < d1; i++)
//		m[i] = new int[d2];
//	//m is now a d1 by d2 array.
//
//	for (i = 0; i < d1; i++)
//		for (j = 0; j < d2; j++) {
//
//			m[i][j] = 0;
//		}
//
//	std::cout << "Echoing the two-dimensional array:\n";
//
//	for (i = 0; i < d1; i++)
//	{
//		for (j = 0; j < d2; j++)
//			std::cout << m[i][j] << " ";
//		std::cout << endl;
//	}
//	for (i = 0; i < d1; i++)
//		delete[] m[i];
//	delete[] m;
//
//	return 0;
//}