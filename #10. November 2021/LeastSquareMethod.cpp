// C++ program to find the
// regression line
#include<bits/stdc++.h>
using namespace std;
 
// Function to calculate b
double calculateB(int x[], int y[], int n)
{
     
    // sum of array x
    int sx = accumulate(x, x + n, 0);
 
    // sum of array y
    int sy = accumulate(y, y + n, 0);
 
    // for sum of product of x and y
    int sxsy = 0;
 
    // sum of square of x
    int sx2 = 0;
    for(int i = 0; i < n; i++)
    {
        sxsy += x[i] * y[i];
         sx2 += x[i] * x[i];
    }
    double b = (double)(n * sxsy - sx * sy) /
                       (n * sx2 - sx * sx);
 
    return b;
}
 
// Function to find the
// least regression line
void leastRegLine( int X[], int Y[], int n)
{
 
    // Finding b
    double b = calculateB(X, Y, n);
 
    int meanX = accumulate(X, X + n, 0) / n;
    int meanY = accumulate(Y, Y + n, 0) / n;
 
    // Calculating a
    double a = meanY - b * meanX;
 
    // Printing regression line
    cout << ("Regression line:") << endl;
    cout << ("Y = ");
    printf("%.3f + ", a);
    printf("%.3f *X", b);
}
 
// Driver code
int main()
{
     
    // Statistical data
    int X[] = { 95, 85, 80, 70, 60 };
    int Y[] = { 90, 80, 70, 65, 60 };
     
    int n = sizeof(X) / sizeof(X[0]);
     
    leastRegLine(X, Y, n);
}
 