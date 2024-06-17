let connected = false;
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

setInterval(updatePage, 1000);
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

function sendCommand(command, value){
    const data = {
      "task": command,
      "value": value
    };
    console.log("sendCommand: " + JSON.stringify(data));
  
    // Send the JSON message to the API
    fetch('http://145.28.162.219/api.php?action=task', {
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

function setActiveName(name){
    console.log('Setting active name')
    connected_to = name;
    connected = true;
}