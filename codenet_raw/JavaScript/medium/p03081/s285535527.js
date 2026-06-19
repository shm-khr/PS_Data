function Main(input){
  const input_line = input.split('\n');
  const input_1 = input_line[0].split(' ');
  const N = parseInt(input_1[0].trim());
  // console.log("N : " + N);
  const Q = parseInt(input_1[1].trim());
  const S = input_line[1].split('');
  // console.log(S);
  const Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  // 先頭、末尾に番兵法的に値を入れるための変数
  const shift_num = 1;
  
  // 全て（N）のマスにゴーレムが１体ずついる配列を作成（先頭末尾をかさ増し）
  var golem_num_arr = new Array(N + shift_num * 2).fill(1);
  // console.log("golem_num_arr : " + golem_num_arr);
  
  // アルファベットの配列初期化（order 1）
  arr = new Array(Alphabet.length);
  for(var i = 0; i < Alphabet.length; i++) {
    arr[i] = [];
  }
  
  // それぞれのアルファベットがSの何番目に現れているのか（order N）
  var i = 0;
  S.forEach((ch) => {
    arr[Alphabet.indexOf(ch)].push(i + shift_num);
    i++;
  });
  
  //arr.forEach((list)=>{
  //  console.log("arr : " + list);
  //});

  // （order NxN）
  for (var i = 0; i < Q; i++) {
    var ss = input_line[i+2].split(' ');
    // console.log(ss);
    var mass = ss[0].trim();
    var LR = ss[1].trim();
    var Alphabet_index = Alphabet.indexOf(mass);
    
    // 該当するアルファベットの配列（例えばBが[1,3,6]）（order N）
    // console.log(mass + " : " + arr[Alphabet.indexOf(mass)]);
    if (LR === 'L') {
      // console.log("err : " + arr[Alphabet_index]);
      arr[Alphabet_index].forEach((index) => {
        golem_num_arr[index - 1] += golem_num_arr[index];
        golem_num_arr[index] = 0;
      });
    } else {
      arr[Alphabet_index].reverse().forEach((index) => { 
        golem_num_arr[index + 1] += golem_num_arr[index];
	    golem_num_arr[index] = 0;
      });
    } //if
    // console.log(golem_num_arr);
  }
  
  // （order N）
  var total_num = 0;
  // 先頭末尾を除いて合計する
  for (var i = 1; i < (N + 1); i++) {
    total_num += golem_num_arr[i];
  }
  
  console.log(total_num);

}
 
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
