#!/bin/bash

# Start Apache in the background
apache2ctl -D FOREGROUND &

# Start the PHP script
php /var/www/html/websocket.php

# Wait for any process to exit
wait -n

# Exit with status of the process that exited first
exit $?
