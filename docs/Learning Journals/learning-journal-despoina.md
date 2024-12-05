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

### User Story [#129]: Sharing database tables and data via docker-compose.yml
In order to address some of the issues I encountered during the development process, I decided to implement a solution that would ensure persistence of data in MariaDB when using Docker. Initially, I faced challenges with maintaining the database content across container restarts, as well as managing large commits due to changes in the MariaDB data files. Through researching for my learning story, I found an effective solution using Docker volumes and initialization scripts.