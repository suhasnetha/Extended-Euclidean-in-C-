// C++ program to find multiplicative modulo inverse using
// Extended Euclid algorithm.
#include<iostream>
#include<cstdlib>
using namespace std;

// C function for extended Euclidean Algorithm
int extendedEuclid(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
void modInverse(int a, int b)
{
    int x, y;
    int g = extendedEuclid(a, b, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // b is added to handle negative x
        int result = (x%b + b) % b;
        cout << "Modular multiplicative inverse of " << a << " mod " << b << " is " <<result;
    }
}

// C function for extended Euclidean Algorithm
int extendedEuclid(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = extendedEuclid(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
// Driver Program
int main()
{
     int a, b, x, y;
     char choice;

  do {
        cout << "\n\n-----What would you like to do?------ \n\t 1. GCD \n\t 2. Modular inverse\n\t 3. Exit" ;
        cout <<"\nEnter the choice: ";
        cin >> choice ;
  switch(choice)
  {
  case '1':
    {
    cout << "Please, enter integer A: ";
    cin >> a;
    cout << "Please, enter integer B: ";
    cin >> b;
    cout << "\t\tGCD is " << extendedEuclid(a,b,&x,&y) << endl;
    cout << "\t\tX:" << x << endl << "\t\tY:" << y << endl;
    break;
    }
  case '2':
    {
    cout << "Please, enter integer A: ";
    cin >> a;
    cout << "Please, enter integer B: ";
    cin >> b;
    modInverse(a, b);
    break;
    }
  case '3':
    exit(0);

  default : cout << "\nBad Input. Must be 1 or 2." ;
    }
  }while (a!=0);
  return 0;
}

