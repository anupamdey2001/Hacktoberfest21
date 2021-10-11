// Getting all the cards to perform actions on it.
const cards = document.querySelectorAll(".card");
// Flipping each cards on click event.
cards.forEach((card) => card.addEventListener("click", flip));

// Getting score class for DOM Manipulation or score update.
const score = document.getElementsByClassName("score");

// Variables used:
var isFlipped = false;
var firstCard = null;
var secondCard = null;
var counter = 0;

function flip() {
  // First flipping the card.
  this.classList.add("flip");

  // Then checking for the second card if they are same or not.
  if (!isFlipped) {
    isFlipped = true;
    firstCard = this; //IMPORTANT STEP
  } else {
    secondCard = this;
    checkIt();
  }
}

function checkIt() {
  if (firstCard.dataset.image === secondCard.dataset.image) {
    counter++;
    score[0].innerHTML = "Score : " + counter;
    success();
  } else {
    counter--;
    score[0].innerHTML = "Score : " + counter;
    fail();
  }
}

function success() {
  // If there is success then we will not re-f;ip that card.
  firstCard.removeEventListener("click", flip);
  secondCard.removeEventListener("click", flip);

  // Finally resetting the values for the rest cards
  reset();
}

function fail() {
  setTimeout(() => {
    firstCard.classList.remove("flip");
    secondCard.classList.remove("flip");
    reset();
  }, 1000);
}

function reset() {
  isFlipped = false;
  firstCard = null;
  secondCard = null;
}

(function shuffle() {
  cards.forEach((card) => {
    // Getting random index and then shuffling them as per indices.
    var index = Math.floor(Math.random() * 16);
    // Changing the order using the style.order property of flex-box.
    card.style.order = index;
  });
})();