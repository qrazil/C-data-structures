#include <stdio.h>
#include <math.h>
#include <stdbool.h>


bool sieve(int max)
{
    bool flags[max];
    init(flags,max);
    int count=0;
    int prime=2;
    while(prime<=sqrt(max))
    {
        cross_off(flags,prime,max);
        prime=next_prime(flags,prime,max);
    }
    printf("The list of primes till %d are:\n",max);
    for(count=0; count<max; count++)
    {
        if(flags[count]==true)
        {
            printf("%d\n",count);
        }
    }
}
void init(bool flags[], int max)
{
    int i;
    for(i=1; i<max ; i++)
    {
        flags[i]=true;
    }
}
void cross_off(bool flags[], int prime, int max)
{
    int i;
    for ( i=prime*prime ; i < max ; i+=prime )
    {
        flags[i]=false;
    }
}
int next_prime(bool flags[],int prime, int max)
{
    int next=prime+1;
    while(next < max && !flags[next])
    {
        next++;
    }
    return next;
}
int main()
{
    sieve(100);
    return 0;
}
