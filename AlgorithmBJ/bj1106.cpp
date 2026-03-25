#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    vector<int> people(100001, 0);

    int cost, add_p;
    for (int i = 0; i < N; i++) {
        cin >> cost >> add_p;

        for (int j = cost; j < 100001; j++) {
            people[j] = max(people[j], people[j - cost] + add_p);
        }
    }

    for (int i = 0; i < 100001; i++) {
        if (people[i] >= C) {
            cout << i;
            break;
        }
    }
}