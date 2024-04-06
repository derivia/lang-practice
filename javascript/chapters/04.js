// These could be better, i'm not in the mood

const isPositive = (number) => {
  return number > 0;
};

const mySum = (numbers) => {
  let sum = 0;
  for (let number of numbers) {
    if (isNaN(number)) {
      return -1;
    }
    sum += number;
  }
  return sum;
};

const myRange = (start, end, step = 1) => {
  let range = [];
  let current = start;
  if (isPositive(step)) {
    for (let i = 0; current <= end; i++) {
      range.push(current);
      current += step;
    }
  } else {
    for (let i = 0; current >= end; i++) {
      range.push(current);
      current += step;
    }
  }
  return range;
};

const reverseArray = (array) => {
  let newArray = [];
  for (element in array) {
    newArray[element] = array.length - element;
  }
  return newArray;
}

const reverseArrayInPlace = (array) => {
  for (element in array) {
    array[element] = array.length - element;
  }
  return array;
}
