let names_array = ["gert", "geralda", "gerard", "gabbert"];
let current_name = "hoi";
let names_element_array = document.getElementsByClassName('robot-list-item');
const LIST_ITEM_BACKGROUND_COLOR = "rgb(205, 205, 205)";
const list_container = document.querySelector(".robot-list-container");
function addRobotNames(){
    for(var i = 0; i < names_array.length; i++) {
        let list_item = document.createElement('li');
        list_item.innerHTML = names_array[i];
        list_item.className = 'robot-list-item';
        list_container.appendChild(list_item);
        list_item.addEventListener("click", function(){
            resetList();
            setRobotNameActive(list_item);
            current_name = list_item.innerHTML;
            console.log(current_name);
        });
    }
}
function resetList(){
    let names_element_array = document.getElementsByClassName('robot-list-item');
    for(var i = 0; i < names_element_array.length; i++) {
        var element = names_element_array[i];
        element.style.backgroundColor = LIST_ITEM_BACKGROUND_COLOR;
    }
}

function setRobotNameActive(element){
    console.log(element);
    element.style.backgroundColor = "rgba(255,255,255)"
}

addRobotNames()