# Technical Documentation

## Setup webserver

To set up the web server, you need to clone [this](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/group-project/faaxeeheeqee80)
 GitLab project. After that, you should open the project in a CLI. In the CLI, the following command needs to be executed:

```txt
docker build --tag little-endian .
```

This command builds a Docker image tagged "little-endian" using the files in the current directory. Then, the following command needs to be executed:

```txt
docker run --publish 80:80 --publish 8080:8080 --detach little-endian
```

This command starts a Docker container with the "little-endian" image, where port 80 of the host is linked to port 80 in the container, and port 8080 of the host is linked to port 8080 in the container.

After this, the web server is successfully set up. However, there are still a few places where the IP address of the host needs to be specified for proper communication.

Firstly, the send_command.php file in the /var/www/html folder needs to be edited. On line 4 of this file, the IP address of the host must be specified.

![web_technical](images/send_command.png)

Additionally, in the folder /var/www/html/static/javascript, in the file buttons.js, the IP address of the host needs to be provided on lines 14, 51, and 88. With these steps completed, the web server is fully set up and operational.

## Communication

The communication consists of multiple components. Below, it is schematically depicted: 

![web_technical](images/scheme.png)

Firstly, the robot must be connected to the WebSocket. This is automatically done when the robot is turned on. Once this is established, a button on the HTML page can be pressed. When this button is clicked, a JavaScript file named "buttons.js" is invoked. This script facilitates sending a POST request to the API with the specified task given by clicking the button.

This POST request is received by the API. The API checks the task and calls the "send_command.php" file to transmit the task to the robot via the "websocket.php" file.

## Structure

### Front-end
The front-end consists of the 'index.html' file, a 'templates' folder, and a 'static' folder. In the 'templates' folder, you will find the various HTML pages used for the website. Inside the 'static' folder, there are three subfolders: 'css', 'images', and 'javascript'. The 'css' folder contains the 'style.css' file, which is responsible for the styling of the HTML files. The 'images' folder contains the 'logo.png' image, used for displaying the HvA logo. Lastly, the 'javascript' folder contains six JavaScript files: 'buttons.js' for communication with the API, 'blocky.js', 'connect.js', 'draggin.js', 'script.js', and 'websocket.js'.

Structuring the front-end in this manner ensures efficient organization and enhances development. By segregating files into dedicated folders such as 'css', 'images', and 'javascript', it promotes clarity and ease of access. This approach allows for seamless scalability, making it straightforward to add or modify resources as needed without cluttering the root directory. Additionally, this structure optimizes performance by facilitating efficient browser caching of static assets, resulting in faster loading times for users. Overall, this directory arrangement fosters maintainability, scalability, and efficiency in front-end development.

### Back-end
The back-end consists of three files: 'websocket.php', 'send_command.php', and 'api.php'. The 'websocket.php' file handles incoming connections from the robots and manages communication between the robot and the API. The 'api.php' file processes POST requests from the front-end, after which the 'send_command.php' file is used to send the command to the robot via the websocket.


