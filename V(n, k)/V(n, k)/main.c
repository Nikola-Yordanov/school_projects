#include <stdio.h>
#include <stdlib.h>

void print(int k, int* curr_variation)
{
    for (int i = 0; i < k; i++)
        printf("%d ", curr_variation[i]);
    printf("\n");
}

void get_variation(int n, int k, int idx, int used, int* curr_variation) {
    if (idx == k) {
        print(k, curr_variation);
        return;
    }

    for (int i = 0; i < n; i++)
        if (!(used & (1 << i)))
        {
            curr_variation[idx] = i + 1;
            get_variation(n, k, idx + 1, used | (1 << i), curr_variation);

        }
}
void print_variations(int n, int k)
{
    if (n < k)
    {
        printf("Wrong!!!\n");
        return;
    }

    int* curr_variation = malloc(sizeof * curr_variation * k);

    get_variation(n, k, 0, 0, curr_variation);

    free(curr_variation);
}

int main()
{
    print_variations(5, 3);
    return 0;
}
