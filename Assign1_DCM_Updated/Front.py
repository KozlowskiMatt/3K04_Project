from tkinter import *
from tkinter import ttk
import Back


class DCM(Tk):
    def __init__(self):
        Tk.__init__(self)
        self.frame = None
        self.switchFrame(WelcomeScreen)

    def switchFrame(self, frameClass):
        newFrame = frameClass(self)
        if self.frame is not None:
            self.frame.destroy()
        self.frame = newFrame
        self.frame.pack()

    def callback(self, val):
        if val == "AOO":
            self.switchFrame(AOO_Mode)
        elif val == "VOO":
            self.switchFrame(VOO_Mode)
        elif val == "AAI":
            self.switchFrame(AAI_Mode)
        elif val == "VVI":
            self.switchFrame(VVI_Mode)
        elif val == "DOO":
            self.switchFrame(DOO_Mode)
        elif val == "AOOR":
            self.switchFrame(AOOR_Mode)
        elif val == "VOOR":
            self.switchFrame(VOOR_Mode)
        elif val == "AAIR":
            self.switchFrame(AAIR_Mode)
        elif val == "VVIR":
            self.switchFrame(VVIR_Mode)
        elif val == "DOOR":
            self.switchFrame(DOOR_Mode)
        



class WelcomeScreen(Frame):

    def __init__(self, master):
        Frame.__init__(self, master)

        welcome = Label(self, text="Welcome", font=("Helvetica", 46))
        welcome.grid(row=0, columnspan=2)

        username = Label(self, text="Username")
        password = Label(self, text="Password")
        username.grid(row=1)
        password.grid(row=2)

        self.userEntry = Entry(self)
        self.passwordEntry = Entry(self)
        self.userEntry.grid(row=1, column=1)
        self.passwordEntry.grid(row=2, column=1)

        login = Button(self, text="Login", command=lambda: self.login(master))
        newUser = Button(self, text="Create New User", command=lambda: self.createUser(master))
        login.grid(row=3)
        newUser.grid(row=3, column=1)

        self.max_reached_error = Label(self, text="", fg='red', font=("Helvetica", 12)) #text should be empty at the start
        self.max_reached_error.grid(row=4, columnspan=2)

        self.invalid_userpass = Label(self, text="", fg='red', font=("Helvetica", 12))
        self.max_reached_error.grid(row=4, columnspan=2)

    def createUser(self,master):
        #check if max users reached 10
        if Back.CheckUsers():
            master.switchFrame(NewUser) 

        else:
            #ERROR MAX USER CAPACITY REACHED
            self.max_reached_error.config(text="Maximum user capacity reached.")
            #print("full")

    def login(self, master):
        ##################check if user/pass is valid here###################
        global loginUSERNAME
        loginUSERNAME = self.userEntry.get()
        loginPASSWORD = self.passwordEntry.get()

        if Back.Login(loginUSERNAME,loginPASSWORD):
            master.switchFrame(HomePage)
        else:
            #ERROR INCORRECT USERNAME/PASSWORD
            self.max_reached_error.config(text="Invalid Username and Password.")
            #print("Username dont match")

class NewUser(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)

        title = Label(self, text="Enter new username and password", font=("Helvetica", 16))
        title.grid(row=0, columnspan=2)

        username = Label(self, text="Username")
        password = Label(self, text="Password")
        username.grid(row=1)
        password.grid(row=2)

        self.userEntry = Entry(self)
        self.passwordEntry = Entry(self)
        self.userEntry.grid(row=1, column=1)
        self.passwordEntry.grid(row=2, column=1)

        register = Button(self, text="Register new user", command=lambda: self.register(master))
        register.grid(row=3, columnspan=2)

        self.invalid_entry = Label(self, text="", fg='red', font=("Helvetica", 11)) #text should be empty at the start
        self.invalid_entry.grid(row=4, columnspan=2)

    def register(self, master):
        ################## Add User/pass here ###################
        registerUSERNAME = self.userEntry.get()
        registerPASSWORD = self.passwordEntry.get()
        val = Back.New(registerUSERNAME,registerPASSWORD) #val will be "empty" if entries are empty,
                                                            #it will be True if entries are valid
                                                            #it will be False if entries are invalid
        #print (val)
        if val == True: #valid entries
            master.switchFrame(WelcomeScreen)
            #REGISTER SUCCESS MESSAGE:

        elif val == "empty": #empty entry
            self.invalid_entry.config(text="No empty entries allowed.")

        else: #invalid entry (the same user/pass is already registered)

            #REGISTER ERROR. User/Pass already registered.
            self.invalid_entry.config(text="Username and Password are already registered.")



class HomePage(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font="Helvetica 44")
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx= 0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')

        if (loginUSERNAME != Back.getPrevUser()): #replace ok with previous username stored
            self.newDevice = Label(self, text="Different user detected.", fg='green', font=("Helvetica", 14))
            self.newDevice.place(relx=0.1, rely=0.9)
            Back.StoreUser(loginUSERNAME)
        else:
            #store username
            Back.StoreUser(loginUSERNAME)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))






class AOO_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(0)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.56)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.56)

        Atr_amp = Label(self, text="Atrial Amplitude (V)")
        Atr_amp.place(relx=0.2, rely=0.62)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.62)

        Atr_PW = Label(self, text="Atrial Pulse Width (ms)")
        Atr_PW.place(relx=0.2, rely=0.68)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.68)

        ARP = Label(self, text="Atrial Refractory Period (ms)")
        ARP.place(relx=0.2, rely=0.74)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.74)

        # VALUES -> Display values that are stored in the database
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.56)
        self.value3 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Amplitude' ))  # ATR AMP
        self.value3.place(relx=0.8, rely=0.62)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))  # ATR PW
        self.value4.place(relx=0.8, rely=0.68)
        self.value5 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Refractory_Period'))  # ARP
        self.value5.place(relx=0.8, rely=0.74)

        # BUTTON TO STORE VALUES
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get()))
        storeButton.place(relx=0.8, rely=0.9)

        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)

    def storeValues(self, master, e1, e2, e3, e4, e5):
        # When saved the values get updated in the sql database

        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Attrial_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Attrial_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Attrial_Refractory_Period(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Refractory_Period'))

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")






class VOO_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(1)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.56)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.56)

        Vent_amp = Label(self, text="Ventricular Amplitude (V)")
        Vent_amp.place(relx=0.2, rely=0.62)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.62)

        Vent_PW = Label(self, text="Ventricular Pulse Width (ms)")
        Vent_PW.place(relx=0.2, rely=0.68)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.68)

        VRP = Label(self, text="Ventricular Refractory Period (ms)")
        VRP.place(relx=0.2, rely=0.74)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.74)

        # VALUES -> replace '0's with stored values (in the file)
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.56)
        self.value3 = Label(self, text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))  # VENT AMP
        self.value3.place(relx=0.8, rely=0.62)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))  # VENT PW
        self.value4.place(relx=0.8, rely=0.68)
        self.value5 = Label(self, text= Back.Get_Param(loginUSERNAME,'Ventrical_Refractory_Period'))  # VRP
        self.value5.place(relx=0.8, rely=0.74)

        # button to store values
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get()))
        storeButton.place(relx=0.8, rely=0.9)
        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)

    def storeValues(self, master, e1, e2, e3, e4, e5):
        # When saved, store the entry values in text file.

        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  #Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Ventrical_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Ventrical_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Ventrical_Refractory_Period(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Refractory_Period'))

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")






class AAI_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(2)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.56)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.56)

        Atr_amp = Label(self, text="Atrial Amplitude (V)")
        Atr_amp.place(relx=0.2, rely=0.62)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.62)

        Atr_PW = Label(self, text="Atrial Pulse Width (ms)")
        Atr_PW.place(relx=0.2, rely=0.68)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.68)

        ARP = Label(self, text="Atrial Refractory Period (ms)")
        ARP.place(relx=0.2, rely=0.74)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.74)

        # VALUES -> replace '0's with stored values (in the file)
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.56)
        self.value3 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Amplitude' ))  # ATR AMP
        self.value3.place(relx=0.8, rely=0.62)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))  # ATR PW
        self.value4.place(relx=0.8, rely=0.68)
        self.value5 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Refractory_Period'))  # ARP
        self.value5.place(relx=0.8, rely=0.74)

        # button to store values
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get(),))
        storeButton.place(relx=0.8, rely=0.9)
        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)


    def storeValues(self, master, e1, e2, e3, e4, e5):
        # When saved, store the entry values in text file.

        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Attrial_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Attrial_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Attrial_Refractory_Period(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Refractory_Period'))

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")






class VVI_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(3)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        parameters = Label(self, text='Parameters')

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.56)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.56)

        Vent_amp = Label(self, text="Ventricular Amplitude (V)")
        Vent_amp.place(relx=0.2, rely=0.62)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.62)

        Vent_PW = Label(self, text="Ventricular Pulse Width (ms)")
        Vent_PW.place(relx=0.2, rely=0.68)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.68)

        VRP = Label(self, text="Ventricular Refractory Period (ms)")
        VRP.place(relx=0.2, rely=0.74)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.74)

        # VALUES -> replace '0's with stored values (in the file)
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.56)
        self.value3 = Label(self, text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))  # VENT AMP
        self.value3.place(relx=0.8, rely=0.62)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))  # VENT PW
        self.value4.place(relx=0.8, rely=0.68)
        self.value5 = Label(self, text= Back.Get_Param(loginUSERNAME,'Ventrical_Refractory_Period'))  # VRP
        self.value5.place(relx=0.8, rely=0.74)

        # button to store values
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get()))
        storeButton.place(relx=0.8, rely=0.9)
        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)

    def storeValues(self, master, e1, e2, e3, e4, e5):
        # When saved, store the entry values in text file.
        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Ventrical_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Ventrical_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Ventrical_Refractory_Period(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Refractory_Period'))

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")






class DOO_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(4)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        parameters = Label(self, text='Parameters')

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.55)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.55)

        Vent_amp = Label(self, text="Ventricular Amplitude (V)")
        Vent_amp.place(relx=0.2, rely=0.60)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.60)

        Vent_PW = Label(self, text="Ventricular Pulse Width (ms)")
        Vent_PW.place(relx=0.2, rely=0.65)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.65)

        Atr_amp = Label(self, text="Atrial Amplitude (V)")
        Atr_amp.place(relx=0.2, rely=0.70)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.70)

        Atr_PW = Label(self, text="Atrial Pulse Width (ms)")
        Atr_PW.place(relx=0.2, rely=0.75)
        entry6 = Entry(self)
        entry6.place(relx=0.5, rely=0.75)

        F_AV_Delay = Label(self, text="Fixed AV Delay (ms)")
        F_AV_Delay.place(relx=0.2, rely=0.80)
        entry7 = Entry(self)
        entry7.place(relx=0.5, rely=0.80)

        # VALUES -> replace '0's with stored values (in the file)
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.55)
        self.value3 = Label(self, text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))  # VENT AMP
        self.value3.place(relx=0.8, rely=0.60)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))  # VENT PW
        self.value4.place(relx=0.8, rely=0.65)
        self.value5 = Label(self, text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))  # VENT AMP
        self.value5.place(relx=0.8, rely=0.70)
        self.value6 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))  # VENT PW
        self.value6.place(relx=0.8, rely=0.75)
        self.value7 = Label(self, text= Back.Get_Param(loginUSERNAME,'Fixed_AV_Delay'))  
        self.value7.place(relx=0.8, rely=0.80)

        # button to store values
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get(), entry6.get(), entry7.get()))
        storeButton.place(relx=0.8, rely=0.9)
        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)

    def storeValues(self, master, e1, e2, e3, e4, e5, e6, e7):
        # When saved, store the entry values in text file.
        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Ventrical_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Ventrical_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Attrial_Amplitude(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))

        if e6 != '':
            self.value6.config(text=e6)
            Back.Change_Attrial_Pulse_Width(loginUSERNAME,float(e6))
        else:
            self.value6.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))

        if e7 != '':
            self.value7.config(text=e7)
            Back.Change_Fixed_AV_Delay(loginUSERNAME,float(e7))
        else:
            self.value7.config(text = Back.Get_Param(loginUSERNAME,'Fixed_AV_Delay'))

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")





class AOOR_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(5)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.544)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.544)

        Atr_amp = Label(self, text="Atrial Amplitude (V)")
        Atr_amp.place(relx=0.2, rely=0.588)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.588)

        Atr_PW = Label(self, text="Atrial Pulse Width (ms)")
        Atr_PW.place(relx=0.2, rely=0.632)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.632)

        MSR = Label(self, text="Maximum Sensor Rate (ppm)")
        MSR.place(relx=0.2, rely=0.676)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.676)

        A_Thresh = Label(self, text="Activity Threshold")
        A_Thresh.place(relx=0.2, rely=0.72)
        entry6 = Entry(self)
        entry6.place(relx=0.5, rely=0.72)

        React_T = Label(self, text="Reaction Time (sec)")
        React_T.place(relx=0.2, rely=0.764)
        entry7 = Entry(self)
        entry7.place(relx=0.5, rely=0.764)

        Resp_Fact = Label(self, text="Response Factor")
        Resp_Fact.place(relx=0.2, rely=0.808)
        entry8 = Entry(self)
        entry8.place(relx=0.5, rely=0.808)

        Recov_T = Label(self, text="Recovery Time (min)")
        Recov_T.place(relx=0.2, rely=0.852)
        entry9 = Entry(self)
        entry9.place(relx=0.5, rely=0.852)

        # VALUES -> replace '0's with stored values (in the file)
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.544)
        self.value3 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Amplitude' ))  # ATR AMP
        self.value3.place(relx=0.8, rely=0.588)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))  # ATR PW
        self.value4.place(relx=0.8, rely=0.632)
        self.value5 = Label(self, text= Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate')) 
        self.value5.place(relx=0.8, rely=0.676)
        self.value6 = Label(self, text= Back.Get_Param(loginUSERNAME,'Activity_Threshold'))  
        self.value6.place(relx=0.8, rely=0.72)
        self.value7 = Label(self, text= Back.Get_Param(loginUSERNAME,'Reaction_Time')) 
        self.value7.place(relx=0.8, rely=0.764)
        self.value8 = Label(self, text= Back.Get_Param(loginUSERNAME,'Response_Factor'))  
        self.value8.place(relx=0.8, rely=0.808)
        self.value9 = Label(self, text= Back.Get_Param(loginUSERNAME,'Recovery_Time'))  
        self.value9.place(relx=0.8, rely=0.852)

        # button to store values
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get(),entry6.get(),entry7.get(),
                                                              entry8.get(),entry9.get()))
        storeButton.place(relx=0.8, rely=0.9)
        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)


    def storeValues(self, master, e1, e2, e3, e4, e5, e6, e7, e8, e9):
        # When saved, store the entry values in text file.

        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Attrial_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Attrial_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Maximum_Sensor_Rate(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate'))

        if e6 != '':
            self.value6.config(text=e6)
            Back.Change_Activity_Threshold(loginUSERNAME,float(e6))
        else:
            self.value6.config(text = Back.Get_Param(loginUSERNAME,'Activity_Threshold'))

        if e7 != '':
            self.value7.config(text=e7)
            Back.Change_Reaction_Time(loginUSERNAME,float(e7))
        else:
            self.value7.config(text = Back.Get_Param(loginUSERNAME,'Reaction_Time'))

        if e8 != '':
            self.value8.config(text=e8)
            Back.Change_Response_Factor(loginUSERNAME,float(e8))
        else:
            self.value8.config(text = Back.Get_Param(loginUSERNAME,'Response_Factor'))

        if e9 != '':
            self.value9.config(text=e9)
            Back.Change_Recovery_Time(loginUSERNAME,float(e9))
        else:
            self.value9.config(text = Back.Get_Param(loginUSERNAME,'Recovery_Time'))

        

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")





class VOOR_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(6)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        parameters = Label(self, text='Parameters')

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.544)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.544)

        Vent_amp = Label(self, text="Ventricular Amplitude (V)")
        Vent_amp.place(relx=0.2, rely=0.588)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.588)

        Vent_PW = Label(self, text="Ventricular Pulse Width (ms)")
        Vent_PW.place(relx=0.2, rely=0.632)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.632)

        MSR = Label(self, text="Maximum Sensor Rate (ppm)")
        MSR.place(relx=0.2, rely=0.676)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.676)

        A_Thresh = Label(self, text="Activity Threshold")
        A_Thresh.place(relx=0.2, rely=0.72)
        entry6 = Entry(self)
        entry6.place(relx=0.5, rely=0.72)

        React_T = Label(self, text="Reaction Time (sec)")
        React_T.place(relx=0.2, rely=0.764)
        entry7 = Entry(self)
        entry7.place(relx=0.5, rely=0.764)

        Resp_Fact = Label(self, text="Response Factor")
        Resp_Fact.place(relx=0.2, rely=0.808)
        entry8 = Entry(self)
        entry8.place(relx=0.5, rely=0.808)

        Recov_T = Label(self, text="Recovery Time (min)")
        Recov_T.place(relx=0.2, rely=0.852)
        entry9 = Entry(self)
        entry9.place(relx=0.5, rely=0.852)

        # VALUES -> replace '0's with stored values (in the file)
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.544)
        self.value3 = Label(self, text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))  # VENT AMP
        self.value3.place(relx=0.8, rely=0.588)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))  # VENT PW
        self.value4.place(relx=0.8, rely=0.632)
        self.value5 = Label(self, text= Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate'))  
        self.value5.place(relx=0.8, rely=0.676)
        self.value6 = Label(self, text= Back.Get_Param(loginUSERNAME,'Activity_Threshold'))  
        self.value6.place(relx=0.8, rely=0.72)
        self.value7 = Label(self, text= Back.Get_Param(loginUSERNAME,'Reaction_Time'))  
        self.value7.place(relx=0.8, rely=0.764)
        self.value8 = Label(self, text= Back.Get_Param(loginUSERNAME,'Response_Factor'))  
        self.value8.place(relx=0.8, rely=0.808)
        self.value9 = Label(self, text= Back.Get_Param(loginUSERNAME,'Recovery_Time'))  
        self.value9.place(relx=0.8, rely=0.852)

        # button to store values
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get(), entry6.get(), entry7.get(),
                                                              entry8.get(), entry9.get()))
        storeButton.place(relx=0.8, rely=0.9)
        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)

    def storeValues(self, master, e1, e2, e3, e4, e5, e6, e7, e8, e9):
        # When saved, store the entry values in text file.
        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Ventrical_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Ventrical_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Maximum_Sensor_Rate(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate'))

        if e6 != '':
            self.value6.config(text=e6)
            Back.Change_Activity_Threshold(loginUSERNAME,float(e6))
        else:
            self.value6.config(text = Back.Get_Param(loginUSERNAME,'Activity_Threshold'))

        if e7 != '':
            self.value7.config(text=e7)
            Back.Change_Reaction_Time(loginUSERNAME,float(e7))
        else:
            self.value7.config(text = Back.Get_Param(loginUSERNAME,'Reaction_Time'))

        if e8 != '':
            self.value8.config(text=e8)
            Back.Change_Response_Factor(loginUSERNAME,float(e8))
        else:
            self.value8.config(text = Back.Get_Param(loginUSERNAME,'Response_Factor'))

        if e9 != '':
            self.value9.config(text=e9)
            Back.Change_Recovery_Time(loginUSERNAME,float(e9))
        else:
            self.value9.config(text = Back.Get_Param(loginUSERNAME,'Recovery_Time'))

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")





class AAIR_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(7)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.54)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.54)

        Atr_amp = Label(self, text="Atrial Amplitude (V)")
        Atr_amp.place(relx=0.2, rely=0.58)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.58)

        Atr_PW = Label(self, text="Atrial Pulse Width (ms)")
        Atr_PW.place(relx=0.2, rely=0.62)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.62)

        MSR = Label(self, text="Maximum Sensor Rate (ppm)")
        MSR.place(relx=0.2, rely=0.66)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.66)

        A_Thresh = Label(self, text="Activity Threshold")
        A_Thresh.place(relx=0.2, rely=0.70)
        entry6 = Entry(self)
        entry6.place(relx=0.5, rely=0.70)

        React_T = Label(self, text="Reaction Time (sec)")
        React_T.place(relx=0.2, rely=0.74)
        entry7 = Entry(self)
        entry7.place(relx=0.5, rely=0.74)

        Resp_Fact = Label(self, text="Response Factor")
        Resp_Fact.place(relx=0.2, rely=0.78)
        entry8 = Entry(self)
        entry8.place(relx=0.5, rely=0.78)

        Recov_T = Label(self, text="Recovery Time (min)")
        Recov_T.place(relx=0.2, rely=0.82)
        entry9 = Entry(self)
        entry9.place(relx=0.5, rely=0.82)

        ARP = Label(self, text="Atrial Refractory Period (ms)")
        ARP.place(relx=0.2, rely=0.86)
        entry10 = Entry(self)
        entry10.place(relx=0.5, rely=0.86)


        # VALUES -> replace '0's with stored values (in the file)
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.54)
        self.value3 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Amplitude' ))  # ATR AMP
        self.value3.place(relx=0.8, rely=0.58)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))  # ATR PW
        self.value4.place(relx=0.8, rely=0.62)
        self.value5 = Label(self, text= Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate'))
        self.value5.place(relx=0.8, rely=0.66)
        self.value6 = Label(self, text= Back.Get_Param(loginUSERNAME,'Activity_Threshold'))  
        self.value6.place(relx=0.8, rely=0.70)
        self.value7 = Label(self, text= Back.Get_Param(loginUSERNAME,'Reaction_Time'))  
        self.value7.place(relx=0.8, rely=0.74)
        self.value8 = Label(self, text= Back.Get_Param(loginUSERNAME,'Response_Factor'))  
        self.value8.place(relx=0.8, rely=0.78)
        self.value9 = Label(self, text= Back.Get_Param(loginUSERNAME,'Recovery_Time'))  
        self.value9.place(relx=0.8, rely=0.82)
        self.value10 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Refractory_Period'))  # ARP
        self.value10.place(relx=0.8, rely=0.86)

        # button to store values
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get(),entry6.get(),entry7.get(),
                                                              entry8.get(),entry9.get(),entry10.get()))
        storeButton.place(relx=0.8, rely=0.9)
        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)


    def storeValues(self, master, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10):
        # When saved, store the entry values in text file.

        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Attrial_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Attrial_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Maximum_Sensor_Rate(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate'))

        if e6 != '':
            self.value6.config(text=e6)
            Back.Change_Activity_Threshold(loginUSERNAME,float(e6))
        else:
            self.value6.config(text = Back.Get_Param(loginUSERNAME,'Activity_Threshold'))

        if e7 != '':
            self.value7.config(text=e7)
            Back.Change_Reaction_Time(loginUSERNAME,float(e7))
        else:
            self.value7.config(text = Back.Get_Param(loginUSERNAME,'Reaction_Time'))

        if e8 != '':
            self.value8.config(text=e8)
            Back.Change_Response_Factor(loginUSERNAME,float(e8))
        else:
            self.value8.config(text = Back.Get_Param(loginUSERNAME,'Response_Factor'))

        if e9 != '':
            self.value9.config(text=e9)
            Back.Change_Recovery_Time(loginUSERNAME,float(e9))
        else:
            self.value9.config(text = Back.Get_Param(loginUSERNAME,'Recovery_Time'))

        if e10 != '':
            self.value10.config(text=e10)
            Back.Change_Attrial_Refractory_Period(loginUSERNAME,float(e10))
        else:
            self.value10.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Refractory_Period'))

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")





class VVIR_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(8)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        parameters = Label(self, text='Parameters')

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.54)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.54)

        Vent_amp = Label(self, text="Ventricular Amplitude (V)")
        Vent_amp.place(relx=0.2, rely=0.58)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.58)

        Vent_PW = Label(self, text="Ventricular Pulse Width (ms)")
        Vent_PW.place(relx=0.2, rely=0.62)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.62)

        MSR = Label(self, text="Maximum Sensor Rate (ppm)")
        MSR.place(relx=0.2, rely=0.66)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.66)

        A_Thresh = Label(self, text="Activity Threshold")
        A_Thresh.place(relx=0.2, rely=0.70)
        entry6 = Entry(self)
        entry6.place(relx=0.5, rely=0.70)

        React_T = Label(self, text="Reaction Time (sec)")
        React_T.place(relx=0.2, rely=0.74)
        entry7 = Entry(self)
        entry7.place(relx=0.5, rely=0.74)

        Resp_Fact = Label(self, text="Response Factor")
        Resp_Fact.place(relx=0.2, rely=0.78)
        entry8 = Entry(self)
        entry8.place(relx=0.5, rely=0.78)

        Recov_T = Label(self, text="Recovery Time (min)")
        Recov_T.place(relx=0.2, rely=0.82)
        entry9 = Entry(self)
        entry9.place(relx=0.5, rely=0.82)

        VRP = Label(self, text="Ventricular Refractory Period (ms)")
        VRP.place(relx=0.2, rely=0.86)
        entry10 = Entry(self)
        entry10.place(relx=0.5, rely=0.86)

        # VALUES -> replace '0's with stored values (in the file)
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.54)
        self.value3 = Label(self, text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))  # VENT AMP
        self.value3.place(relx=0.8, rely=0.58)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))  # VENT PW
        self.value4.place(relx=0.8, rely=0.62)
        self.value5 = Label(self, text= Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate'))
        self.value5.place(relx=0.8, rely=0.66)
        self.value6 = Label(self, text= Back.Get_Param(loginUSERNAME,'Activity_Threshold'))  
        self.value6.place(relx=0.8, rely=0.70)
        self.value7 = Label(self, text= Back.Get_Param(loginUSERNAME,'Reaction_Time'))  
        self.value7.place(relx=0.8, rely=0.74)
        self.value8 = Label(self, text= Back.Get_Param(loginUSERNAME,'Response_Factor'))  
        self.value8.place(relx=0.8, rely=0.78)
        self.value9 = Label(self, text= Back.Get_Param(loginUSERNAME,'Recovery_Time'))  
        self.value9.place(relx=0.8, rely=0.82)
        self.value10 = Label(self, text= Back.Get_Param(loginUSERNAME,'Ventrical_Refractory_Period'))  # VRP
        self.value10.place(relx=0.8, rely=0.86)

        # button to store values
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get(), entry6.get(), entry7.get(),
                                                              entry8.get(), entry9.get(), entry10.get()))
        storeButton.place(relx=0.8, rely=0.9)
        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)

    def storeValues(self, master, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10):
        # When saved, store the entry values in text file.
        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Ventrical_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Ventrical_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Maximum_Sensor_Rate(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate'))

        if e6 != '':
            self.value6.config(text=e6)
            Back.Change_Activity_Threshold(loginUSERNAME,float(e6))
        else:
            self.value6.config(text = Back.Get_Param(loginUSERNAME,'Activity_Threshold'))

        if e7 != '':
            self.value7.config(text=e7)
            Back.Change_Reaction_Time(loginUSERNAME,float(e7))
        else:
            self.value7.config(text = Back.Get_Param(loginUSERNAME,'Reaction_Time'))

        if e8 != '':
            self.value8.config(text=e8)
            Back.Change_Response_Factor(loginUSERNAME,float(e8))
        else:
            self.value8.config(text = Back.Get_Param(loginUSERNAME,'Response_Factor'))

        if e9 != '':
            self.value9.config(text=e9)
            Back.Change_Recovery_Time(loginUSERNAME,float(e9))
        else:
            self.value9.config(text = Back.Get_Param(loginUSERNAME,'Recovery_Time'))

        if e10 != '':
            self.value10.config(text=e10)
            Back.Change_Ventrical_Refractory_Period(loginUSERNAME,float(e10))
        else:
            self.value10.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Refractory_Period'))

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")






class DOOR_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='800')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters. \nDo not include units in the entries.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI","DOO","AOOR","VOOR","AAIR","VVIR","DOOR"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(9)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        parameters = Label(self, text='Parameters')

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit (ppm)")
        LRL.place(relx=0.2, rely=0.45)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.45)

        URL = Label(self, text="Upper Rate Limit (ppm)")
        URL.place(relx=0.2, rely=0.4875)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.4875)

        Vent_amp = Label(self, text="Ventricular Amplitude (V)")
        Vent_amp.place(relx=0.2, rely=0.525)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.525)

        Vent_PW = Label(self, text="Ventricular Pulse Width (ms)")
        Vent_PW.place(relx=0.2, rely=0.5625)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.5625)

        Atr_amp = Label(self, text="Atrial Amplitude (V)")
        Atr_amp.place(relx=0.2, rely=0.6)
        entry5 = Entry(self)
        entry5.place(relx=0.5, rely=0.6)

        Atr_PW = Label(self, text="Atrial Pulse Width (ms)")
        Atr_PW.place(relx=0.2, rely=0.6375)
        entry6 = Entry(self)
        entry6.place(relx=0.5, rely=0.6375)

        MSR = Label(self, text="Maximum Sensor Rate (ppm)")
        MSR.place(relx=0.2, rely=0.675)
        entry7 = Entry(self)
        entry7.place(relx=0.5, rely=0.675)

        A_Thresh = Label(self, text="Activity Threshold")
        A_Thresh.place(relx=0.2, rely=0.7125)
        entry8 = Entry(self)
        entry8.place(relx=0.5, rely=0.7125)

        React_T = Label(self, text="Reaction Time (sec)")
        React_T.place(relx=0.2, rely=0.75)
        entry9 = Entry(self)
        entry9.place(relx=0.5, rely=0.75)

        Resp_Fact = Label(self, text="Response Factor")
        Resp_Fact.place(relx=0.2, rely=0.7875)
        entry10 = Entry(self)
        entry10.place(relx=0.5, rely=0.7875)

        Recov_T = Label(self, text="Recovery Time (min)")
        Recov_T.place(relx=0.2, rely=0.825)
        entry11 = Entry(self)
        entry11.place(relx=0.5, rely=0.825)

        F_AV_Delay = Label(self, text="Fixed AV Delay (ms)")
        F_AV_Delay.place(relx=0.2, rely=0.8625)
        entry12 = Entry(self)
        entry12.place(relx=0.5, rely=0.8625)

        # VALUES -> replace '0's with stored values (in the file)
        self.value1 = Label(self, text= Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  # LRL
        self.value1.place(relx=0.8, rely=0.45)
        self.value2 = Label(self, text= Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))  # URL
        self.value2.place(relx=0.8, rely=0.4875)
        self.value3 = Label(self, text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))  # VENT AMP
        self.value3.place(relx=0.8, rely=0.525)
        self.value4 = Label(self, text= Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))  # VENT PW
        self.value4.place(relx=0.8, rely=0.5625)
        self.value5 = Label(self, text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))  # VENT AMP
        self.value5.place(relx=0.8, rely=0.6)
        self.value6 = Label(self, text= Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))  # VENT PW
        self.value6.place(relx=0.8, rely=0.6375)
        self.value7 = Label(self, text= Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate'))  
        self.value7.place(relx=0.8, rely=0.675)
        self.value8 = Label(self, text= Back.Get_Param(loginUSERNAME,'Activity_Threshold'))  
        self.value8.place(relx=0.8, rely=0.7125)
        self.value9 = Label(self, text= Back.Get_Param(loginUSERNAME,'Reaction_Time'))  
        self.value9.place(relx=0.8, rely=0.75)
        self.value10 = Label(self, text= Back.Get_Param(loginUSERNAME,'Response_Factor'))  
        self.value10.place(relx=0.8, rely=0.7875)
        self.value11 = Label(self, text= Back.Get_Param(loginUSERNAME,'Recovery_Time'))  
        self.value11.place(relx=0.8, rely=0.825)
        self.value12 = Label(self, text= Back.Get_Param(loginUSERNAME,'Fixed_AV_Delay'))  
        self.value12.place(relx=0.8, rely=0.8625)

        # button to store values
        storeButton = Button(self, text="Store",
                             command=lambda: self.storeValues(master, entry1.get(), entry2.get(), entry3.get(),
                                                              entry4.get(), entry5.get(), entry6.get(), entry7.get(),
                                                              entry8.get(), entry9.get(), entry10.get(), entry11.get(),
                                                              entry12.get()))
        storeButton.place(relx=0.8, rely=0.9)
        # button to connect
        connectButton = Button(self, text="Connect", command=lambda: self.connect(master))
        connectButton.place(relx=0.9, rely=0.9)

        self.connected_message = Label(self,text="", fg='blue', font=("Helvetica", 12))
        self.connected_message.place(relx=0.1, rely=0.95)

    def storeValues(self, master, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12):
        # When saved, store the entry values in text file.
        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,float(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,float(e2))
        else:
            self.value2.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Ventrical_Amplitude(loginUSERNAME,float(e3))
        else:
            self.value3.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Ventrical_Pulse_Width(loginUSERNAME,float(e4))
        else:
            self.value4.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Attrial_Amplitude(loginUSERNAME,float(e5))
        else:
            self.value5.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))

        if e6 != '':
            self.value6.config(text=e6)
            Back.Change_Attrial_Pulse_Width(loginUSERNAME,float(e6))
        else:
            self.value6.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))

        if e7 != '':
            self.value7.config(text=e7)
            Back.Change_Maximum_Sensor_Rate(loginUSERNAME,float(e7))
        else:
            self.value7.config(text = Back.Get_Param(loginUSERNAME,'Maximum_Sensor_Rate'))

        if e8 != '':
            self.value8.config(text=e8)
            Back.Change_Activity_Threshold(loginUSERNAME,float(e8))
        else:
            self.value8.config(text = Back.Get_Param(loginUSERNAME,'Activity_Threshold'))

        if e9 != '':
            self.value9.config(text=e9)
            Back.Change_Reaction_Time(loginUSERNAME,float(e9))
        else:
            self.value9.config(text = Back.Get_Param(loginUSERNAME,'Reaction_Time'))

        if e10 != '':
            self.value10.config(text=e10)
            Back.Change_Response_Factor(loginUSERNAME,float(e10))
        else:
            self.value10.config(text = Back.Get_Param(loginUSERNAME,'Response_Factor'))

        if e11 != '':
            self.value11.config(text=e11)
            Back.Change_Recovery_Time(loginUSERNAME,float(e11))
        else:
            self.value11.config(text = Back.Get_Param(loginUSERNAME,'Recovery_Time'))

        if e12 != '':
            self.value12.config(text=e12)
            Back.Change_Fixed_AV_Delay(loginUSERNAME,float(e12))
        else:
            self.value12.config(text = Back.Get_Param(loginUSERNAME,'Fixed_AV_Delay'))

    def connect(self, master):
    	self.connected_message.config(text= "Connected to pacemaker device.")




dcm = DCM()
dcm.resizable(width=False, height=False)
dcm.mainloop()