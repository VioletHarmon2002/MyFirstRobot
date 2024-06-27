let connected = true;
let connected_to = "Kees";
let connection_speed = 10;
const connected_to_name_element = document.getElementById('connected-to?-name');
const connected_element = document.getElementById('connected-to?');

const connected_speed_value_element = document.getElementById('connected-speed?-value');
const connected_speed = document.getElementById('connected-speed?');

const not_connected_element = document.getElementById('not-connected');

document.getElementById('toggleDrawer').addEventListener('click', function() {
    const drawer = document.getElementById('drawer');
    drawer.classList.toggle('open');

    const drawerToggle = document.getElementById('toggleDrawer');
    drawerToggle.classList.toggle('open');
});

setInterval(updatePage(), 1000);
function updatePage(){
    if(connected){
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

function sendCommand(jsonData){
    // Verstuur het JSON-bericht naar de API
    fetch('http://172.16.34.136/api.php?action=task', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(jsonData)
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
}