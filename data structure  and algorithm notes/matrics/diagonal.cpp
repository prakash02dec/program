#include <iostream>
using namespace std;

class LTMatrix{
private:
    int n;
    int* A;
public:
    LTMatrix(int n){
        this->n = n;
        A = new int [n * (n + 1)/2];
    }
    ~LTMatrix(){ delete[] A; }
    void Display(bool row=true);
    void setRowMajor(int i, int j, int x);
    void setColMajor(int i, int j, int x);
    int getRowMajor(int i, int j);
    int getColMajor(int i, int j);
    int getN(){ return n; }
 
};
 
void LTMatrix::setRowMajor(int i, int j, int x) {
    if (i >= j){
        int index = ((i * (i - 1))/2) + j - 1;
        A[index] = x;
    }
}
 
void LTMatrix::setColMajor(int i, int j, int x) {
    if (i >= j){
        int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
        A[index] = x;
    }
}
 
int LTMatrix::getRowMajor(int i, int j) {
    if (i >= j){
        int index = ((i * (i - 1))/2) + j - 1;
        return A[index];
    } else {
        return 0;
    }
}
 
int LTMatrix::getColMajor(int i, int j) {
    if (i >= j){
        int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
        return A[index];
    } else {
        return 0;
    }
}
 
void LTMatrix::Display(bool row) {
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i >= j){
                if (row){
                    cout << getRowMajor(i, j) << " ";
                } else {
                    cout << getColMajor(i, j) << " ";
                }
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
 


class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal(){
        n = 2;
        A = new int[2];
    }
    Diagonal(int n){
        this->n = n;
        A = new int[n];
    }
    ~Diagonal(){
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n; }
};
void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}
int Diagonal::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    return 0;
}
void Diagonal::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                cout << A[i - 1] << "";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}



int main()
{
    int d;
    cout << "Enter Dimensions";
    cin >> d;

    Diagonal diagonal(d);

    int x;
    cout << "Enter All Elements";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            diagonal.Set(i, j, x);
        }
    }

    diagonal.Display();
    return 0;
}