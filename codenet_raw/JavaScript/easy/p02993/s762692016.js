function test(password) {
  let array = password.split("");

  const t = (() => {
    let temp = "";

    for (const value of array) {
      if (!temp) {
        temp = value;
        continue;
      }

      if (temp === value) {
        return false;
      } else {
        temp = value;
      }
    }

    return true
  })();

  if (t) {
    console.log("Good");
  } else {
    console.log("Bad");
  }
}