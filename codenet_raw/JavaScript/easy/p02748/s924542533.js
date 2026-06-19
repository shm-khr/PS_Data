
function Main(arg)
{
  var A = arg.split("\n")[0].split(" ")[0]-0;
  var B = arg.split("\n")[0].split(" ")[1]-0;
  var M = arg.split("\n")[0].split(" ")[2]-0;


  var reizouko = arg.split("\n")[1].split(" ").map(Number);
  var renzi = arg.split("\n")[2].split(" ").map(Number);
  var waribiki = arg.split("\n").slice(3);
  var max = 0;
  var index = 0;
  for (var i = 0; i < M; i++){
    var tmp = waribiki[i].split(" ")[2] - 0;
    if (max < tmp) {
      max = tmp;
      index = i;
    }
  }

  var a = waribiki[index].split(" ")[0] - 0;
  var b = waribiki[index].split(" ")[1] - 0;

  var c = reizouko[a - 1];
  var d = reizouko[b - 1];

  var reizouko_min = reizouko.reduce((a,b)=>a<b?a:b);
  var renzi_min = renzi.reduce((a, b) => a < b ? a : b);

  console.log(Math.min(c + d - max, reizouko_min + renzi_min));

  return;
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));