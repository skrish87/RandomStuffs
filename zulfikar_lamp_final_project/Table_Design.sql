create table Posts(Posts_ID INTEGER NOT NULL AUTO_INCREMENT, PRIMARY KEY(Posts_ID), Title VARCHAR(25), Price DECIMAL(8,2), 
	Description VARCHAR(50), Email VARCHAR(25), Agreement VARCHAR(10), Timestamp TIMESTAMP, Image_1 varchar(50) 
	SubCategory_ID INTEGER, Location_ID INTEGER, Region_ID int(4));

create table Region(RegionID int(4) not null auto_increment, primary key(RegionID), RegionName varchar(25));
create table Category(CategoryID int(4) not null auto_increment, primary key(RegionID), CategoryName varchar(25));
create table Location(LocatioID, int(4) not null auto_increment, primary key(LocatioID), LocationName varchar(25));
create table users(username varchar(25) not null, primary key(username), password varchar(25));

alter table Posts add foreign key(SubCategory_ID) references Category(CategoryID);
alter table Posts add foreign key(Location_ID) references Location(LocationID);
alter table Posts add foreign key(Region_ID) references Region(RegionID);


insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Honda', '123.45', 'Honda bike sale', 'abc@test.com', '/Applications/lamp_final_project/images/honda.jpg', '2','1','1')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Bike', '123.45', 'Hybrid bike', 'hello@test.com', '/Applications/lamp_final_project/images/bike2.jpg', '1','2','2')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Commuting car', '123.45', 'Car is in decent condition', 'def@test.com', '/Applications/lamp_final_project/images/car1-thumb.jpg', '3','3','3')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Honda Bike', '123.45', 'Sports model in sexy yellow', 'abc@test.com', '/Applications/lamp_final_project/images/honda.jpg', '2','2','2')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Car sale', '123.45', 'Amazing car offer', 'def@test.com', '/Applications/lamp_final_project/images/car1-thumb.jpg', '3','4','3')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Motor cycle sale', '123.45', 'Amazing car offer', 'hello@test.com', '/Applications/lamp_final_project/images/car1-thumb.jpg', '2','1','1')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Race Bike', '123.45', 'Amazing car offer', 'abc@test.com', '/Applications/lamp_final_project/images/car1-thumb.jpg', '2','2','3')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Mountain Bike', '123.45', 'Amazing car offer', 'hello@gmail.com', '/Applications/lamp_final_project/images/bike2.jpg', '1','3','1')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Car sale', '123.45', 'Amazing car offer', 'hello@gmail.com', '/Applications/lamp_final_project/images/car1-thumb.jpg', '3','3','2')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Car', '123.45', 'Amazing car offer', 'abc@test.com', '/Applications/lamp_final_project/images/car1-thumb.jpg', '3','4','2')

insert into Posts(Posts_ID, Title, Price, Description, Email, Image_1, SubCategory_ID, Location_ID, Region_ID) 
	values('', 'Amazing car', '123.45', 'Amazing car offer', 'def@test.com', '/Applications/lamp_final_project/images/tesla.jpg', '3','4','2')



insert into Region(RegionID, RegionName) values('1', 'South Bay');
insert into Region(RegionID, RegionName) values('2', 'North Bay');
insert into Region(RegionID, RegionName) values('3', 'East Bay');

insert into Location(LocationID, LocationName) values('1', 'Sunnyvale');
insert into Location(LocationID, LocationName) values('2', 'San Francisco');
insert into Location(LocationID, LocationName) values('3', 'Santa Clara');
insert into Location(LocationID, LocationName) values('4', 'Oakland');

insert into Category(CategoryID, CategoryName) values('1', 'Bike');
insert into Category(CategoryID, CategoryName) values('2', 'Motor Cycle');
insert into Category(CategoryID, CategoryName) values('3', 'Car');

insert into users(username, password) values('abc@test.com', 'test')
insert into users(username, password) values('hello@gmail.com', '1234')