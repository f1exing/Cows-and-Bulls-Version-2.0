#include <iostream>
#include <random>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Hello, 0 - exit" << endl << endl;
    int a, b, ran[4], i, j, c[4], bull, cow;
    bool f = 0;

    while (true)
    {
        i = 0;
        while (i < 4)
        {
            srand(time(NULL));
            ran[i] = rand() % 10;
            for (j = 0; j < i; j++)
            {
                if (ran[i] == ran[j])
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                i++;
            }
            f = 0;
        }


        int s = 0;
        while (true && s < 10)
        {

            bull = 0;
            cow = 0;
            cout << s + 1 << " - ";
            s++;
            cin >> a;
            if (a == 0)
                break;
            for (i = 3; i >= 0; i--)
            {
                b = a % 10;
                c[i] = b;
                a = (a - b) / 10;
            }
            for (i = 0; i < 4; i++)
            {
                if (c[i] == ran[i])
                {
                    bull++;
                }
            }
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (c[i] == ran[j])
                    {
                        cow++;
                    }
                }
            }
            cout << bull << " - number of bulls; " << cow - bull << " - number of cows " << endl << endl;
            if (bull == 4)
            {
                cout << "You win ";
                break;
            }
        }
        for (i = 0; i < 4; i++)
        {
            cout << ran[i];
        }
        cout << endl << "game over. continue? 1 - yes 0 - no" << endl;
        cin >> f;
        if (f == 0)
        {
            return 0;
        }
        f = 0;
    }
}