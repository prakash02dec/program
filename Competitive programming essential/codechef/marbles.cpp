#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int a, b;
        cin >> a >> b;

        if (a % b == 0) {
            cout << 0 << endl;
        } else {
            int count = 0;
            int count2 = 0;
            int c = a;
            int d = b;
            int got1 = 0;

            while (a >= b) {
                a--;
                b++;

                count++;
                if (a % b == 0) {
                    got1 = 1;
                    break;
                }
            }

            a = c;
            b = d;
            int got2 = 0;

            while (b > 0) {
                a++;
                b--;

                count2++;
                if (a % b == 0) {
                    got2 = 1;
                    break;
                }
            }

            if (got2 == 1 && got1 == 1) {
                if (count2 < count) {
                    cout << count2 << endl;
                } else {
                    cout << count << endl;
                }
            } else {
                if (got1 == 1) {
                    cout << count << endl;
                } else {
                    cout << count2 << endl;
                }
            }
        }

        t--;
    }

    return 0;
}