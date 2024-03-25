#include <stdio.h>
#include <time.h>

unsigned long long fact_iter(int n) { //반복문을 사용
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) { //1부터 n까지의 숫자를 곱하여 계산
        result *= i;
    }
    return result;
}

unsigned long long factorial_rec(int n) { //재귀를 사용
    if (n == 0) { //n이 0일 때 1을 반환
        return 1;
    }
    else {
        return n * factorial_rec(n - 1); //해당하지 않는다면 n과 n-1의 팩토리얼을 곱한다.
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    // 반복문을 사용해 계산 후 시간을 측정
    start = clock();
    double result_iter = (double)fact_iter(20);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Factorial Iterative Result : %.0f\n", result_iter);
    printf("Time : %f seconds\n", cpu_time_used);

    // 재귀를 사용해 계산 후 시간을 측정
    start = clock();
    double result_rec = (double)factorial_rec(20);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Factorial Recursive Result : %.0f\n", result_rec);
    printf("Time : %f seconds\n", cpu_time_used);

    return 0;
}