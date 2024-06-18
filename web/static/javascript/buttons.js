const forwardButton = document.querySelector('.arrow-btn.arrow-up');
const rightwardButton = document.querySelector('.arrow-btn.arrow-right');
const leftwardButton = document.querySelector('.arrow-btn.arrow-left');

const sendCommand = (button, task) => {
    // Visual feedback when button is pressed
    if (button) {
        button.style.transform = 'translateY(2px)';
        button.style.boxShadow = '0px 2px 0px #888';
    }

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
        // Reset visual feedback when command is successfully sent
        if (button) {
            button.style.transform = '';
            button.style.boxShadow = '';
        }
    })
    .catch(error => {
        console.error('There was a problem with the fetch operation:', error);
        // Reset visual feedback on error
        if (button) {
            button.style.transform = '';
            button.style.boxShadow = '';
        }
    });
};

// Add event listeners for mouse down events
forwardButton.addEventListener('mousedown', () => sendCommand(forwardButton, 'forward'));
rightwardButton.addEventListener('mousedown', () => sendCommand(rightwardButton, 'rightward'));
leftwardButton.addEventListener('mousedown', () => sendCommand(leftwardButton, 'leftward'));

// Add event listeners for mouse up events (assuming you want to send a blank command on release)
forwardButton.addEventListener('mouseup', () => sendCommand());
rightwardButton.addEventListener('mouseup', () => sendCommand());
leftwardButton.addEventListener('mouseup', () => sendCommand());
