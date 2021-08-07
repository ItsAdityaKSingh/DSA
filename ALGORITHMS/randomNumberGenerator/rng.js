// noprotect

let canvas = document.createElement("canvas")
canvas.id = "canvas"

var digits = 10,
    seed = 1234567890

var s = seed
let y = 0


function nextRand() {
  var n = (seed*seed).toString()
  while(n.length<2*digits) {
    n = '0' + n
  }
  var begin = parseInt(digits/2)
  var end = begin + digits
  seed = parseInt(n.substring(begin,end))
  return seed
}


function nextRandfloat() {
  return nextRand()/9999999999;
}


// var ct = 600, N = 0
// for(var i=0;i<ct;i++) {
//   let rand = nextRandfloat()
//   if(rand>0.5) {
//     N++
//     console.log(rand)
//   }
// }
// console.log(N)

// var results = []
// for(var i=0;i<ct;i++) {
//   var rand = nextRand()
//   if(results[rand]) break;
//   results[rand] = true
// }
// console.log(i)


draw()
var context = canvas.getContext("2d")
console.log(canvas)
function draw() {
   for(var x=0;x<600;x++){
    //console.log(x)
     if(nextRandfloat < 0.5) {
       context.fillRect(0,0,600,600)
    }
  }
  y++
  console.log(y)
  if(y<600) {
    requestAnimationFrame(draw)
    //draw()
  }  
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
