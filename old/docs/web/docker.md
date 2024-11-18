# Docker environment
## Dockerfile
For setting up our Docker environment, we have used a Dockerfile. The Dockerfile defines a Docker image for a web server based on Ubuntu. It starts with specifying the base image as Ubuntu using FROM ubuntu. The environment variable TZ is then set to "Europe/Amsterdam" to specify the time zone.

Next, the RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone command configures the time zone for the container. The subsequent RUN apt update && apt install -y apache2 apache2-utils libapache2-mod-php php-cli php-sockets && apt clean command updates the package lists and installs Apache, PHP, and necessary PHP modules, and then cleans up to reduce the image size.

The COPY ../web/ /var/www/html/ command copies the contents from the local ../web/ directory to the container's /var/www/html/ directory, which is the default directory for web content in Apache. Similarly, COPY startup.sh /usr/local/bin/start.sh copies a script named startup.sh from the local environment to the container's /usr/local/bin/start.sh.

To set the correct permissions, the RUN chown -R www-data:www-data /var/www/html && chmod -R 775 /var/www/html && chmod +x /usr/local/bin/start.sh command changes the ownership of the /var/www/html directory to www-data (the user Apache runs as) and adjusts the permissions to ensure the web server can access these files. It also makes the startup script executable.

Ports 80 and 8080 are exposed using EXPOSE 80 and EXPOSE 8080, indicating that the container will listen for HTTP traffic on these ports. Finally, the CMD ["/usr/local/bin/start.sh"] command sets the default command to run when the container starts, which is the start.sh script located in /usr/local/bin

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/4c150f1f813871ddadbe0176c947d78157aba7e8/dockerfile">Click here</a>,
to see the dockerfile.
</div>

## start.sh
The start.sh sets up and runs necessary services for the Docker container. It is designed to ensure that the Apache web server starts and that the websocket.php script runs, enabling robots to connect to the WebSocket.

The command apache2ctl -D FOREGROUND & starts the Apache web server in the foreground mode but runs it as a background process (&). Running Apache in the foreground is necessary for proper signal handling in a containerized environment.

The next command, php /var/www/html/websocket.php, starts the websocket.php PHP script, which is crucial for enabling WebSocket connections that robots will use to interact with the server.

The wait -n command waits for any of the background processes (in this case, Apache or the PHP script) to exit. This ensures that the script doesn't terminate immediately and allows the container to keep running as long as either process is active.

Finally, exit $? exits the script with the status of the process that exited first, ensuring that the container reflects the correct status based on which process terminated.

This setup ensures that both Apache and the websocket.php script run concurrently, providing the necessary environment for robots to connect via WebSocket.

<div style="background-color: #f2f2f2; padding: 10px; border-left: 6px solid #4d90fe;"> 
Info<br>
<a href="https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80/-/blob/4c150f1f813871ddadbe0176c947d78157aba7e8/startup.sh">Click here</a>,
to see the start.sh.
</div>