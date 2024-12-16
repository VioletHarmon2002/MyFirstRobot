// Get the saved robot ID from localStorage
function getSavedRobotId() {
    return localStorage.getItem('robotId');
}

const sendCommand = (command) => {
    // Optionally log the saved ID for debugging
    const robotId = getSavedRobotId();
    if (robotId) {
        console.log(`Robot ID retrieved from localStorage: ${robotId}`);
    }

    // data object with the command key and the provided command value
    const data = { command, robotId };
    // Perform a fetch request to the specified URL with the action 'command'
    fetch('http://127.0.0.1/api.php?action=command', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        // Convert the data object to a JSON string and set it as the request body
        body: JSON.stringify(data)
    })
    // Check if the response status is not OK (status code outside the range 200-299)
    .then(response => {
        if (!response.ok) {
            // If the response is not OK, throw an error
            throw new Error('Network response was not ok');
        }
        // If the response is OK, parse the response body as JSON
        return response.json();
    })
    .then(data => {
        console.log('API response:', data);
    })
    .catch(error => {
        console.error('There was a problem with the fetch operation:', error);
    });
};
