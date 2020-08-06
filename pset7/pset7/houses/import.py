import cs50
import csv
from sys import argv, exit

if len(argv) != 2:  # check argument 
    print("Usage: python ")
    exit(1)

open(f"students.db", "w").close()   
db = cs50.SQL("sqlite:///students.db")  # create database

db.execute("CREATE TABLE students(first name TEXT,middle name TEXT,last name TEXT, house TEXT, birth NUMERIC)")
# create table 

with open(argv[1], "r") as f:  # open file
    reader = csv.DictReader(f)
    for row in reader:   
        names = row["name"].split()
        if len(names) == 3:
            db.execute("INSERT INTO students (first,middle,last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       names[0], names[1], names[2], row["house"], row["birth"])
        else:
            db.execute("INSERT INTO students (first,middle,last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       names[0], None, names[1], row["house"], row["birth"])
                