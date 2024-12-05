### Learning Story [#119]: Making Database Changes Visible to Team Members

How can I set up and share a database online so my team can use it securely without any issues?

1. Verify Permissions
Ensure that all team members have the correct database permissions.

    1. Log in to the database as an admin.
    2. Check user privileges for the database in phpMyAdmin:  
    ``
    SHOW GRANTS FOR 'username'@'host';
    ``
    3. Ensure they have at least SELECT and INSERT privileges for the new tables.  
    ``
    GRANT SELECT, INSERT ON database_name.* TO 'username'@'host';
    FLUSH PRIVILEGES;
    `` 

2. Ensure Database is Properly Shared  
Check the docker-compose.yml file to confirm:

    - The database service is correctly configured with shared volumes to persist changes.  
    - Example configuration for shared volume:  

    ``
    services:  
    db:  
        image: mariadb  
        environment:  
        MYSQL_DATABASE: my_first_robot  
        volumes:  
        - ./db_data:/var/lib/mysql
    ``

    - The db_data directory ensures all changes, including new tables, are saved and shared.

### Learning Story [#120]: Implementing a MariaDB Database with Docker Compose

How can I create and configure a MariaDB database using Docker Compose to ensure it is easily deployed and accessible for all team members?

1. Setting Up the Docker Compose File: We have configured a Docker Compose file that defines a MariaDB container along with necessary environment variables. This setup allows anyone in the team to easily spin up a consistent MariaDB database environment.

    docker-compose.yml:
    ``
    version: '3.1'

    services:
    db:
        image: mariadb:latest
        container_name: mariadb_container
        environment:
        MYSQL_ROOT_PASSWORD: ${MYSQL_ROOT_PASSWORD}
        MYSQL_DATABASE: ${MYSQL_DATABASE}
        MYSQL_USER: ${MYSQL_USER}
        MYSQL_PASSWORD: ${MYSQL_PASSWORD}
        ports:
        - "3306:3306"
        volumes:
        - mariadb_data:/var/lib/mysql

    volumes:
    mariadb_data:
    ``

    **Explanation:**

    - image: mariadb:latest: This uses the latest official MariaDB image.    
    - container_name: mariadb_container: The container will be named mariadb_container.  
    - environment: Here we define important environment variables like the root password, database name, and user credentials. These credentials are stored in a .env file to keep sensitive information safe.  
    - ports: "3306:3306": This exposes the database on the host machine's port 3306.  
    - volumes: mariadb_data:/var/lib/mysql: This ensures that the database data is persisted across container restarts.

2. Configuring .env file  
    The .env file contains the sensitive environment variables used in the Docker Compose file. It keeps the credentials and database name secure.

    ````
    MYSQL_ROOT_PASSWORD=  
    MYSQL_DATABASE=  
    MYSQL_USER=  
    MYSQL_PASSWORD=  
    ````

3. After setting up the Docker Compose file and .env file, start the MariaDB container:

    ``
    docker-compose up -d
    ``

    This command will pull the MariaDB image and start the database container in the background.

4. Access PhpMyAdmin:  
PhpMyAdmin can be accessed through the web browser at http://localhost:8081. Use the MYSQL_USER and PMA_PASSWORD from the .env file to log in.