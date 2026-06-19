var c = 0;

(function(input) {
    var p = input.split('\n');
    var n = Number(p.shift());
    var A = p.shift().split(' ', n).map(Number);

    mergeSort(A, 0, A.length);

    console.log(A.join(' '));
    console.log(c);
})(require('fs').readFileSync('/dev/stdin', 'utf8'));

function mergeSort(array, left, right) {
    if (left + 1 < right) {
        var mid = Math.floor((left + right) / 2);
        mergeSort(array, left, mid);
        mergeSort(array, mid, right);
        mergeSortSub(array, left, mid, right);
    }

    function mergeSortSub(array, left, mid, right) {
        var n1 = mid - left;
        var n2 = right - mid;
        var leftArray = [];
        var rightArray = [];
        for (var i = 0; i < n1; i++) {
            leftArray.push(array[left + i]);
        }
        for (var i = 0; i < n2; i++) {
            rightArray.push(array[mid + i]);
        }
        leftArray.push(Infinity);
        rightArray.push(Infinity);
        var i = j = 0;
        for (var k = left; k < right; k++) {
            c++;
            if (leftArray[i] <= rightArray[j]) {
                array[k] = leftArray[i];
                i++;
            } else {
                array[k] = rightArray[j];
                j++;
            }
        }
    }
}