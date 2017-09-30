# change, strip_quotes, scramble, say, triples, powers,
#                    interleave, Cylinder, make_crypto_functions, random_name
import re;

def change(price):
    if price < 0:
        raise ValueError('amount cannot be negative')
    coins = [25, 10, 5, 1]
    results = []
    remaining = price
    for coin in coins:
        d = divmod(remaining, coin)
        results.append(d[0])
        remaining = d[1]
    return tuple(results)

def strip_quotes(s):
    return re.sub(r'\'|\"', '', s)

def scramble(s):
    return s

def say(s):
    return s

def triples(number):
    return number

def powers(base, maximum):
    return base * maximum

def interleave(array, *args):
    return array + args

def Cylinder(radius=1, height=1):
    return radius + height

def make_crypto_functions(s, key):
    return s + key

def random_name(gender, region):
    return gender + region
