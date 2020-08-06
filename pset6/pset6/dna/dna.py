import csv
from sys import argv, exit
import collections


def max_count(s, substring):  # count str
    lent = len(s)
    lensub = len(substring)
    max = 1   # atmost 1 str present
    for i in range(0, lent-lensub):
        if(s[i:i+lensub] == substring):
            count = 1  # count str
            j = i + lensub
            while j < lent-lensub:
                if(s[j:j+lensub] == substring):
                    count = count + 1
                    if max < count:
                        max = count
                    j = j+lensub    
                else:
                    break
            
    h = max  # str presnt 

    return h  # retrun str count
    
    
def main():
    file = open(argv[1], "r")  # open file
    y = csv.reader(file)  # read
    # for x in y:
    #     print(x)
    al = next(y)[1:]  # get string not including name
    # print(al)

    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(0)
    
    strc = argv[2]
    with open(strc) as f:  # open txt file
        s = f.read()  # reading
        # print(s)
        
        strcount = [max_count(s, seq) for seq in al]
        # print(strcount)
        for line in y:
            person = line[0]
            values = [int(val) for val in line[1:]]
            if values == strcount:
                print(person)
                exit(0)
                 
        print("No match")
        file.close()   
 
        
main()
