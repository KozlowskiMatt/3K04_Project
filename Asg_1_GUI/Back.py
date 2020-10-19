import mysql.connector

mysql_user = " " #Insert mysql password name here
mysql_passwd = " " #Insert mysql password name here 

db = mysql.connector.connect(
    host="localhost",
    user= mysql_user,
    passwd= mysql_passwd,
    database = 'Prac'
)
mycursor = db.cursor(buffered=True)


'''
Function: New(name,passwrd)
Paramaeters: name --> input username
             passwrd --> input password

Description: This function will create a new user if there is enough space in the data base
             and if input username and password  dont already exist
'''

def New(name,passwrd):
    mycursor.execute("SELECT *FROM Prac ORDER BY personID DESC LIMIT 1 ")
    CREATING = True
    for i in mycursor:
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
        mycursor.execute("INSERT INTO Prac (username,password,Lower_Rate_Limit,Upper_Rate_Limit,Ventrical_Amplitude,Ventrical_Pulse_Width,Ventrical_Refractory_Period,Attrial_Amplitude,Attrial_Pulse_Width,Attrial_Refractory_Period) VALUES(%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)",(name, passwrd, 0, 0, 0, 0, 0, 0, 0, 0,))
        db.commit()
        print("It is made!")
        return True
    return False

'''
Function CheckUsers() is used to see whether there is enough space in database to create a new user
'''
def CheckUsers():
    mycursor.execute("SELECT *FROM Prac ORDER BY personID DESC LIMIT 1 ")
    for i in mycursor:
        if i[-1] > 10:
            return True
    return False

''' 
This will let the user login to their acount if username and password match with the database
'''
def Login(name,passwrd):
    mycursor.execute("SELECT username,password FROM Prac")
    for info in mycursor:
        if name == info[0] and passwrd == info[-1]:
            #print("Login Succesful")
            #return (name)
            return 1
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

def Change_Ventrical_Refractory_Period(name,VRP):
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
##########################################################################################################


##### To get any parameter value given username and parameter, will be used to display current stored values
def Get_Param(name,param):
    query = "SELECT username,%s FROM Prac WHERE username = '%s'"%(param,name)
    print(query)
    mycursor.execute(query)
    for i in mycursor:
        print(i[-1])
    return (str(i[-1]))


