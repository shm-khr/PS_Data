"use strict";
    
class PriorityQueue {
  constructor() {
    this.heap = [];
  }

  push(item) {
    let heap = this.heap;
    let i = heap.length++;
    let j;

    while(i) {
      j = Math.floor((i - 1) / 2);
      if(heap[j] <= item) break;
      heap[i] = heap[j]
      i = j;
    }

    heap[i] = item;
  }

  pop() {
    let heap = this.heap;
    let top = heap[0];
    let popped = heap.pop();

    let i = 0;
    let k = Math.floor(heap.length / 2);
    let j;

    while(i < k) {
      j = (i * 2) + 1;
      if(heap[j+1] < heap[j]) ++j;

      if(popped <= heap[j]) break;

      heap[i] = heap[j];

      i = j;
    }

    if(heap.length) {
      heap[i] = popped;
    }

    return top;
  }

  size() {
    return this.heap.length;
  }

  top() {
    return this.heap[0];
  }
}

const main = arg => {
    arg = arg.trim().split("\n");
    const N = parseInt(arg[0].split(" ")[0]);
    const M = parseInt(arg[0].split(" ")[1]);
    
    const A = arg[1].split(" ").map(n=>parseInt(n));
    const B = arg.slice(2, M + 2).map(n=>n.split(" ").map(l=>parseInt(l)));
    
    B.sort((a,b)=>b[1] - a[1])
    
    let pq = new PriorityQueue();
    
    for(let i=0; i<N; i++) {
        pq.push(A[i]);
    }
    
    // console.log(pq.heap)
    
    for(let i=0; i<M; i++) {
        let target = B[i][0];
        let num = B[i][1];
        
        let temp = pq.top();
        
        for(let j=0; j<target; j++) {
            if(num > temp) {
                pq.pop();
                pq.push(num);
            } else {
                break;
            }
        }
    }
    
    console.log(pq.heap.reduce((m,n)=>m+n));
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));