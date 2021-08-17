// noprotect

window.onload = function () {
  window.onload = function() {
    var c=document.getElementById("canvas");
    var cxt=c.getContext("2d");
    cxt.fillStyle="#FF0000";
    cxt.fillRect(0,0,150,75);
}
Share
}

//middle square method:
var digits = 10,
    seed = 1234568901;

function nextRand() {
  var n = (seed * seed).toString();
  while(n.length < digits * 2) {
    n = "0" + n;
  }
  var start = Math.floor(digits / 2),
      end = start + digits;
  seed = parseInt(n.substring(start, end));
  return seed;
}

function nextRandFloat() {
  return nextRand() / 9999999999;
}

for(var i = 0; i < 20; i++) {
  console.log(nextRandFloat());
}

// var results = [];
// for(var i = 0; i < 100000; i++) {
//   var rand = nextRand();
//   if(results[rand]) {
//     break;
//   }
//   results[rand] = true;
// }
// console.log(i);

// linear congruential generator

// var a = 1664525,
//     c = 1013904223,
//     m = Math.pow(2, 32),
//     seed = 12234;

// function nextRand() {
//   seed = (a * seed + c) % m;
//   return seed;
// }

// function nextRandFloat() {
//   return nextRand() / m;
// }


var canvas = document.getElementById("canvas"),
    context = canvas.getContext("2d");

var y = 0;
function draw() {
  console.log("draw")
  for(var x = 0; x < 550; x++) {
    if(nextRandFloat() < 0.5) {
      context.fillRect(x, y, 1, 1);
    }
  }
  y++;
  if(y < 600) {
    requestAnimationFrame(draw);
  }
}








