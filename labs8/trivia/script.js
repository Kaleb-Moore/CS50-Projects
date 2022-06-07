const first = document.getElementById('first-answer');
const second = document.getElementById('second-answer');
const correct = document.getElementById('correct-answer');

const rightAnswer = document.getElementById("correct");
const wrongAnswer = document.getElementById('incorrect');

const form = document.querySelector('form');


const answerCorrect = document.getElementById('correct-2');
const answerWrong = document.getElementById('incorrect-2');

first.addEventListener('click', e => {
    first.style.backgroundColor = "red";
    second.removeAttribute('style');
    correct.removeAttribute('style');
    rightAnswer.setAttribute('hidden', true);
    wrongAnswer.removeAttribute('hidden');
});

second.addEventListener('click', e => {
    second.style.backgroundColor = "red";
    first.removeAttribute('style');
    correct.removeAttribute('style');
    rightAnswer.setAttribute('hidden', true);
    wrongAnswer.removeAttribute('hidden');
});

correct.addEventListener('click', e => {
    correct.style.backgroundColor = "green";
    first.removeAttribute('style');
    second.removeAttribute('style');
    rightAnswer.removeAttribute('hidden');
    wrongAnswer.setAttribute('hidden', true);
});

form.addEventListener('submit', e => {
    e.preventDefault();
    let answerField = document.getElementById('answer-field');
    if(answerField.value.toLowerCase() == 'scotland'){
        answerCorrect.removeAttribute('hidden');
        answerWrong.setAttribute('hidden', true);
        answerField.style.backgroundColor = 'green';
    }
    else {
        answerCorrect.setAttribute('hidden', true);
        answerWrong.removeAttribute('hidden');
        answerField.style.background = 'red';
    }
});