function main(input) {
  const args = input.split('').reverse().join('');
  
  while(true){var rplc1 = /maerd/g;
  var rplc2 = /remaerd/g;
  var rplc3 = /esare/g;
  var rplc4 = /resare/g;
  var i = args.replace(rplc1,'');
  var j = i.replace(rplc2,'');
  var k = j.replace(rplc3,'');
  var l = k.replace(rplc4,'');
  var m = l === '';
  if(m){break;}
  }
  
  if(!m){
    console.log('NO');
  }else if(m){
    console.log('YES');
  }
  
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));