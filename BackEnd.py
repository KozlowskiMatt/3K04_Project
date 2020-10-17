import mysql.connector
#import Front.py


db = mysql.connector.connect(
    host="localhost",
    user=" ", #Insert user name
    passwd=" ",#Insert Password
    database = "Prac " #Insert Database name
)
mycursor = db.cursor(buffered=True)

'''To create new database and table when first running the code

mycursor.execute("CREATE DATABASE [insert_data_base_name]")


mycursor.execute("CREATE TABLE users (username VARCHAR(25), password VARCHAR(25),Lower_Rate_Limit int, Upper_Rate_Limit int, \
#Ventrical_Amplitude int, Ventrical_Pulse_Width int, Ventrical_Refractory_Period int, Attrial_Amplitude int, Attrial_Pulse_Width int,\
Attrial_Refractory_Period int, personID int PRIMARY KEY AUTO_INCREMENT)")
'''

'''
Function: NewUser()
Paramaeters: name --> input username
             passwrd --> input password

Description: This function will create a new user if there is enough space in the data base
             and if input username and password  dont already exist
'''
def NewUser(name,passwrd):
    mycursor.execute("SELECT *FROM Prac ORDER BY personID DESC LIMIT 1 ")
    CREATING = True
    for i in mycursor:
        if i[-1] >10: # To check if there is space to add a new user
            while (CREATING):
                mycursor.execute("SELECT username,password FROM Prac")
                user = True
                for info in mycursor:
                    if name == info[0] or passwrd == info[-1]:
                        user = False
                        print("Sorry Username or Password is not available try again!")
                        break
                if (user == True):
                    CREATING = False
            mycursor.execute("INSERT INTO Prac (username,password,Lower_Rate_Limit,Upper_Rate_Limit,Ventrical_Amplitude,Ventrical_Pulse_Width,Ventrical_Refractory_Period,Attrial_Amplitude,Attrial_Pulse_Width,Attrial_Refractory_Period) VALUES(%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)",(name,passwrd,0,0,0,0,0,0,0,0,))
            db.commit()
            print("It is made!")
        else:
            print("Sorry Database is full")
    return 0


''' 
This function could work with front end if we take the logic from NewUser and put it into Front end
'''
'''
def Reg(name,passwrd):
    mycursor.execute("INSERT INTO Prac (username,password,Lower_Rate_Limit,Upper_Rate_Limit,Ventrical_Amplitude,Ventrical_Pulse_Width,Ventrical_Refractory_Period,Attrial_Amplitude,Attrial_Pulse_Width,Attrial_Refractory_Period) VALUES(%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)", (name, passwrd, 0, 0, 0, 0, 0, 0, 0, 0,))
    db.commit()
    return 0
'''

''' 
This will let the user login to their acount if username and password match with the database
'''
def Login():
    name = input("Please enter your username")
    passwrd = input("Please enter your password")

    mycursor.execute("SELECT username,password FROM Prac")
    for info in mycursor:
        if name == info[0] and passwrd == info[-1]:
            print("Login Succesful")
            return (name)
    print("Incorrect Login information")
    return 0


''' Functions to update the Parameters depending on the user '''

def Change_Lower_Rate_Limit(name,LRL):
    mycursor.execute("UPDATE Prac SET Lower_Rate_Limit = %s WHERE username = '%s'"%(LRL,name))
    db.commit()

def Change_Upper_Rate_Limit(name,URL):
    mycursor.execute("UPDATE Prac SET Upper_Rate_Limit = %s WHERE username = '%s'"%(URL,name))
    db.commit()

def Change_Ventrical_Amplitude(name,VA):
    mycursor.execute("UPDATE Prac SET Ventrical_Amplitude = %s WHERE username = '%s'"%(VA,name))
    db.commit()

def Change_Ventrical_Pulse_Width(name,VPW):
    mycursor.execute("UPDATE Prac SET Ventrical_Pulse_Width = %s WHERE username = '%s'"%(VPW,name))
    db.commit()

def Change_Ventrical_Refractory_Period(name,LRL):
    mycursor.execute("UPDATE Prac SET Ventrical_Refractory_Period = %s WHERE username = '%s'"%(VRP,name))
    db.commit()

def Change_Attrial_Amplitude(name,AA):
    mycursor.execute("UPDATE Prac SET Attrial_Amplitude = %s WHERE username = '%s'"%(AA,name))
    db.commit()

def Change_Attrial_Pulse_Width(name,APW):
    mycursor.execute("UPDATE Prac SET Attrial_Pulse_Width = %s WHERE username = '%s'"%(APW,name))
    db.commit()

def Change_Attrial_Refractory_Period(name,ARP):
    mycursor.execute("UPDATE Prac SET Attrial_Refractory_Period = %s WHERE username = '%s'"%(ARP,name))
    db.commit()

'''
Functions to fetch desired parameters given the pacemaker mode
'''

