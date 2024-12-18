document.addEventListener("DOMContentLoaded", function () {
    fetch('NavBar.html')
        .then(response => response.text())
        .then(data => {
            document.getElementById('navbar').innerHTML = data;

            // After loading the navbar, set the active link
            const currentPage = window.location.pathname.split("/").pop();

            // Map pages to their corresponding link IDs
            const pageToLinkMap = {
                "arrows.html": "robot-controls-link",
                "blocky.html": "block-editor-link",
                "connect.html": "connect-robot-link",
            };

            // Get the corresponding link ID
            const activeLinkId = pageToLinkMap[currentPage];

            // If the link ID exists, add the 'active' class to the corresponding link
            if (activeLinkId) {
                const activeLink = document.getElementById(activeLinkId);
                if (activeLink) {
                    activeLink.classList.add("active");
                }
            }
        })
        .catch(error => console.error('Error loading navbar:', error));
});

document.addEventListener("DOMContentLoaded", function () {
    fetch('footer.html')
        .then(response => response.text())
        .then(data => {
            document.getElementById('footer').innerHTML = data;
        })
        .catch(error => console.error('Error loading footer:', error));
});