#include <stdio.h>
#include <time.h>

unsigned long long fact_iter(int n) { //�ݺ����� ���
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) { //1���� n������ ���ڸ� ���Ͽ� ���
        result *= i;
    }
    return result;
}

unsigned long long factorial_rec(int n) { //��͸� ���
    if (n == 0) { //n�� 0�� �� 1�� ��ȯ
        return 1;
    }
    else {
        return n * factorial_rec(n - 1); //�ش����� �ʴ´ٸ� n�� n-1�� ���丮���� ���Ѵ�.
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    // �ݺ����� ����� ��� �� �ð��� ����
    start = clock();
    double result_iter = (double)fact_iter(20);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Factorial Iterative Result : %.0f\n", result_iter);
    printf("Time : %f seconds\n", cpu_time_used);

    // ��͸� ����� ��� �� �ð��� ����
    start = clock();
    double result_rec = (double)factorial_rec(20);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Factorial Recursive Result : %.0f\n", result_rec);
    printf("Time : %f seconds\n", cpu_time_used);

    return 0;
}