function Main(input){
  const input_line = input.split('\n');
  const input_1 = input_line[0].split(' ');
  const N = parseInt(input_1[0].trim());
  // console.log("N : " + N);
  const Q = parseInt(input_1[1].trim());
  const S = input_line[1].split('');
  // console.log(S);
  const Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  // 全てのマスにゴーレムが１体ずついる配列を作成
  var golem_num_arr = new Array(N).fill(1);
  // console.log("golem_num_arr : " + golem_num_arr);
  
  // 配列化
  arr = new Array(Alphabet.length);
  for(var i = 0; i < Alphabet.length; i++) {
    arr[i] = [];
  }
  
  var i = 0;
  S.forEach((ch) => {
    arr[Alphabet.indexOf(ch)].push(i);
    i++;
  });
  
  // console.log("arr : " + arr);

  for (var i = 0; i < Q; i++) {
    ss = input_line[i+2].split(' ');
    //console.log(ss);
    mass = ss[0].trim();
    LR = ss[1].trim();
    
    // 該当するアルファベットの配列（例えばBが[1,3,6]、[1,3,5,6]などの連番も注意でLRの順番に考慮）
    // console.log(mass + " : " + arr[Alphabet.indexOf(mass)]);
    if (LR === 'L') {
      arr[Alphabet.indexOf(mass)].forEach((index) => {
        // 左端を超える場合
        if (index === 0) {
          golem_num_arr[index] = 0;
        } else {
          golem_num_arr[index - 1] += golem_num_arr[index];
          golem_num_arr[index] = 0;
        }
      });
    } else if (LR === 'R') {
      arr[Alphabet.indexOf(mass)].reverse().forEach((index) => {   
        // 右端を超える場合
        if (index === (N - 1)) {
          golem_num_arr[index] = 0;
        } else {
          golem_num_arr[index + 1] += golem_num_arr[index];
	      golem_num_arr[index] = 0;
        }
      });
    } //if
    // console.log(golem_num_arr);
  }
  
  var total_num = 0;
  golem_num_arr.forEach((num)=>{
    total_num += num;
  });
  console.log(total_num);

}
 
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
