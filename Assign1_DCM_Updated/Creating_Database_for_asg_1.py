import mysql.connector


mysql_user = "" #Insert mysql password name here
mysql_passwd = "" #Insert mysql password name here 


### Steps to create new database and table when first running the code###

### Step 1, uncomment the first set of '''s to run this to create your database ###
			#Then add the ''' comments again exactly like it was before.


'''

db = mysql.connector.connect(
    host="localhost",
    user= mysql_user,
    passwd= mysql_passwd,

)
mycursor = db.cursor(buffered=True)

#This database name should be the same as the one in the Back.py file. In this case the name is 'application'
mycursor.execute("CREATE DATABASE application")

'''




#Step 2: Uncomment '''s here, and KEEP THEM UNCOMMENTED for future mycursor commands.

'''
db = mysql.connector.connect(
    host="localhost",
    user= mysql_user,
    passwd= mysql_passwd,
    database = 'application' #database name here

)
mycursor = db.cursor(buffered=True)
'''




#Step 3: Uncomment '''s here and run to create a table. Keep the name as 'Prac'. Then COMMENT IT AGAIN after running to avoid the already exists error.
'''
mycursor.execute("CREATE TABLE Prac(username VARCHAR(25), password VARCHAR(25),Lower_Rate_Limit float, Upper_Rate_Limit float, \
Ventrical_Amplitude float, Ventrical_Pulse_Width float, Ventrical_Refractory_Period float, Attrial_Amplitude float, Attrial_Pulse_Width float,\
Attrial_Refractory_Period float, personID float PRIMARY KEY AUTO_INCREMENT)")
'''


#Step 4: Make sure Back.py has the same database as the one created here.
#DONE, Now run the Front.py and everything should be working. 


##############################            TESTING PURPOSES HERE           #################################

#Uncomment the line below and run to DELETE THE SELECTED DATABASE, then make it a comment again
#mycursor.execute("DROP DATABASE [database to delete]")


#Uncomment the line below and run to CLEAR THE ENTRIES OF Prac TABLE, then make it a comment again.
#mycursor.execute("TRUNCATE TABLE Prac")


#Uncomment the two lines below and run to ADD A DUMMY USER to the table. Can add multiple dummy users by running it again and again.
#mycursor.execute("INSERT INTO Prac (username,password,Lower_Rate_Limit,Upper_Rate_Limit,Ventrical_Amplitude,Ventrical_Pulse_Width,Ventrical_Refractory_Period,Attrial_Amplitude,Attrial_Pulse_Width,Attrial_Refractory_Period) VALUES(%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)",('First', 'user', 0, 0, 0, 0, 0, 0, 0, 0,))
#db.commit()


