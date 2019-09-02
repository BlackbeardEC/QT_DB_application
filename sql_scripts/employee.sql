DROP TABLE `employee`;

CREATE TABLE `employee` (
  `id` mediumint(8) unsigned NOT NULL auto_increment,
  `name` varchar(255) default NULL,
  `address` varchar(255) default NULL,
  `phone_number` varchar(100) default NULL,
  `email` varchar(255) default NULL,
  PRIMARY KEY (`id`)
) AUTO_INCREMENT=1;

INSERT INTO `employee` (`id`,`name`,`address`,`phone_number`,`email`) VALUES (1,"Hamilton Nolan","466-4297 Ridiculus St.","1-769-180-4617","vitae.odio.sagittis@nec.edu"),(2,"Abbot Finley","608-4855 Auctor. Ave","1-572-966-0913","diam.nunc.ullamcorper@consequatlectus.edu"),(3,"Elmo Rose","288-5802 Tincidunt. Avenue","1-699-295-8963","auctor.vitae@elementum.edu"),(4,"Octavia Scott","6350 Augue Rd.","1-164-314-6863","eu.lacus@magna.com"),(5,"Tarik Hernandez","P.O. Box 713, 2953 Torquent St.","1-811-309-0558","Sed.id.risus@Aliquamnecenim.co.uk");
