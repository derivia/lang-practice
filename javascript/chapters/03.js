const myMin = (a, b) => {
  if (a < b) return a;
  return b;
}

const isEven = (n) => {
  if (n == 0) return true;
  else if (n == 1) return false;
  else if (n < 0) return isEven(-n);
  return isEven(n - 2);
}

const countChar = (string, char) => {
  let charCount = 0;
  for (stringChar of string) {
    if (char === stringChar) charCount++;
  }
  return charCount;
}

console.log(countChar("lorran", 'r'));
