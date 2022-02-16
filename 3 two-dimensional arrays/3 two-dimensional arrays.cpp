// 3 two-dimensional arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Потрібно доопрацювати виділення динамічної пам*яті, з*являються помилки

#include <iostream> 
#include <Windows.h>
#include <ctime>

using namespace std;
void divisionArr(int** matrix, int n, int m);
void inputArr(int** matrix, int n, int m);
void printArr(int** matrix, int n, int m);
void deleteArr(int** matrix, int n, int m);
void commonABC(int** A, int** B, int** C, int a1, int a2, int b1, int b2, int c1, int c2);
void uniqueABC(int** A, int** B, int** C, int a1, int a2, int b1, int b2, int c1, int c2);
void negativeABC(int** A, int** B, int** C, int a1, int a2, int b1, int b2, int c1, int c2);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int** A = nullptr;
    int a1 = 1;
    int a2 = 1;
    cout << "Введіть кількість стовпців та рядків масиву А" << endl;
    cin >> a1 >> a2;
    A = new int* [a1];
    divisionArr(A, a1, a2);
    inputArr(A, a1, a2);
    printArr(A, a1, a2);
    cout << endl;
    int** B = nullptr;
    int b1 = 1;
    int b2 = 1;
    cout << "Введіть кількість стовпців та рядків масиву В" << endl;
    cin >> b1 >> b2;
    B = new int* [b1];
    divisionArr(B, b1, b2);
    inputArr(B, b1, b2);
    printArr(B, b1, b2);
    cout << endl;
    int** C = nullptr;
    int c1 = 1;
    int c2 = 1;
    cout << "Введіть кількість стовпців та рядків масиву С" << endl;
    cin >> c1 >> c2;
    C = new int* [c1];
    divisionArr(C, c1, c2);
    inputArr(C, c1, c2);
    printArr(C, c1, c2);      
    commonABC(A, B, C, a1, a2, b1, b2, c1, c2); 
    cout << endl;
    uniqueABC(A, B, C, a1, a2, b1, b2, c1, c2); 
    cout << endl;
    negativeABC(A, B, C, a1, a2, b1, b2, c1, c2);
    deleteArr(A, a1, a2);
    deleteArr(B, b1, b2);
    deleteArr(C, c1, c2);
    delete[]A;
    delete[]B;
    delete[]C;        
}
void divisionArr(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }
}
void inputArr(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 80 - 10;
        }
    }
}
void printArr(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void deleteArr(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        delete[]matrix[i];
    }
}
void commonABC(int** A, int** B, int** C, int a1, int a2, int b1, int b2, int c1, int c2) {
    int ab = 0;
    int ac = 0;
    int bc = 0;
    int size1 = 1;
    int* arr1 = new int[size1];
    int sizeAB = 1;
    int* arrAB = new int[sizeAB];
    int sizeAC = 1;
    int* arrAC = new int[sizeAC];
    int sizeBC = 1;
    int* arrBC = new int[sizeBC];
    for (int i = 0; i < a1; i++)
    {
        for (int j = 0; j < a2; j++)
        {
            for (int n = 0; n < b1; n++)
            {
                for (int m = 0; m < b2; m++)
                {
                    if (B[n][m] == A[i][j])
                    {
                        arrAB[ab] = A[i][j];
                        ab++;
                    }
                }
            }
        }
    }
    sizeAB = ab;
    for (int i = 0; i < a1; i++)
    {
        for (int j = 0; j < a2; j++)
        {
            for (int n = 0; n < c1; n++)
            {
                for (int m = 0; m < c2; m++)
                {
                    if (C[n][m] == A[i][j])
                    {
                        arrAC[ac] = A[i][j];
                        ac++;
                    }
                }
            }
        }
    }
    sizeAC = ac;
    for (int i = 0; i < b1; i++)
    {
        for (int j = 0; j < b2; j++)
        {
            for (int n = 0; n < c1; n++)
            {
                for (int m = 0; m < c2; m++)
                {
                    if (C[n][m] == B[i][j])
                    {
                        arrBC[bc] = B[i][j];
                        bc++;
                    }
                }
            }
        }
    }
    sizeBC = bc;

    int sizeABAC = ab + ac;
    int* arrABAC = new int[sizeABAC];
    int i = 0;
    for (; i < sizeAB; i++)
    {
        arrABAC[i] = arrAB[i];
    }
    for (int j = 0; j < sizeAC; i++, j++)
    {
        arrABAC[i] = arrAC[j];
    }
    int k = 0;
    for (; k < sizeABAC; k++)
    {
        arr1[k] = arrABAC[k];
    }
    for (int l = 0; l < sizeBC; k++, l++)
    {
        arr1[k] = arrBC[l];
    }
    size1 = ab + ac + bc;
    cout << "Загальні елементи для усіх масивів:" << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Загальні елементи для масивів A та C:" << endl;
    for (int i = 0; i < sizeAC; i++)
    {
        cout << arrAC[i] << " ";
    }
    delete[]arrAB;
    delete[]arrAC;
    delete[]arrABAC;
    delete[]arrBC;
  //  delete[]arr1;
}
void uniqueABC(int** A, int** B, int** C, int a1, int a2, int b1, int b2, int c1, int c2) {
    int ab = 0;
    int ac = 0;
    int bc = 0;
    int size1 = 1;
    int* arr1 = new int[size1];
    int sizeAB = 1;
    int* arrAB = new int[sizeAB];
    int sizeAC = 1;
    int* arrAC = new int[sizeAC];
    int sizeBC = 1;
    int* arrBC = new int[sizeBC];
    for (int i = 0; i < a1; i++)
    {
        for (int j = 0; j < a2; j++)
        {
            for (int n = 0; n < b1; n++)
            {
                for (int m = 0; m < b2; m++)
                {
                    if (B[n][m] == A[i][j])
                    {
                        break;
                    }
                    else if(m==b2-1 && n==b1-1)
                    {
                        arrAB[ab] = A[i][j];
                        ab++; 
                    }
                }
            }
        }
    }
    sizeAB = ab;
    for (int i = 0; i < c1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int n = 0; n < a1; n++)
            {
                for (int m = 0; m < a2; m++)
                {
                    if (A[n][m]==C[i][j])
                    {
                        break;
                    }
                    else if (m == a2 - 1 && n == a1 - 1) {
                        arrAC[ac] = C[i][j];
                        ac++;
                    }
                }
            }
        }
    }
    sizeAC = ac;
    for (int i = 0; i < b1; i++)
    {
        for (int j = 0; j < b2; j++)
        {
            for (int n = 0; n < c1; n++)
            {
                for (int m = 0; m < c2; m++)
                {
                    if (C[n][m] == B[i][j]) {
                        break;
                    }
                    else if (m == c2 - 1 && n == c1 - 1) {
                        arrBC[bc] = B[i][j];
                        bc++;
                    }
                }
            }
        }
    }
    sizeBC = bc;

    int sizeABAC = ab + ac;
    int* arrABAC = new int[sizeABAC];
    int i = 0;
    for (; i < sizeAB; i++)
    {
        arrABAC[i] = arrAB[i];
    }
    for (int j = 0; j < sizeAC; i++, j++)
    {
        arrABAC[i] = arrAC[j];
    }
    int k = 0;
    for (; k < sizeABAC; k++)
    {
        arr1[k] = arrABAC[k];
    }
    for (int l = 0; l < sizeBC; k++, l++)
    {
        arr1[k] = arrBC[l];
    }
    size1 = ab + ac + bc;
    cout << "Відмінні елементи для усіх масивів:" << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << " ";
    }
    delete[]arrAB;
    delete[]arrAC;
    delete[]arrABAC;
    delete[]arrBC;
   // delete[]arr1;
}
void negativeABC(int** A, int** B, int** C, int a1, int a2, int b1, int b2, int c1, int c2) {
    int a = 0;
    int c = 0;
    int b = 0;
    int size1 = 1;
    int* arr1 = new int[size1];
    int sizeA = 1;
    int* arrA = new int[sizeA];
    int sizeC = 1;
    int* arrC = new int[sizeC];
    int sizeB = 1;
    int* arrB = new int[sizeB];
    for (int i = 0; i < a1; i++)
    {
        for (int j = 0; j < a2; j++)
        {          
               if (A[i][j]<0){
                arrA[a] = A[i][j];
                a++;
               }
                
        }
    }
    sizeA = a;
    for (int i = 0; i < c1; i++)
    {
          for (int j = 0; j < c2; j++)
          {
              if (C[i][j] <0){
                  arrC[c] = C[i][j];
                  c++;
              }
          }
    }        
    sizeC = c;
    for (int i = 0; i < b1; i++)
    {
        for (int j = 0; j < b2; j++)
        {
           if (B[i][j]<0){
                 arrB[b] = B[i][j];
                        b++;
           }                
        }
    }
    sizeB = b;
    int sizeAB = a + b;
    int* arrAB = new int[sizeAB];
    int i = 0;
    for (; i < sizeA; i++)
    {
        arrAB[i] = arrA[i];
    }
    for (int j = 0; j < sizeB; i++, j++)
    {
        arrAB[i] = arrB[j];
    }
    int k = 0;
    for (; k < sizeAB; k++)
    {
        arr1[k] = arrAB[k];
    }
    for (int l = 0; l < sizeC; k++, l++)
    {
        arr1[k] = arrC[l];
    }
    size1 = a + b + c;
    cout << "Від*ємні елементи усіх масивів:" << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << " ";
    }  
    delete[]arrA;
    delete[]arrB;
    delete[]arrAB;
    delete[]arrC;
    delete[]arr1;
}