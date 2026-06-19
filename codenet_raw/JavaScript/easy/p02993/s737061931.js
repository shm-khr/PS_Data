  function test(password) {
  var array = password.split("");
  var temp = "";

  if (array.length !== 4) {
    return;
  }

  for(const value of array) {
    if (!temp) {
      temp = value;
      continue;
    } else {
      if (temp === value) {
        console.log("Bad");
        return;
      } else {
        temp = value;
      }
    }
  }

  console.log("Good");
  }