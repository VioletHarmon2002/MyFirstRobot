let connected = true;
let connected_to = "Kees";
let connection_speed = 10;
const IP_ADRESS = '127.0.0.1';


const connected_to_name_element = document.getElementById('connected-to?-name');
const connected_element = document.getElementById('connected-to?');

const connected_speed_value_element = document.getElementById('connected-speed?-value');
const connected_speed = document.getElementById('connected-speed?');

const not_connected_element = document.getElementById('not-connected');

// Utility to get query parameter by name
function getQueryParam(param) {
    const urlParams = new URLSearchParams(window.location.search);
    return urlParams.get(param);
}

// Save ID from URL to localStorage
function saveRobotId() {
    const robotId = getQueryParam('id');
    if (robotId) {
        localStorage.setItem('robotId', robotId);
        console.log(`Robot ID saved to localStorage: ${robotId}`);
    } else {
        console.log('No robot ID found in URL.');
    }
}

// Get the saved robot ID from localStorage
function getSavedRobotId() {
    return localStorage.getItem('robotId');
}

// Initialize robot ID saving on page load
document.addEventListener('DOMContentLoaded', () => {
    saveRobotId();

    // Optionally log the saved ID for debugging
    const savedId = getSavedRobotId();
    if (savedId) {
        console.log(`Robot ID retrieved from localStorage: ${savedId}`);
    }
});

// Toggle the drawer open/closed
document.getElementById('toggleDrawer').addEventListener('click', function () {
    const drawer = document.getElementById('drawer');
    drawer.classList.toggle('open');

    const drawerToggle = document.getElementById('toggleDrawer');
    drawerToggle.classList.toggle('open');
});

// Periodically update the page
setInterval(updatePage, 1000);

function updatePage() {
    if (connected) {
        not_connected_element.style.display = 'none';
        connected_element.style.display = 'block';
        connected_speed.style.display = 'block';

        connected_to_name_element.innerHTML = connected_to;
        connected_speed_value_element.innerHTML = connection_speed;
    } else {
        not_connected_element.style.display = 'block';
        connected_element.style.display = 'none';
        connected_speed.style.display = 'none';
    }
}

// Send JSON data to the API
function sendCommand(jsonData) {
    fetch(`http://${IP_ADRESS}/api.php?action=task`, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(jsonData),
    })
        .then((response) => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then((data) => {
            console.log('API response:', data);
            // Handle API response if needed
        })
        .catch((error) => {
            console.error('There was a problem with the fetch operation:', error);
        });
}
