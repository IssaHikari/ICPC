#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y, n;
    cin >> x >> y >> n;

    long long ansA = 0;
    long long ansB = 1;

    for (long long b = 1; b <= n; b++) {

    
        long long p = x * b / y;

  
        for (long long a = p; a <= p + 1; a++) {

            if (a < 0)
                continue;

            long long currentNumerator = abs(x * b - a * y);
            long long currentDenominator = y * b;

            long long bestNumerator = abs(x * ansB - ansA * y);
            long long bestDenominator = y * ansB;

        
            if (currentNumerator * bestDenominator <
                bestNumerator * currentDenominator) {

                ansA = a;
                ansB = b;
            }

    
            else if (currentNumerator * bestDenominator ==
                     bestNumerator * currentDenominator) {

            
                if (b < ansB) {
                    ansA = a;
                    ansB = b;
                }

        
                else if (b == ansB && a < ansA) {
                    ansA = a;
                }
            }
        }
    }

    cout << ansA << "/" << ansB << '\n';

    return 0;
}