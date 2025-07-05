#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    //INPUT
    int N;
    cin >> N;
    vector<int> fruits(N);
    for (int i = 0; i < N; i++) {
        cin >> fruits[i];
    }

    //CHECK
    map<int, int> fruitCount;
    int maxLen = 0;
    int left = 0;

    //left = 조건(과일 종류2개 이하)를 만족시키기 위해 윈도우 왼쪽을 줄임
    //right = 앞으로 나아가면서 데이터를 확인

    for (int right = 0; right < N; right++) {
        fruitCount[fruits[right]]++;

        // 과일 종류가 2개 이하 아니면
        while (fruitCount.size() > 2) {

            //제일 왼쪽의 fruits를 없앤다.
            fruitCount[fruits[left]]--;
            if (fruitCount[fruits[left]] == 0)
                fruitCount.erase(fruits[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << endl;
    return 0;
}
