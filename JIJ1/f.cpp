#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;

    cin >> N >> M;

    vector<ll> A(N + 1), B(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int j = 1; j <= N; j++)
        cin >> B[j];

    /*
        s = r + c
        d = r - c + N

        For every diagonal we store:
        cnt  = sum of number of people
        sum  = sum of (diagonal coordinate * number of people)
    */

    vector<ll> cntS(2 * N + 2, 0);
    vector<ll> sumS(2 * N + 2, 0);

    vector<ll> cntD(2 * N + 2, 0);
    vector<ll> sumD(2 * N + 2, 0);

    // Build diagonal information
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {

            ll people = (A[r] * B[c]) % M;

            int s = r + c;
            int d = r - c + N;

            cntS[s] += people;
            sumS[s] += people * s;

            cntD[d] += people;
            sumD[d] += people * d;
        }
    }

    /*
        Prefix sums over diagonals
    */

    vector<ll> prefCntS(2 * N + 2);
    vector<ll> prefSumS(2 * N + 2);

    vector<ll> prefCntD(2 * N + 2);
    vector<ll> prefSumD(2 * N + 2);

    for (int i = 1; i <= 2 * N; i++) {
        prefCntS[i] = prefCntS[i - 1] + cntS[i];
        prefSumS[i] = prefSumS[i - 1] + sumS[i];

        prefCntD[i] = prefCntD[i - 1] + cntD[i];
        prefSumD[i] = prefSumD[i - 1] + sumD[i];
    }

    // Sum weight * |x - target|
    auto calc = [](int target,
                   const vector<ll>& prefCnt,
                   const vector<ll>& prefSum,
                   int maxCoord) -> ll {

        // Coordinates <= target
        ll leftCnt = prefCnt[target];
        ll leftSum = prefSum[target];

        ll left =
            1LL * target * leftCnt - leftSum;

        // Coordinates > target
        ll totalCnt = prefCnt[maxCoord];
        ll totalSum = prefSum[maxCoord];

        ll rightCnt = totalCnt - leftCnt;
        ll rightSum = totalSum - leftSum;

        ll right =
            rightSum - 1LL * target * rightCnt;

        return left + right;
    };

    ll answer = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            int s = i + j;
            int d = i - j + N;

            /*
                sum people * |(r+c) - (i+j)|
            */
            ll part1 = calc(
                s,
                prefCntS,
                prefSumS,
                2 * N
            );

            /*
                sum people * |(r-c) - (i-j)|

                We shifted r-c by +N.
            */
            ll part2 = calc(
                d,
                prefCntD,
                prefSumD,
                2 * N
            );

            /*
                max(|r-i|, |c-j|)
                =
                (part1 + part2) / 2
            */
            ll f = (part1 + part2) / 2;

            /*
                Required value:
                f(i,j) + (i-1)N + (j-1)
            */
            ll value = f + 1LL * (i - 1) * N + (j - 1);

            answer ^= value;
        }
    }

    cout << answer << '\n';

    return 0;
}