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

address_book = {}
def hash(name):
    y = ''
    for ch in name:
        ch = bytes(ch, 'utf-8')
        s = str(ch[0])
        y += s[2]
    return y

def insert(index, num):
    address_book[index] = num

i = hash("hello")
insert(i, 9404797231)
print(address_book[i])