function Main (input) {
  const inputs = input.split(/\s/g);
  const arrayLength = inputs[0];
  const selectLength = inputs[1] - 1;

  if (arrayLength <= inputs[1]) return console.log('%s', 1);

  const result = arrayLength % selectLength === 0
    ? arrayLength / selectLength
    : Math.floor(arrayLength / selectLength);

  console.log('%s', result);
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
