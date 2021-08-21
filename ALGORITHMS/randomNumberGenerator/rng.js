let canvas = document.getElementById("prng")
let context = canvas.getContext("2d")

// PRNG 1 MIDDLE SQUARE
let digits = 12
let ms_seed = 123456789091
function ms_rand() {
  let str = (ms_seed*ms_seed).toString()
  while(str.length<digits*digits) {
    str+="0"
  }
  ms_seed = parseInt(
    str.substring(digits/2,3*(digits/2))
  )
  return ms_seed
}

function ms_nextRandFloat() {
  let div = ""
  for(let i=0;i<digits;i++) {
    div += "9"
  }
  return ms_rand()/parseInt(div)
}
let y = 0
draw()
function draw() {
  for(let x = 0; x < 600; x++) {
    if(ms_nextRandFloat() < 0.5) {
      context.fillRect(x, y, 1, 1);
    }
  }
  y++;
  if(y < 600) {
    requestAnimationFrame(draw);
  }
}
