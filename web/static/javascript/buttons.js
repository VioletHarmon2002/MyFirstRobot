const forwardButton = document.querySelector('.arrow-btn.arrow-up');
const leftward = document.querySelector('.arrow-btn.arrow-left'); 

forwardButton.addEventListener('mousedown', () => {
    forwardButton.style.transform = 'translateY(2px)';
    forwardButton.style.boxShadow = '0px 2px 0px #888';

    const data = {
        task: 'forward' 
    };

    // Verstuur het JSON-bericht naar de API
    fetch('http://Hier_eigen_IP/api.php?action=task', {
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
});

forwardButton.addEventListener('mouseup', () => {
    forwardButton.style.transform = '';
    forwardButton.style.boxShadow = '';
});

// -------------------------------------

leftward.addEventListener('mousedown', () => {
    forwardButton.style.transform = 'translateY(2px)';
    forwardButton.style.boxShadow = '0px 2px 0px #888';

    const data = {
        task: 'leftward' 
    };

    // Verstuur het JSON-bericht naar de API
    fetch('http://Hier_eigen_IP/api.php?action=task', {
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
});

leftward.addEventListener('mouseup', () => {
    forwardButton.style.transform = '';
    forwardButton.style.boxShadow = '';
});