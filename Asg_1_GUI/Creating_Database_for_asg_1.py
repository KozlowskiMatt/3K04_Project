import mysql.connector


mysql_user = "" #Insert mysql password name here
mysql_passwd = " " #Insert mysql password name here 


### Steps to create new database and table when first running the code###

### Step 1, run this to create your database ###
'''
db = mysql.connector.connect(
    host="localhost",
    user= mysql_user,
    passwd= mysql_passwd,
)
mycursor = db.cursor(buffered=True)
mycursor.execute("CREATE DATABASE [insert_data_base_name]")
'''

### Step 2, Once database is created this portion will create the table with the desired columns ###
'''
db = mysql.connector.connect(
    host="localhost",
    user= mysql_user,
    passwd= mysql_passwd,
    database = " " #insert the databse name here
)

mycursor.execute("CREATE TABLE users (username VARCHAR(25), password VARCHAR(25),Lower_Rate_Limit int, Upper_Rate_Limit int, \
#Ventrical_Amplitude int, Ventrical_Pulse_Width int, Ventrical_Refractory_Period int, Attrial_Amplitude int, Attrial_Pulse_Width int,\
Attrial_Refractory_Period int, personID int PRIMARY KEY AUTO_INCREMENT)")

'''
### Step 3, Create the first user in the database ###
'''
mycursor.execute("INSERT INTO Prac (username,password,Lower_Rate_Limit,Upper_Rate_Limit,Ventrical_Amplitude,Ventrical_Pulse_Width,Ventrical_Refractory_Period,Attrial_Amplitude,Attrial_Pulse_Width,Attrial_Refractory_Period) VALUES(%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)",('First', 'user', 0, 0, 0, 0, 0, 0, 0, 0,))
Note: "First" and 'user' are the username and password for the first user in the database
'''
### Step 4, ALL DONE, run the front end code now
