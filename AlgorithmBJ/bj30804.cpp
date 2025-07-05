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

    //left = ����(���� ����2�� ����)�� ������Ű�� ���� ������ ������ ����
    //right = ������ ���ư��鼭 �����͸� Ȯ��

    for (int right = 0; right < N; right++) {
        fruitCount[fruits[right]]++;

        // ���� ������ 2�� ���� �ƴϸ�
        while (fruitCount.size() > 2) {

            //���� ������ fruits�� ���ش�.
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
