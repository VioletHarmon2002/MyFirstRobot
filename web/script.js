document.addEventListener("DOMContentLoaded", function() {
    fetch('http://145.28.188.103/api.php?action=connections')  // Verander de URL indien nodig
        .then(response => response.json())
        .then(data => {
            const list = document.getElementById('connection-list');
            list.innerHTML = '';  // Leeg de lijst

            if (data.error) {
                const li = document.createElement('li');
                li.textContent = `Error: ${data.error}`;
                list.appendChild(li);
            } else if (data.length === 0) {
                const li = document.createElement('li');
                li.textContent = 'Geen actieve verbindingen.';
                list.appendChild(li);
            } else {
                data.forEach(connection => {
                    const li = document.createElement('li');
                    li.textContent = `Client: ${connection.address}:${connection.port}`;
                    list.appendChild(li);
                });
            }
        })
        .catch(error => {
            const list = document.getElementById('connection-list');
            list.innerHTML = '';  // Leeg de lijst
            const li = document.createElement('li');
            li.textContent = `Fout bij het ophalen van gegevens: ${error}`;
            list.appendChild(li);
        });
});

