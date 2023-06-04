var slides = document.querySelectorAll("#slides > img");
var prev = document.getElementById("prev");
var next = document.getElementById("next");
var current = 0;
var sel_1 = document.getElementById("sel_1");
var sel_2 = document.getElementById("sel_2");
var sel_3 = document.getElementById("sel_3");
var sel_4 = document.getElementById("sel_4");
var sel_5 = document.getElementById("sel_5");

showSlides(current);
prev.onclick = prevSlide;
next.onclick = nextSlide;

var img = document.getElementById("slides");
function go(current)
{
  switch(current){
    case 0:
      img.style.transform="translateX(0px)";
      break;
    case 1:
      img.style.transform="translateX(-1200px)";
      break;

    case 2:
      img.style.transform="translateX(-2400px)";
      break;
    case 3:
      img.style.transform="translateX(-3600px)";
      break;
    case 4:img.style.transform="translateX(-4800px)";
  }
}
function showSlides(n) {
  for (let i = 0; i < slides.length; i++) {
    slides[i].style.display = "block";
  }
  slides[n].style.display = "block";
}

function prevSlide() {
  /*
  if (current > 0) current -= 1;
  else
    current = slides.length - 1;
    go(current);*/
  if(current ==0) current = slides.length -1;
  else current -=1;
  go(current);
}

function nextSlide() {
  /*if (current < slides.length - 1) current += 1;
  else
    current = 0;
    go(current);  
*/
  if(current == slides.length - 1) current = 0;
  else current+=1;
  go(current);  
}



const btn = document.getElementById('btn');         //버튼
let addValue = document.getElementById('addValue'); //할일 입력
let result = document.getElementById('result');    //추가된 할일
function newRegister() {
      let list = document.createElement("li");
      let del = document.createElement('button');
      list.innerHTML = addValue.value;
      result.appendChild(list); //추가된 할일에 할일 리스트 추가하기
      list.appendChild(del);    //할일 리스트 추가시 삭제버튼도 추가    
      del.innerHTML = "<img src = 'images/trash.png' width = 20>"      //삭제버튼에 이미지 삽입
      
      del.style.fontSize = "20px";
      del.style.backgroundColor = "white";
      del.style.border = "none";
      del.style.left = "500px";
      del.style.marginTop = "10px";
      del.style.cursor = "pointer";
      del.addEventListener("click", deleteList); //쓰레기통에 delte리스트 적용
      del.style.position='absolute';  
    }
function deleteList(e){ //쓰레기통 클릭시 
  this.parentNode.remove();
}

var ad = document.querySelector('.ad');
var box = document.querySelector('.box');
ad.onmouseover = function() {
          box.style.display="none";
          void box.offsetWidth;
          box.style.display="flex";
}
    