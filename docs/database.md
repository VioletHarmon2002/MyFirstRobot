### For Developers
MariaDB and phpMyAdmin have been set up in Docker containers using Docker Compose to manage the database for the robot project. The database, my_first_robot, includes a table called robot_data that stores information about the robot, such as its ID, uuid, name, and uptime.

Sensitive credentials are stored in a .env file for security and excluded from version control using .gitignore.

**Steps**
1. A .env file was created to securely store sensitive credentials:

``
MYSQL_ROOT_PASSWORD=  
MYSQL_DATABASE=my_first_robot  
MYSQL_USER=   
MYSQL_PASSWORD=    
PMA_PORT=8080
``

2. Docker Compose Configuration

    - A docker-compose.yml file was created to run MariaDB and phpMyAdmin.
    - The docker-compose.yml uses the values from the .env file for configuration:

````
version: '3.1'

services:
  mariadb:
    image: mariadb:latest
    container_name: mariadb_container
    restart: always
    environment:
      MYSQL_ROOT_PASSWORD: ${MYSQL_ROOT_PASSWORD}
      MYSQL_DATABASE: ${MYSQL_DATABASE}
      MYSQL_USER: ${MYSQL_USER}
      MYSQL_PASSWORD: ${MYSQL_PASSWORD}
    ports:
      - "3306:3306"

  phpmyadmin:
    image: phpmyadmin:latest
    container_name: phpmyadmin_container
    restart: always
    environment:
      PMA_HOST: mariadb
      MYSQL_ROOT_PASSWORD: ${MYSQL_ROOT_PASSWORD}
    ports:
      - "${PMA_PORT}:80"
````

3. Starting the containers:

``
docker-compose up -d
``

MariaDB is accessible on port 3306, and phpMyAdmin is available at http://localhost:8081.

4. Database Creation
In phpMyAdmin, a table was added with the following structure:

| Column Name | Type         | Attributes                     |
|-------------|--------------|---------------------------------|
| id          | INT          | Primary Key, Auto-Increment    |
| uuid        | VARCHAR(36)  | Unique                         |
| name        | VARCHAR(50)  | Not Null                       |
| uptime      | FLOAT        | Tracks uptime in hours         |
