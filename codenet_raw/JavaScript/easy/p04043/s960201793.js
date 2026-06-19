function Main(input) {
  // 1行目がinput[0], 2行目がinput[1], …に入る
  //input = input.split("\n");
  tmp = input.split(" ");
  //文字列から10進数に変換するときはparseIntを使います
  const a = parseInt(tmp[0], 10);
  const b = parseInt(tmp[1], 10);
  const c = parseInt(tmp[2], 10);
  let bool = false;
  let ans = "NO";
  if (a === 7 && b === 5 && c === 5) {
    bool = true;
  } else if (a === 5 && b === 7 && c === 5) {
    bool = true;
  } else if (a === 5 && b === 5 && c === 7) {
    bool = true;
  }

  if (bool) {
    ans = "YES";
  }
  //出力
  console.log(ans);
}