function Main(input) {
var arr = input.split('\n').map(row => row.split(" ").map(el => Number(el)))

var A = arr[0][0]
var B = arr[0][1]
var M = arr[0][2]
var price = {
  a: arr[1],
  b: arr[2]
}


var lowest1 = 100000
var my_price = 0

var coupons = arr.splice(3, 3)

coupons.map(coupon => {


  my_price = price.a[coupon[0] - 1] + price.b[coupon[1] - 1] - coupon[2]
  //console.log(price.a[coupon[0]-1], price.b[coupon[1]-1], coupon[2])

  if (my_price < lowest1) {
    lowest1 = my_price
  }

})

var lowest2 = Math.min(...price.a) + Math.min(...price.b)

if (lowest1 <= lowest2) {
  console.log(lowest1)
} else {
  console.log(lowest2)
}
}
Main(require("fs").readFileSync("/dev/stdin", "utf8"));