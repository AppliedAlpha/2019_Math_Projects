#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unordered_map>
#include <random>
using namespace std;
unordered_map<int, int> seen;

void sample_mean(int max, int cnt, int size, double mean) {
    // ���� ������ (mt19937_64) ����
    random_device rn;
    mt19937_64 rnd(rn());
    uniform_int_distribution<int> range(1, max);
    double sum = 0, total_mean = 0;

    if (cnt <= 0 || max <= 0 || size <= 0) {
        cout << "�Է°��� �ùٸ��� �ʽ��ϴ�.\n";
        return;
    }

    if (cnt > 10000000 || max > 100000 || size > 10) {
        cout << "�Է°��� �ùٸ��� �ʽ��ϴ�.\n";
        return;
    }

    for (int i = 0; i < cnt; i++) {
        sum = 0;
        for (int j = 0; j < size; j++) {
            // ���� �� ȣ��
            int get_rand = range(rnd);
            sum += get_rand;
            seen[get_rand]++;

            // ȣ���� �� ���
            cout << setfill(' ') << setw(6);
            cout << get_rand << ' ';
        }

        // (ǥ�� ��� �� / ǥ�� ũ��) = ǥ�����
        sum /= (double)size;
        total_mean += sum;

        // ǥ����� ���
        cout << fixed << setprecision(3);
        cout << "  ǥ�����: " << sum << '\n';
    }

    // (ǥ����� ��� �� / ǥ�� ����) = ǥ������� ���
    // ���⼭�� ǥ������� ����� ����տ� �ٻ��Ѵ�.
    cout << '\n';
    total_mean /= cnt;

    for (int i = 1; i <= max; i++)
        cout << '[' << i << "]�� ���� Ƚ��: " << seen[i] << '\n';

    cout << '\n' << fixed << setprecision(8);
    cout << "ǥ������� ���: " << total_mean << '\n';
    cout << "����հ��� ����: " << abs(total_mean - mean) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int max, size, cnt;
    double mean;
    cout << "�ִ� ���ڴ�? (����: ~ 100,000):";
    cin >> max;

    cout << "ǥ���� ũ���? (����: ~ 10):";
    cin >> size;

    cout << "���� Ƚ����? (����: ~ 10,000,000):";
    cin >> cnt;

    // ��ü [1, max]������ ����� : (max+1)/2
    cout << '\n';
    cout << fixed << setprecision(1);
    mean = (double)(max + 1) / 2;
    cout << "�����: " << mean << '\n';

    sample_mean(max, cnt, size, mean);
    system("pause");
    return 0;
}
