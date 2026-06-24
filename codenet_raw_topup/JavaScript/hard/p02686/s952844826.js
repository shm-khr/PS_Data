
let input = require("fs").readFileSync("/dev/stdin", "utf8")

function main() {
    const [N] = load(1)
    const S = load(N,1,String)
    
    for(let i = 0; i < N; i++) {
        while(true) {
            let before = S[i]
            S[i] = S[i].split('()').join('')
            if(before !== S[i]) continue
            break
        }
    }

    for(let i = 0; i < N; i++) {
        const s = S[i]
        let dec = s.indexOf('(')
        if(dec === -1) dec = s.length
        S[i] = [-dec, s.length - dec]
    }

    S.sort((a,b) => (b[0]+b[1]) - (a[0]+a[1]))

    let sum = 0
    for(const s of S) {
        sum += s[0]
        if(sum < 0) return 'No'
        sum += s[1]
    }

    return yesno(sum === 0)
}

/*

入力値を読み込む
load(rows = 1, cols = 1, type = Number)

TruthyならYes, FalsyならNo
yesno(boolean) => String

*/


let inputs = input.split(/[\s\n]/)
console.log(main())


// 入力値を読み込む
function load(rows = 1, cols = 1, type = Number) {
    const length = rows * cols
    let result = inputs.splice(0, length)

    if(type !== String) result = result.map(type)
    if(cols > 1) {
        const arrays = new Array(cols)
        for(let col = 0; col < cols; col++) {
            arrays[col] = new Array()
            for(let row = 0; row < rows; row++) {
                arrays[col].push(result[row * cols + col])
            }
        }
        result = arrays
    }

    return result
}

// TruthyならYes, FalsyならNo
function yesno(value) {
    return value ? 'Yes' : 'No'
}
