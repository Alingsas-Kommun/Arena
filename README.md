# Arena
Arena Skolportal

This is a version in beta.

##Installation

1. Setup your Apache/MySQL/PHP Stack and install additionally Drush as
	 commandline-tool (drush.org).
2. Clone the repository and use the standard Drupal installation method. See
	 drupal.org for more detailed information about this process. (Basically it's
	 setting up your server-host and running http://host-address/install.php)
3. Import the database to activate the modules and import some standard content
	 with $> drush sql-cli ../datadump/arena.sql

The database import adds some standard roles, users and content.

##Logins:
Administrator         admin/skolportalen

Schooladministrator:  skoladministrator/skoladministrator

Teacher:              lärare/lärare

Student 1:            student1/student1

Student 2:            student2/student2
