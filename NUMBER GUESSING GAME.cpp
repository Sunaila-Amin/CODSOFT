#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int n, g, t = 0;
    srand(time(0));
    n = rand() % 100 + 1; 
    cout << "Guess My Number Game\n\n";
    do
    {
        cout << "Guess a number between 1 and 100 : ";
        cin >> g;
        t++;

        if (g > n)
            cout << " high!\n\n";
        else if (g < n)
            cout << " low!\n\n";
        else
            cout << "\nCorrect! You got it in " << t << " guesses!\n";
    } while (g != n);

    return 0;
}
