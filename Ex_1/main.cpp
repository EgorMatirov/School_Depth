#include <algorithm>
#include <stdio.h>
using namespace std;

// Иначе студия ругается на scanf \ printf
#pragma warning(disable:4996)

void solve_a()
{
    int n;
    scanf("%d", &n);
    int max_number = 1 << n;
    int max_position = 1 << (n - 1);
    for (int i = 0; i<max_number; ++i)
    {
        for (int maska = max_position; maska>0; maska >>= 1)
        {
            if((i&maska) == 0)
            {
                printf("+");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
}

void solve_b()
{
    int n;
    scanf("%d", &n);
    int max_number = 1 << n;
    int max_position = 1 << (n - 1);
    for (int i = 0; i<max_number; ++i)
    {
        int num = 1;
        for (int maska = max_position; maska>0; maska >>= 1)
        {
            if ((i&maska) == 0)
            {
                printf("+");
            }
            else
            {
                printf("-");
            }
            printf("%d", num);
            ++num;
;        }
        printf("\n");
    }
}

void solve_c()
{
    int m;
    scanf("%d", &m);
    int n = 9;
    int max_number = 1 << n;
    int max_position = 1 << (n - 1);
    for (int i = 0; i<max_number; ++i)
    {
        int balance = -m;
        for (int maska = max_position, num = 1; maska>0; maska >>= 1, ++num)
        {
            if ((i&maska) == 0)
            {
                balance += num;
            }
            else
            {
                balance -= num;
            }
        }
        if(balance == 0)
        {
            for (int maska = max_position, num = 1; maska>0; maska >>= 1, ++num)
            {
                if ((i&maska) == 0)
                {
                    printf("+");
                }
                else
                {
                    printf("-");
                }
                printf("%d", num);
            }
            printf("\n");
        }
    }
}

void solve_d()
{
    int n, prev;
    scanf("%d", &n);
    scanf("%d", &prev);
    for (int i = 1; i<n; ++i)
    {
        int diff = 0;
        int current;
        scanf("%d", &current);
        int maska = 1;
        while(maska < max(prev, current))
        {
            maska<<=1;
        }
        for(; maska > 0; maska >>=1)
        {
            if((prev&maska) != (current&maska))
            {
                ++diff;
            }
        }
        if (diff != 1)
        {
            printf("NO\n%d\n", i);
            return;
        }
        prev = current;
    }
    printf("YES\n");
}

void solve_e()
{
    int w, n;
    int W_i[10];
    scanf("%d", &n);
    scanf("%d", &w);
    for (int i = 0; i < n; ++i)
        scanf("%d", &W_i[i]);
    int max_number = 1 << n;
    for (int k = 0; k<max_number; ++k)
    {
        for (int i = 0; i<max_number; ++i)
        {
            int balance = w;
            for (int j = n; j > 0; --j)
            {
                int p = 1 << (j-1);
                if ((k&p) != 0 && (i&p) != 0)
                    balance -= W_i[n - j];
                if ((k&p) != 0 && (i&p) == 0)
                    balance += W_i[n - j];
            }
            if (balance == 0)
            {
                printf("YES\n");
                for (int j = n; j > 0; --j)
                {
                    int p = 1 << (j - 1);
                    if ((k&p) != 0 && (i&p) == 0)
                        printf("%d ", W_i[n - j]);
                }
                printf("\n");
                for (int j = n; j > 0; --j)
                {
                    int p = 1 << (j - 1);
                    if ((k&p) != 0 && (i&p) != 0)
                        printf("%d ", W_i[n - j]);
                }
                printf("\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main()
{
    //solve_a();
    //solve_b();
    //solve_c();
    //solve_d();
    //solve_e();
    return 0;
}