import cs50
import csv
from sys import argv, exit

if len(argv) != 2:  # check argument
    print("Usage: python ")
    exit(1)

db = cs50.SQL("sqlite:///students.db")        
rows = db.execute("SELECT first,middle,last,birth FROM students WHERE house=? order by last, first", argv[1])
for row in rows:  # to print and check middle name 
    if row['middle'] != None:
        print(row['first'], row['middle'], row['last'], 'born', row['birth'])
    else:
        print(row['first'], row['last'], ',', 'born', row['birth'])