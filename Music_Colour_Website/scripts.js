const red = document.querySelector(".red");
const cyan = document.querySelector(".cyan");
const violet = document.querySelector(".violet");
const orange = document.querySelector(".orange");
const pink = document.querySelector(".pink");
// Selecting the center element:
const center = document.querySelector(".center");

// Making an array of all the selected classes.
const colorArray = [red, cyan, violet, orange, pink];

// getting the background color of the given element.
const BGColor = (index) => {
  return window.getComputedStyle(colorArray[index]).backgroundColor;
};

// Changing the background color of the center element with mouse action and playing different music for each color.
for (let i = 0; i < colorArray.length; i++) {
  colorArray[i].addEventListener("mouseenter", () => {
    center.style.background = BGColor(i);
    musicPlayer(i);
  });
}


// Audio Playing:
//-------------------

const audio1 = new Audio("Audios/audio1.mp3");
const audio2 = new Audio("Audios/audio2.mp3");
const audio3 = new Audio("Audios/audio3.mp3");
const audio4 = new Audio("Audios/audio4.mp3");
const audio5 = new Audio("Audios/audio5.mp3");
// Making an array of all the audios.
const audioArray = [audio1, audio2, audio3, audio4, audio5];

// A function to play certain music as per the color selected
const musicPlayer = (i) => {
  if (i == 0) {
    audioArray[0].play();
    audioArray[1].pause();
    audioArray[2].pause();
    audioArray[3].pause();
    audioArray[4].pause();
  } else if (i == 1) {
    audioArray[1].play();
    audioArray[0].pause();
    audioArray[2].pause();
    audioArray[3].pause();
    audioArray[4].pause();
  } else if (i == 2) {
    audioArray[2].play();
    audioArray[0].pause();
    audioArray[1].pause();
    audioArray[3].pause();
    audioArray[4].pause();
  } else if (i == 3) {
    audioArray[3].play();
    audioArray[0].pause();
    audioArray[1].pause();
    audioArray[2].pause();
    audioArray[4].pause();
  } else if (i == 4) {
    audioArray[4].play();
    audioArray[0].pause();
    audioArray[1].pause();
    audioArray[2].pause();
    audioArray[3].pause();
  }
};