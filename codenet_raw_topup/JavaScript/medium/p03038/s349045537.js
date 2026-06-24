

function Main(input) {
  input = input.split("\n");
  var N = parseInt(input[0].split(" ")[0]);
  var M = parseInt(input[0].split(" ")[1]);
  var A = new Array();
  var t = new Array(M);
  for(var i=0;i<M;i++){
    var tmp=new Array(parseInt(input[i+2].split(" ")[0]),parseInt(input[i+2].split(" ")[1]));
    t[i]=tmp;
  }
  var max=0;
  var memo=new Array(Math.pow(10,5));
  var set=new Set();
  for(var i=0;i<N;i++){
    a=parseInt(input[1].split(" ")[i]);
    if(memo[a]==undefined){
      memo[a]=1;
    }else{
      memo[a]++;
    }
    max=Math.max(max,a);
    set.add(a);
  }
  for(var i=0;i<M;i++){
    var b=parseInt(input[i+2].split(" ")[0]);
    var c=parseInt(input[i+2].split(" ")[1]);
    if(memo[c]==undefined){
      memo[c]=b;
    }else{
      memo[c]+=b;
    }
    max=Math.max(max,c);
    set.add(c);
  }
  var set2=[...set];
  set2.sort(function(a,b){return b-a});
  var ans=0;
  var cnt=0;
  for(var i=0;i<set2.length;i++){
    if(cnt+memo[set2[i]]<=N){
      ans=ans+memo[set2[i]]*set2[i];
      cnt+=memo[set2[i]];
    }else if(cnt+1<=N){
      ans=ans+set2[i]*(N-cnt);
      cnt+=N-cnt;
    }else{
      break;
    }
  }


  console.log('%s', ans);
  return ans;
}

function debug(n){
  var input = document.getElementById("input"+n).value;
  var ans=Main(input);
  var result="WA";
  if(ans==document.getElementById("output"+n).value.split("\n")[0]){
    result="AC";
  }
  document.getElementById("result"+n).innerHTML=result;
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));