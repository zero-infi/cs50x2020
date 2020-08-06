from cs50 import get_string

s = list()
scount = 0
lcount = 0
wcount = 1
k = get_string("Text:")
for i in range(0, len(k)):
    if k[i] == '.' or k[i] == '!' or k[i] == '?':
        scount += 1
    elif k[i] == ' ':
        wcount += 1
    else:
        if k[i] >= 'a' and k[i] <= 'z':  # check small letter
            lcount += 1
        elif k[i] >= 'A' and k[i] <= 'Z':  # check capital
            lcount += 1
# print(lcount)
# print(scount)
# // printf("%i\n",wcount);
# //  float w = (float) 100 / words;
# // float L = letters * w;
# // float S = (float) sentences / words;
w = 100 / wcount
L = lcount * w
S = scount / wcount
S *= 100
I = 0.0588 * L - 0.296 * S - 15.8
index = round(I)

if index < 1:
    print("Before Grade 1")
    
elif (index > 16):
    print("Grade 16+")
    
else:
    print("Grade", index)