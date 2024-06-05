// THis file is for sending commands

function forward(n){
    sendCommand('forward');
}

function sendCommand(command){
    const data = {
        task: command 
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
}