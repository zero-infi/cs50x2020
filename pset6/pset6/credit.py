from cs50 import get_int


def main():
    no = get_int("Enter your credit card no. :")
    lenght(no)  # function call


def lenght(n):  # to check card  is 13-16 no.or not
    if n < 1000000000000 or n > 10000000000000000:
        print("INVALID")
    else:
        checksum(n)  # function call

        
def checksum(n):    # to check whether it is valid or not or belongs to which card service company
    t = n
    su = 0
    sum1 = 0
    r = 0
    while n != 0:   # calculating sum and sum 1
        su += n % 10
        n = n // 10
        r = (n % 10) * 2
        if r >= 10:
            sum1 += r % 10
            r = r // 10
            sum1 += r % 10
            r = r // 10
            n = n // 10
        
        else:
            sum1 += r
            n = n // 10
    
  # print(su, sum1)
    usum = su + sum1
    print(usum)        # give the sum 
    usum = usum % 10  # checking usum last last digit is 0 or not
    if usum == 0:
        while t > 100:
            t = t // 10
        
        if t == 34 or t == 37:
            print("AMEX")   # check for AMEX card
        elif t >= 51 and t <= 55:
            print("MASTERCARD")  # check for MASTERCARD
        
        else:
            t = t // 10
            if t == 4:
                print("VISA")  # check for VISA card
            
            else:
                print("INVALID")   # case for an invalid type number with correct checksum
    else:
        print("INVALID")  # card is not vaild
 
        
main()