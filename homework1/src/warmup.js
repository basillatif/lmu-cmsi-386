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

function say(a) {
  if (!a) {
    return '';
  }
  return (b) => {
    if (!b) {
      return a;
    }
    return say(a.concat(' ').concat(b));
  };
}

function interleave(arr, ...y) {
  const resultArr = [];
  while (arr.length > 0 || y.length > 0) {
    if (arr.length > 0) {
      resultArr.push(arr.shift());
    }
    if (y.length > 0) {
      resultArr.push(y.shift());
    }
  }
  return resultArr;
}

function cylinder(args) {
  let { radius = 1, height = 1 } = args;
  const surfaceArea = () => (2 * Math.PI * radius * height) + (2 * Math.PI * (radius ** 2));
  const volume = () => Math.PI * (radius ** 2) * height;
  const widen = (multiple) => { radius *= multiple; };
  const stretch = (multiple) => { height *= multiple; };
  const toString = () => `Cylinder with radius ${radius} and height ${height}`;
  return Object.freeze({
    get radius() {
      return radius;
    },
    get height() {
      return height;
    },
    surfaceArea,
    volume,
    widen,
    stretch,
    toString,
  });
}

module.exports = {
  change, stripQuotes, scramble, powers, powersGenerator, cylinder, say, interleave,
};
