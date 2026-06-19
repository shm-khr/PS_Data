function r(str){
let out ="";
  for(i = str.lenght; i > 0 ; i--){
   out += str.charAt(i-1);
  }
return out;
};
 
 
if(r(s) == s){
  let b = s.substring((s.lenght-1)/2));
  if(r(b) = b){
    let c = s.substring((s.lenght+3)/2));
    if(r(c) = c){
      console.log("Yes");
    }else{console.log("No");}
  }else{console.log("No");}
}else{console.log("No");}