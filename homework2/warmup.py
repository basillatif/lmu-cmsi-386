import re
import random
import math
import json
from Crypto.Cipher import AES
import requests


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


def interleave(l, *args):
    first_length = len(l)
    second_length = len(args)
    result = []
    maximum = max(first_length, second_length)
    for i in range(0, maximum):
        if i < first_length:
            result.append(l[i])
        if i < second_length:
            result.append(args[i])
    return result


class Cylinder:
    def __init__(self, radius=1, height=1):
        self.radius = radius
        self.height = height

    @property
    def volume(self):
        return math.pi * (self.radius ** 2) * self.height
    @property
    def surface_area(self):
        return 2 * math.pi * self.radius * self.height + 2 * math.pi * (self.radius**2)

    def widen(self, multiple):
        self.radius = self.radius * multiple

    def stretch(self, multiple):
        self.height = self.height * multiple


def make_crypto_functions(key, iv):
    def encrypt(s):
        obj = AES.new(key, AES.MODE_CBC, iv)
        return obj.encrypt(s)
    def decrypt(s):
        obj = AES.new(key, AES.MODE_CBC, iv)
        return obj.decrypt(s)
    return (encrypt, decrypt)


def random_name(**params):
    params['amount'] = 1
    r = requests.get('https://uinames.com/api/', params)
    if r.status_code not in range(200, 300):
        raise ValueError(r.text)
    obj = json.loads(r.text)
    full_name = '{}, {}'.format(obj['surname'], obj['name'])
    return full_name
