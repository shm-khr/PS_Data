'use strict'

/////////////////////////////////////
//コピペスペース//////////////////////

//定数
const INF  =  900719925474099 // Math.floor(Number.MAX_SAFE_INTEGER / 10);

//スペース区切りの数字列を数字の配列にして返す
function mapint(line){return line.split(' ').map((v)=>parseInt(v));}

function lower_bound(d,a,b,e){
    for(var c;1<b-a;)
        d[c=0|(a+b)/2]<e ? a=c : b=c;
    return d[a]<e?b:a
};

const MOD = 1000000007;
//コピペスペース//////////////////////
/////////////////////////////////////

function Main(input){
	let temp = input.trim().split('\n');
	let temp2 = mapint(temp[0]);
	let n = temp2[0];
	let l = temp2[1];
	let t = temp2[2]%l;

	let f = mapint(temp[1]);
	let a1 = []; //時計方向
	let a2 = []; //反時計方向
	let ans = new Array(n);
	if(f[1] === 1){
		a1.push(l/2);
		ans[0] = (f[0]+t)%l;
	}else{
		a2.push(l/2);
		ans[0] = (f[0]-t+l)%l;
	}
	for(let i=2;i<=n;i++){
		temp2 = mapint(temp[i]);
		if(temp2[1] === 1){
			if(temp2[0]>f[0]){
				a1.push((l-temp2[0]+f[0])/2);
			}else{
				a1.push((temp2[0]-f[0])/2);
			}
			ans[i-1] = (temp2[0] + t) % l;
		} else {
			if(temp2[0]>f[0]){
				a2.push((temp2[0]-f[0])/2);
			}else{
				a2.push((l+temp2[0]-f[0])/2);
			}
			ans[i-1] = (temp2[0] - t + l) % l;
		}
	}
	a1.sort((a,b)=>a-b);
	a2.sort((a,b)=>a-b);
	ans.sort((a,b)=>a-b);

	//すべて衝突した後の最初のアリの位置計算
	a1.push(INF);
	a2.push(INF);
	let sum=0;
	let t1=0,t2=0;
	let dire=f[1];
	//if(dire === 1)t1++;
	//else t2++;
	for(let i=0;i<n;i++){
		if(dire === 2){
			if(sum + a1[t1] >= t) break;
			//console.log('sum1:',sum,a1[t1]);
			sum += a1[t1++];
			dire = 1;
		}else{
			if(sum + a2[t2] >= t) break;
			//console.log('sum2:',sum,a2[t2]);
			sum += a2[t2++];
			dire = 2;
		}
	}
	t1--;
	t2--;
	a1.pop();
	a2.pop();

	//console.log(f,a1,a2,ans);
	//console.log('sum::::',sum);
	let pos = (t2===-1?0:a2[t2]) - (t1===-1?0:a1[t1]);
	//if(f[1] === 2) pos = -pos;
	let time = t - (t2===-1?0:a2[t2]) - (t1===-1?0:a1[t1]);
	//console.log(pos,time,t1,t2,dire);

	if( dire === 1 ) pos = (pos + time + f[0]) % l;
	else pos = (pos - time + f[0] + l) % l;
	//console.log(pos);

	let low = lower_bound(ans,0,ans.length-1,pos);

	let ans2 = new Array(n);
	//console.log(low);
	for(let i=0;i<n;i++){
		ans2[i] = ans[low];
		low++;
		low %= n;
	}
	//console.log(ans2);
	console.log(ans2.join('\n'));

}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
