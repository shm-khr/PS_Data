function Main(input) {
  input = input.split('\n');
  tmp = input[0].split(' ');
  heights = input[1].split(' ');
  numFriends = tmp[0];
  minHeight = tmp[1]; 
  var count = 0;

//console.log('data heights: ' + heights);
//console.log('data numFriends: ' + numFriends);
//console.log('data minHeight: ' + minHeight);
  for(var i = 0; i < numFriends; i++) {
    if(heights[i] >= minHeight) {
      count++;
    }
  }
  console.log(count);
}
Main(require('fs').readFileSync('/dev/stdin', 'utf-8'));
