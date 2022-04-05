# Consider a telephone book db of N clients. Make use of a hash table implementation to quickly
# look up client's telephone number. Make use of 2 collision handling techniques.
# and compare them using number of comparisons required to find a set of telephone numbers.
# Input : 
#   N clients
# For each client : Name & Telephone No.
# Hash Table:
#       Index     |      Value
#   --------------|------------------
#         0       |        
#         1       |
#         2       |
#         3       |
#         4       |
#         5       |

import sqlite3
from numpy import int64

conn = sqlite3.connect('num_dir.db')
c = conn.cursor()
c.execute("""CREATE TABLE if not exists directory (
        name text,
        number integer
        )""")
c.close()
conn.commit()
conn.close()

def hash(name):
    y = ''
    for ch in name:
        ch = bytes(ch, 'utf-8')
        # print(type(ch)," - ",ch)
        s = str(ch[0])
        # print(type(s)," - ",s)
        y += s
    # print(y)
    return y
def linearProbingWithoutReplacement(name):
    return(int64(name)+1)
def search(name):
    name = hash(name)
    conn = sqlite3.connect('num_dir.db')
    c = conn.cursor()
    c.execute(f"SELECT number FROM directory WHERE name={name}")
    record = c.fetchall()
    c.close()
    conn.commit()
    conn.close()
    print(record)
    if record:
        print(record[0])
        return(1)
    else:
        print("returned 0")
        return(0)
def insert(name, num):
    hname = hash(name)
    conn = sqlite3.connect('num_dir.db')
    c = conn.cursor()
    if(search(name)==0):
        c.execute("INSERT INTO directory VALUES (:name, :number)",
                {
                    'name' : str(hname),
                    'number' : int(num)
                })
        c.close()
    else:
        print(hname)
        hname = linearProbingWithoutReplacement(hname)
        print(hname)
        c.execute("INSERT INTO directory VALUES (:name, :number)",
                {
                    'name' : str(hname),
                    'number' : int(num)
                })
        c.close()
    conn.commit()
    conn.close()

insert("Shrirang", 9404797231)
# search("hello")

