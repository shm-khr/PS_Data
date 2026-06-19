function a(password) {
  const array = password.split("");
  let temp = "";

  if (array.length !== 4) {
    return;
  }

  for(const value of array) {
    if (!temp) {
      temp = value;
      continue;
    } else {
      if (temp === value) {
        return false;
      } else {
        temp = value;
      }
    }
  }

  return true;
}
