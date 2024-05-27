const forwardButton = document.querySelector('.arrow-btn.arrow-up'); // Selecteer de forward knop
const rightButton = document.querySelector('.arrow-btn.arrow-right'); // Selecteer de right knop

forwardButton.addEventListener('mousedown', () => {
    forwardButton.style.transform = 'translateY(2px)';
    forwardButton.style.boxShadow = '0px 2px 0px #888';

    // Maak het JSON-object met de gewenste gegevens
    const data = {
        task: 'forward' // Taak is 'forward'
    };

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
});

forwardButton.addEventListener('mouseup', () => {
    forwardButton.style.transform = '';
    forwardButton.style.boxShadow = '';
});

rightButton.addEventListener('mousedown', () => {
    rightButton.style.transform = 'translateY(2px)';
    rightButton.style.boxShadow = '0px 2px 0px #888';

    // Maak het JSON-object met de gewenste gegevens
    const data = {
        task: 'rightward' // Taak is 'rightward'
    };

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
});

rightButton.addEventListener('mouseup', () => {
    rightButton.style.transform = '';
    rightButton.style.boxShadow = '';
});