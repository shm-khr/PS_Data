config = { input: 'tmp', newline: '\r\n' }; // win
//config = { input: '/dev/stdin', newline: '\n' }; // linux

line = require('fs').readFileSync(config.input, 'ascii')
  .split(config.newline, 2);

S = line[1].split(' ').map(Number);
sorted = [].concat(S);
cnt = 0;
mergeSort(sorted, 0, sorted.length);
console.log(sorted.join(' '));
console.log(cnt);

function merge(A, left, mid, right) {
  var n1, n2, L, R, i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  L = new Array(n1 + 1);
  R = new Array(n2 + 1);
  for (i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = Number.POSITIVE_INFINITY;
  R[n2] = Number.POSITIVE_INFINITY;
  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    } else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

function mergeSort(A, left, right) {
  var mid;
  if (left+1 < right) {
    mid = Math.floor((left + right) / 2);
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}