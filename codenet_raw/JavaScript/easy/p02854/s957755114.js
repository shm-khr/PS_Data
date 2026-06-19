function Main(input) {
  var inputs = input.split('\n')
  var branch_number = inputs[0]
  var branches = inputs[1].split(' ')
  var result = 0

  var sum = parseInt(branches[0])
  var branch_sum = []
  branch_sum[0] = parseInt(branches[0])
  for (i = 1; i < branch_number; i++) {
    sum += parseInt(branches[i])
    branch_sum[i] = branch_sum[i-1] + parseInt(branches[i])
  }

  var half = sum / 2

  var j = 0
  var flag = false
  var index = 0
  while (!flag) {
    if (Math.abs(branch_sum[j] - half) <= Math.abs(branch_sum[j+1] - half)) {
      index = j
      flag = true
    }
    j++
  }
  // 割れたら終わり
  if (branch_sum[index] === half) {
    console.log(result)
    return
  }

  var center = branch_sum[index]

  var plus = false
  if (center < half) {
    plus = true
  }
while (center !== half) {
    result++
    if (plus) {
      center++
      sum++
      half = sum / 2
    } else {
      center--
      sum--
      half = sum / 2
    }
  }

  console.log(result)

}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));