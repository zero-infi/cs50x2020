#include <cs50.h>
#include <stdio.h>

void lenght(long n);      //function declartion
void checksum(long n);    //function declartion
int main(void)
{

    long no = get_long("Enter your credit card no. :");
    lenght(no);          // function call

}
void lenght(long n)                // to check card  is 13-16 no.or not
{
    if (n < 1000000000000 || n > 10000000000000000)
    {
        printf("INVALID\n");
    }
    else
    {
        checksum(n);    //function call
    }
}

void checksum(long n)   // to check whether it is valid or not or belongs to which card service company
{  
    long t = n;
    static int sum = 0;
    static int sum1 = 0;
    int r;
    while (n != 0)                              // calculating sum and sum 1
    {
        sum += n % 10;
        n = n / 10;

        r = (n % 10) * 2;
        if (r >= 10)
        {
            sum1 += r % 10;
            r = r / 10;
            sum1 += r % 10;
            r = r / 10;
            n = n / 10;
        }
        else
        {
            sum1 += r;
            n = n / 10;
        }
    }
    int usum = sum + sum1;   
    printf("%i",usum);//give the sum 
    usum = usum %  10;                                // checking usum last last digit is 0 or not
    if (usum == 0)
    {
        while (t > 100)
        {
            t /= 10;
        }
        if (t == 34 || t == 37)
        {
            printf("AMEX\n");                           //check for AMEX card
        }
        else if (t >= 51 && t <= 55)
        {
            printf("MASTERCARD\n");                     //check for MASTERCARD
        }
        else
        {
            t /= 10;
            if (t == 4)
            {
                printf("VISA\n");                       //check for VISA card
            }
            else
            {
                printf("INVALID\n");                    //case for an invalid type number with correct checksum
            }
        }
    }
    else 
    {
        printf("INVALID\n");          // card is not vaild
        
    }
   
}

