input = require('fs').readFileSync('/dev/stdin', 'utf8')
lines = input.split('\n')
line = lines.shift().split(' ')
N = line[0] * 1
K = line[1] * 1 
A = lines.shift().split(' ')

_makePriorityQueue = (arr, max) => {
  var idx = ~~(arr.length / 2)
  return _heapify(arr, idx, max);
}


_heapify = (arr, idx, max) =>  {
  while(idx >= 0) {
    var min = max ?  _swapHeapMax(arr, idx) : _swapHeapMin(arr, idx)
    if (min != idx) {
        idx = min
    } else {
        idx = idx - 1
    }
  }
  return arr
}

_swapHeapMin = (arr, idx) =>  {
    var left = idx * 2 + 1
    var right = idx * 2 + 2
    var min = idx
    if (left < arr.length && arr[left] * 1 < arr[idx] * 1) {
      min = left
    }
    if (right < arr.length && arr[right] * 1 < arr[min] * 1) {
      min = right
    }
    if (min != idx) {
      var tmp = arr[idx]
      arr[idx] = arr[min]
      arr[min] = tmp
    }
    return min
}


_swapHeapMax = (arr, idx) =>  {
    var left = idx * 2 + 1
    var right = idx * 2 + 2
    var min = idx
    if (left < arr.length && arr[left] * 1 > arr[idx] * 1) {
      min = left
    }
    if (right < arr.length && arr[right] * 1 > arr[min] * 1) {
      min = right
    }
    if (min != idx) {
      var tmp = arr[idx]
      arr[idx] = arr[min]
      arr[min] = tmp
    }
    return min
}


_popPrioriyQueue = (a, max) => {
    var tmp = a[0]
    a[0] = a[a.length - 1]
    a.pop()
    a = _heapify(a, 0, max)
    return tmp
}

_pushPrioriyQueue = (a, d, max) => {
    a.push(d)
    a = _heapify(a, a.length, max)
}

_makePriorityQueue(A, true)
for(i=0; i<K; i++) {
    a = _popPrioriyQueue(A, true)
    _pushPrioriyQueue(A, ~~(a / 2), true)
}

sum = A.reduce((s, c) => s += c * 1, 0)
console.log(sum)
