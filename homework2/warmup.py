# change, strip_quotes, scramble, say, triples, powers,
#                    interleave, Cylinder, make_crypto_functions, random_name
import re
import random

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
    c = list(s)
    for item_index in range(0, len(c)-1):
        random_int = random.randint(item_index, len(c)-1)
        c[item_index], c[random_int] = c[random_int], c[item_index]
    return ''.join(c)

def say(a=''):
    if a == '':
        return a
    def say2(b=''):
        if b == '':
            return a
        return say('{} {}'.format(a, b))
    return say2

def triples(end):
    result = []
    for a in range(1, end+1):
        for b in range(1, end+1):
            for c in range(1, end+1):
                if a**2 + b**2 == c**2 and a < b and b < c:
                    result.append((a, b, c))
    return result

def powers(base, maximum):
    value = 1
    p = 1
    while value <= maximum:
        yield value
        value = base**p
        p += 1

def interleave(array, *args):
    return array + args

def Cylinder(radius=1, height=1):
    return radius + height

def make_crypto_functions(s, key):
    return s + key

def random_name(gender, region):
    return gender + region
