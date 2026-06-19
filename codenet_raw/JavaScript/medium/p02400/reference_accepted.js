r = Number(require('fs').readFileSync('/dev/stdin', 'utf8'))
console.log([r*r,r*2].map(n=>(n*Math.PI).toFixed(6)).join(' '))
