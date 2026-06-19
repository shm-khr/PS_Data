'use strict'
const Main=input=>{
    input=input.split("\n");
    for(let i=0;i<input.length;i++){
        input[i]=input[i].split(" ");
    }
    const humanNum=parseInt(input[0][0]);
    
    let sheet=new Array(humanNum);
    for(let i=0;i<humanNum;i++){
        sheet[i]=new Array(humanNum).fill(true);
    }
    
    for(let i=1;i<input.length;i++){
        sheet[input[i][0]-1][input[i][1]-1]=false;
        sheet[input[i][1]-1][input[i][0]-1]=false;
        
    }
    for(let i=0;i<humanNum;i++){
        if(i!=0)sheet[i][i-1]=false;
        if(i!=humanNum-1)sheet[i][i+1]=false;
        sheet[i][i]=false;
    }
    
    for(let i=0;i<humanNum;i++){
        let count=0;
        for(let j=0;j<humanNum;j++){
            if(sheet[i][j])count++;
        }
        sheet[i]=count;
    }
    
    console.log(sheet.join(" "));
}

Main(require("fs").readFileSync("/dev/stdin","utf8"));