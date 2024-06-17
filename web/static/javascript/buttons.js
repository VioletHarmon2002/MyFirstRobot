const forwardButton = document.querySelector('.arrow-btn.arrow-up');
const rightwardButton = document.querySelector('.arrow-btn.arrow-right');
const leftwardButton = document.querySelector('.arrow-btn.arrow-left');

const sendCommand = (button, task) => {
    button.style.transform = 'translateY(2px)';
    button.style.boxShadow = '0px 2px 0px #888';

    const data = { task };

    fetch('http://145.3.249.252/api.php?action=task', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        return response.json();
    })
    .then(data => {
        console.log('API response:', data);
    })
    .catch(error => {
        console.error('There was a problem with the fetch operation:', error);
    });
};

forwardButton.addEventListener('mousedown', () => sendCommand(rightwardButton, 'forward'));
rightwardButton.addEventListener('mousedown', () => sendCommand(rightwardButton, 'rightward'));
leftwardButton.addEventListener('mousedown', () => sendCommand(leftwardButton, 'leftward'));

forwardButton.addEventListener('mouseup', () => sendCommand());
rightwardButton.addEventListener('mouseup', () => sendCommand());
leftwardButton.addEventListener('mouseup', () => sendCommand());