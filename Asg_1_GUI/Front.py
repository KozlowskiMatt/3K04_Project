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

    def createUser(self,master):
        #check if max users reached 10
        if Back.CheckUsers():
            master.switchFrame(NewUser)
        else:
            print("full")

    def login(self, master):
        ##################check if user/pass is valid here###################
        global loginUSERNAME
        loginUSERNAME = self.userEntry.get()
        loginPASSWORD = self.passwordEntry.get()
        

        if Back.Login(loginUSERNAME,loginPASSWORD):
            master.switchFrame(HomePage)
        else:
            print("Username dont match")

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

    def register(self, master):
        ################## Add User/pass here ###################
        registerUSERNAME = self.userEntry.get()
        registerPASSWORD = self.passwordEntry.get()

        if Back.New(registerUSERNAME,registerPASSWORD):
            master.switchFrame(WelcomeScreen)
        else:
            print("sorry same pass and user")



class HomePage(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font="Helvetica 44")
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO", "VOO", "AAI", "VVI"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))


class AOO_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO", "VOO", "AAI", "VVI"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(0)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit")
        URL.place(relx=0.2, rely=0.56)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.56)

        Atr_amp = Label(self, text="Atrial Amplitude")
        Atr_amp.place(relx=0.2, rely=0.62)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.62)

        Atr_PW = Label(self, text="Atrial Pulse Width")
        Atr_PW.place(relx=0.2, rely=0.68)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.68)

        ARP = Label(self, text="Atrial Refractory Period")
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
        storeButton.place(relx=0.8, rely=0.8)

        # button to connect
        connectButton = Button(self, text="Connect")
        connectButton.place(relx=0.9, rely=0.8)

    def storeValues(self, master, e1, e2, e3, e4, e5):
        # When saved the values get updated in the sql database

        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,int(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,int(e2))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Attrial_Amplitude(loginUSERNAME,int(e3))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Attrial_Pulse_Width(loginUSERNAME,int(e4))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Attrial_Refractory_Period(loginUSERNAME,int(e5))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Refractory_Period'))


class VOO_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO", "VOO", "AAI", "VVI"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(1)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit")
        URL.place(relx=0.2, rely=0.56)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.56)

        Vent_amp = Label(self, text="Ventricular Amplitude")
        Vent_amp.place(relx=0.2, rely=0.62)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.62)

        Vent_PW = Label(self, text="Ventricular Pulse Width")
        Vent_PW.place(relx=0.2, rely=0.68)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.68)

        VRP = Label(self, text="Ventricular Refractory Period")
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
        storeButton.place(relx=0.8, rely=0.8)
        # button to connect
        connectButton = Button(self, text="Connect")
        connectButton.place(relx=0.9, rely=0.8)

    def storeValues(self, master, e1, e2, e3, e4, e5):
        # When saved, store the entry values in text file.

        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,int(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))  #Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,int(e2))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Ventrical_Amplitude(loginUSERNAME,int(e3))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Ventrical_Pulse_Width(loginUSERNAME,int(e4))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Ventrical_Refractory_Period(loginUSERNAME,int(e5))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Refractory_Period'))


class AAI_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO", "VOO", "AAI", "VVI"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(2)

        dropDown.bind("<<ComboboxSelected>>", lambda _: master.callback(dropDown.get()))

        # LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        # PARAMETERS AND ENTRIES FOR THEM
        LRL = Label(self, text="Lower Rate Limit")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit")
        URL.place(relx=0.2, rely=0.56)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.56)

        Atr_amp = Label(self, text="Atrial Amplitude")
        Atr_amp.place(relx=0.2, rely=0.62)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.62)

        Atr_PW = Label(self, text="Atrial Pulse Width")
        Atr_PW.place(relx=0.2, rely=0.68)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.68)

        ARP = Label(self, text="Atrial Refractory Period")
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
        storeButton.place(relx=0.8, rely=0.8)
        # button to connect
        connectButton = Button(self, text="Connect")
        connectButton.place(relx=0.9, rely=0.8)

    def storeValues(self, master, e1, e2, e3, e4, e5):
        # When saved, store the entry values in text file.

        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,int(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,int(e2))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Attrial_Amplitude(loginUSERNAME,int(e3))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Attrial_Pulse_Width(loginUSERNAME,int(e4))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Attrial_Refractory_Period(loginUSERNAME,int(e5))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Attrial_Refractory_Period'))


class VVI_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14),
                                text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO", "VOO", "AAI", "VVI"], state="readonly")
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
        LRL = Label(self, text="Lower Rate Limit")
        LRL.place(relx=0.2, rely=0.5)
        entry1 = Entry(self)
        entry1.place(relx=0.5, rely=0.5)

        URL = Label(self, text="Upper Rate Limit")
        URL.place(relx=0.2, rely=0.56)
        entry2 = Entry(self)
        entry2.place(relx=0.5, rely=0.56)

        Vent_amp = Label(self, text="Ventricular Amplitude")
        Vent_amp.place(relx=0.2, rely=0.62)
        entry3 = Entry(self)
        entry3.place(relx=0.5, rely=0.62)

        Vent_PW = Label(self, text="Ventricular Pulse Width")
        Vent_PW.place(relx=0.2, rely=0.68)
        entry4 = Entry(self)
        entry4.place(relx=0.5, rely=0.68)

        VRP = Label(self, text="Ventricular Refractory Period")
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
        storeButton.place(relx=0.8, rely=0.8)
        # button to connect
        connectButton = Button(self, text="Connect")
        connectButton.place(relx=0.9, rely=0.8)

    def storeValues(self, master, e1, e2, e3, e4, e5):
        # When saved, store the entry values in text file.

        # If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
            Back.Change_Lower_Rate_Limit(loginUSERNAME,int(e1))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Lower_Rate_Limit'))

        if e2 != '':
            self.value2.config(text=e2)
            Back.Change_Upper_Rate_Limit(loginUSERNAME,int(e2))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Upper_Rate_Limit'))

        if e3 != '':
            self.value3.config(text=e3)
            Back.Change_Ventrical_Amplitude(loginUSERNAME,int(e3))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Amplitude'))

        if e4 != '':
            self.value4.config(text=e4)
            Back.Change_Ventrical_Pulse_Width(loginUSERNAME,int(e4))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Pulse_Width'))

        if e5 != '':
            self.value5.config(text=e5)
            Back.Change_Ventrical_Refractory_Period(loginUSERNAME,int(e5))
        else:
            self.value1.config(text = Back.Get_Param(loginUSERNAME,'Ventrical_Refractory_Period'))

dcm = DCM()

dcm.mainloop()