const namesArray = ["Gert", "Geralda", "Gerard", "Gabbert", "Geronk", "Giovanni", "Gnar", "Gnappie"];
const listContainer = document.querySelector(".robot-list-container");
const inputNameElement = document.querySelector(".robot-name-input");

function addRobotNames() {
    listContainer.innerHTML = ""; // Clear list before adding names
    namesArray.forEach(name => {
        const listItem = document.createElement('li');
        listItem.textContent = name;
        listItem.className = 'robot-list-item';
        listContainer.appendChild(listItem);
        listItem.addEventListener("click", () => {
            resetList();
            setRobotNameActive(listItem);
        });
    });
}

function resetList() {
    document.querySelectorAll('.robot-list-item').forEach(item => {
        item.style.backgroundColor = "#ecf0f1";
    });
}

function setRobotNameActive(element) {
    element.style.backgroundColor = "#3498db";
    element.style.color = "white";
    inputNameElement.value = element.textContent;
}

function connect() {
    const robotName = inputNameElement.value.trim();
    if (robotName) {
        alert(`Connecting to ${robotName}`);
        document.getElementById("connected-to-name").textContent = robotName;
    } else {
        alert("Please enter a robot name.");
    }
}

addRobotNames();
