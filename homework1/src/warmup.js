function change(amount) {
  let price = amount;
  const result = [];
  if (price < 0) {
    throw new RangeError('the amount cannot be negative');
  }
  [25, 10, 5, 1].forEach((coin) => {
    result.push(Math.floor(price / coin));
    price %= coin;
  });
  return result;
}

function stripQuotes(str) {
  return str.replace(/"|\\|'/g, '');
}

function scramble(str) {
  const arr = str.split('');
  let temp = '';
  for (let i = str.length - 1; i > 0; i -= 1) {
    const rand = Math.floor(Math.random() * (i + 1));
    temp = arr[i];
    arr[i] = arr[rand];
    arr[rand] = temp;
  }
  /* Fisher Yates Algorithm */
  return arr.join('');
}

function powers(base, max, callback) {
  let value = 0;
  let i = 0;
  while (value < max) {
    value = base ** i;
    i += 1;
    if (value <= max) {
      callback(value);
    }
  }
}

function* powersGenerator(base, max) {
  // let [x, y] = [a, b];
  // let i = 0;
  // while (x < y) {
  //   [x, y] = [b, a ** i];
  //   i += 1;
  //   yield a;
  // }
  let value = 0;
  let i = 0;
  while (value < max) {
    value = base ** i;
    i += 1;
    if (value <= max) {
      yield value;
    }
  }
}

module.exports = {
  change, stripQuotes, scramble, powers, powersGenerator,
};
