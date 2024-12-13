CREATE TABLE `robots` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,       
  `uuid` CHAR(36) NOT NULL,                   
  `name` VARCHAR(255) NOT NULL,              
  `uptime` FLOAT NOT NULL CHECK (`uptime` >= 0),
  PRIMARY KEY (`id`),                         
  UNIQUE (`uuid`)                             
);