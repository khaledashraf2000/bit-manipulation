#include <stdio.h>

/*
 * x is a power of two if it only has one 1 in 
 * its binary represenation. By flipping all other
 * bits and passing x with ~x through and gate,
 * if it produced 0 then all other bits were 0,
 * and hence it is a power of two.
 */
int ispoftwo(int x)
{
    return !(x & ~x) ? 1 : 0;
}

/*
 * We can remove the rightmost 1 by passing 
 * x and x - 1 through & gate, this works becuase
 * x - 1 flips rightmost set bit in x and all 
 * other bits set to its right (to compensate 
 * the removal of 1), and by anding this number
 * with the original one we can obtain a number
 * without the rightmost one. Repeat this process
 * till the number becomes 0 (has no ones).
 */
int nofone(int x)
{
    int count = 0;
    while(x)
    {
        x = x & (x - 1);
        count++;
    }
    return count;
}

/*
 * 1 << i represents 2^i, by anding it
 * with the target number we can find if
 * ith bit is set or not.
 */
int isset(int x, int i)
{
    return x & (1 << i);
}

/*
 * By creating a binary number with length n,
 * incrementing it with 1 steps, and looking
 * for set bits as to choose this position in
 * the array and off bits and not to choose it,
 * we can print all possible subsets of an array.
 */
void subset(int* a, size_t n)
{
    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(isset(i, j))
            {
                printf("%d ", *(a + j));
            }
        }
        printf("\n");
    }
}

/*
 * -x is the two's complement of x, where
 * all bits of x are flipped then 1 is added,
 * therefore x & -x will return the rightmost 
 * set bit.
 */
int rightmostone(int x)
{
    return x & (-1 * x);
}