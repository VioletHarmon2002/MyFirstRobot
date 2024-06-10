const forwardButton = document.querySelector('.arrow-btn.arrow-up');
const leftwardButton = document.querySelector('.arrow-btn.arrow-left'); 
const rightwardButton = document.querySelector('.arrow-btn.arrow-right'); 

forwardButton.addEventListener('mousedown', () => {
    forwardButton.style.transform = 'translateY(2px)';
    forwardButton.style.boxShadow = '0px 2px 0px #888';

    const data = {
        task: 'forward',
        value: 1
    };

    // Verstuur het JSON-bericht naar de API
    fetch('http://145.3.245.224/api.php?action=task', {
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

leftwardButton.addEventListener('mousedown', () => {
    leftwardButton.style.transform = 'translateY(2px)';
    leftwardButton.style.boxShadow = '0px 2px 0px #888';

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
    leftwardButton.style.transform = '';
    leftwardButton.style.boxShadow = '';
});

// ---------------------------------

rightwardButton.addEventListener('mousedown', () => {
    rightwardButton.style.transform = 'translateY(2px)';
    rightwardButton.style.boxShadow = '0px 2px 0px #888';

    const data = {
        task: 'rightward' 
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
    rightwardButton.style.transform = '';
    rightwardButton.style.boxShadow = '';
});