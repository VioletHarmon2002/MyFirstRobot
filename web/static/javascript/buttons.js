const arrowButtons = document.querySelectorAll('.arrow-btn');

arrowButtons.forEach(button => {
    button.addEventListener('mousedown', () => {
        button.style.transform = 'translateY(2px)';
        button.style.boxShadow = '0px 2px 0px #888';
    });

    button.addEventListener('mouseup', () => {
        button.style.transform = '';
        button.style.boxShadow = '';
    });
});

