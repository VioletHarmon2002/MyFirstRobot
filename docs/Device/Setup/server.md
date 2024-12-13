# Server setup

## Run server
To start the server it starts with building and running the docker docker-compose file. This is done by running this command:
```
docker-compose up --build -d
```
Breakdown:

- docker-compose
    - This is the Docker tool that defines and runs multi-container Docker applications using the docker-compose.yml file.

- up
    - This command creates and starts containers based on the configuration in the docker-compose.yml file. If the containers are already running, it stops and recreates them.

- --build
    - Forces Docker Compose to build the images before starting the containers. This is useful if you’ve made changes to the Dockerfile or any related files and want to ensure the container uses the latest image build.

- -d (detached mode)
    - Runs the containers in the background (detached mode). This means the containers will continue running, and you can use your terminal for other tasks.

Equivalent Steps:

- docker-compose build (to build images)
- docker-compose up -d (to start services in the background)

---

## Dockerfile
This Dockerfile creates a Docker image based on Ubuntu, sets up an Apache web server with PHP, and includes custom files for a web application. Apache is used to serve the website stored in the container's ```/var/www/html/``` directory.


**1. `FROM ubuntu`**

- **Base image:** Uses the official Ubuntu image as the starting point for building the custom Docker image.


**2. `ENV TZ=Europe/Amsterdam`**

- **Environment variable:** Sets the time zone to Europe/Amsterdam.


**3. `RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone`**

- **Time zone configuration:** 
  - Links the system's local time to the specified time zone.
  - Updates the `/etc/timezone` file with the correct time zone.


**4. `RUN apt update && apt install -y apache2 apache2-utils libapache2-mod-php php-cli php-sockets && apt clean`**

- **Install necessary software:** 
  - Updates the package list.
  - Installs Apache2, utilities, and PHP modules.
  - Cleans up the package cache to reduce image size.


**5. `COPY ../web/ /var/www/html/`**

- **Copy web files:** 
  - Copies the content from a local `../web/` directory into the container's Apache web server directory (`/var/www/html/`).


**6. `COPY startup.sh /usr/local/bin/start.sh`**

- **Copy a custom script:** 
  - Copies a `startup.sh` script into the container’s `/usr/local/bin/start.sh` directory, which might contain additional setup commands.


**7. `RUN chown -R www-data:www-data /var/www/html && chmod -R 775 /var/www/html && chmod +x /usr/local/bin/start.sh`**

- **Set file permissions:**
  - Changes ownership of `/var/www/html` to the Apache user (`www-data`).
  - Sets read, write, and execute permissions (`775`) for the web directory.
  - Makes the `start.sh` script executable.


**8. `EXPOSE 80` and `EXPOSE 8080`**

- **Port exposure:** 
  - Exposes ports 80 and 8080 so the container can accept HTTP traffic. 
  - Port 80 is the default HTTP port; 8080 is commonly used for alternative web services.


**9. `ENTRYPOINT ["apache2ctl", "-D", "FOREGROUND"]`**

- **Container entry point:** 
  - Specifies the command that runs when the container starts.
  - Launches Apache in the foreground mode to keep the container running.


## Overall Function
This Dockerfile sets up an Ubuntu-based container with an Apache web server to serve a PHP-based website. It includes custom web content and a startup script, ensuring the environment is correctly configured. Apache is the core service that runs and hosts the website, handling HTTP requests on the exposed ports.

---

## Websocket
Next up is starting the websocket. The websocket is started by running the ```websocket.php``` located at ```/var/www/html```.
The command for running the websocket:

```php /var/www/html/websocket.php```

This needs to be run within the exec of the docker container you created.

---

If you need to get into a shell within the docker of the raspberry pi use this command:

```docker exec -it pi-little-endian-1 /bin/bash```

This command allows you to access an interactive shell inside a running Docker container. Let's break down what each part does:

1. **`docker exec`**  
   Runs a command inside an existing (running) container. This is useful for performing maintenance, debugging, or inspecting the container's state.

2. **`-it`**  
   These are two combined options:
    1. **`-i`** (interactive mode): Keeps the standard input (stdin) open, allowing you to interact with the container.
    2. **`-t`** (pseudo-TTY): Allocates a terminal for the session, making it behave like a typical command-line interface.

3. **`pi-little-endian-1`**  
   This is the **name or container ID** of the Docker container you want to access. In this case, it's called `pi-little-endian-1`.

4. **`/bin/bash`**  
   Specifies the command to run inside the container. Here, it opens a **Bash shell** (`/bin/bash`), providing a command-line interface within the container.
