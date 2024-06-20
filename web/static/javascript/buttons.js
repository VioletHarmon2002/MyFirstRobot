const sendCommand = (command) => {
    const data = { command };

    fetch('http://172.20.10.2/api.php?action=command', {
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
