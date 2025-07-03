#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    int min = 0;
    int max = *max_element(trees.begin(), trees.end());
    int mid;
    int answer = 0;  // ������ ���� �� �ִ밪 ����

    while (min <= max) {
        mid = (max + min) / 2;

        long long sum = 0;
        for (int tree : trees) {
            if (tree > mid) {
                sum += (tree - mid);
            }
        }

        if (sum >= M) {
            answer = mid;        // �ϴ� �����ϰ� �� ���� ���̵� �õ�
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }

    cout << answer;
    return 0;
}
