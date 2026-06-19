function Main(input) {

  input = input.split("\n");
  var N = parseInt(input[0].split(" ")[0]);
  var Q = parseInt(input[0].split(" ")[1]);
  var S = input[1];

  var l = Array(input.length-2);
  var r = Array(input.length-2);

  for(var i = 2; i < input.length; i ++){
    l[i-2] = parseInt(input[i].split(" ")[0]);
    r[i-2] = parseInt(input[i].split(" ")[1]);
  }

  var AtCoder = function(){
    this.dp = Array(N+1).fill(0);
  };

  AtCoder.prototype = {
    procedure: function(){
      for(let i = 0; i < N; i++){
        this.dp[i] = S.substring(0,i).split("AC").length -1;
      }
      this.dp[N] = this.dp[N-1];
      debugger;
      for(let i = 0; i < Q; i++){
        console.log(this.dp[r[i]]-this.dp[l[i]]);
      }
    }
  }
  var atcoder = new AtCoder();
  atcoder.procedure();
}
// try{
  Main(require("fs").readFileSync("/dev/stdin", "utf8"));
// }catch(e){
//   var input=``
//   Main(input);
// }
