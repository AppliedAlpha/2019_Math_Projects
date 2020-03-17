#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unordered_map>
#include <random>
using namespace std;
unordered_map<int, int> seen;

void sample_mean(int max, int cnt, int size, double mean) {
    // 난수 생성기 (mt19937_64) 정의
    random_device rn;
    mt19937_64 rnd(rn());
    uniform_int_distribution<int> range(1, max);
    double sum = 0, total_mean = 0;

    if (cnt <= 0 || max <= 0 || size <= 0) {
        cout << "입력값이 올바르지 않습니다.\n";
        return;
    }

    if (cnt > 10000000 || max > 100000 || size > 10) {
        cout << "입력값이 올바르지 않습니다.\n";
        return;
    }

    for (int i = 0; i < cnt; i++) {
        sum = 0;
        for (int j = 0; j < size; j++) {
            // 랜덤 수 호출
            int get_rand = range(rnd);
            sum += get_rand;
            seen[get_rand]++;

            // 호출한 수 출력
            cout << setfill(' ') << setw(6);
            cout << get_rand << ' ';
        }

        // (표본 요소 합 / 표본 크기) = 표본평균
        sum /= (double)size;
        total_mean += sum;

        // 표본평균 출력
        cout << fixed << setprecision(3);
        cout << "  표본평균: " << sum << '\n';
    }

    // (표본평균 요소 합 / 표본 개수) = 표본평균의 평균
    // 여기서는 표본평균의 평균이 모평균에 근사한다.
    cout << '\n';
    total_mean /= cnt;

    for (int i = 1; i <= max; i++)
        cout << '[' << i << "]이 나온 횟수: " << seen[i] << '\n';

    cout << '\n' << fixed << setprecision(8);
    cout << "표본평균의 평균: " << total_mean << '\n';
    cout << "모평균과의 오차: " << abs(total_mean - mean) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int max, size, cnt;
    double mean;
    cout << "최대 숫자는? (범위: ~ 100,000):";
    cin >> max;

    cout << "표본의 크기는? (범위: ~ 10):";
    cin >> size;

    cout << "실행 횟수는? (범위: ~ 10,000,000):";
    cin >> cnt;

    // 전체 [1, max]에서의 모평균 : (max+1)/2
    cout << '\n';
    cout << fixed << setprecision(1);
    mean = (double)(max + 1) / 2;
    cout << "모평균: " << mean << '\n';

    sample_mean(max, cnt, size, mean);
    system("pause");
    return 0;
}
