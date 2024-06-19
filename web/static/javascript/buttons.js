const forwardButton = document.querySelector('.arrow-btn.arrow-up');
const rightwardButton = document.querySelector('.arrow-btn.arrow-right'); 
const leftwardButton = document.querySelector('.arrow-btn.arrow-left'); 

const handleButtonPress = (button, task) => {
    button.style.transform = 'translateY(2px)';
    button.style.boxShadow = '0px 2px 0px #888';

    const data = { task };

    // Verstuur het JSON-bericht naar de API
    fetch('http://172.16.34.136/api.php?action=task', {
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
        // Doe hier iets met de API-reactie als dat nodig is
    })
    .catch(error => {
        console.error('There was a problem with the fetch operation:', error);
    });
};

forwardButton.addEventListener('mousedown', () => handleButtonPress(forwardButton, 'forward'));
rightwardButton.addEventListener('mousedown', () => handleButtonPress(rightwardButton, 'rightward'));
leftwardButton.addEventListener('mousedown', () => handleButtonPress(leftwardButton, 'leftward'));
