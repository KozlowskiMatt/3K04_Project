from tkinter import *
from tkinter import ttk

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

        userEntry = Entry(self)
        passwordEntry = Entry(self)
        userEntry.grid(row=1, column=1)
        passwordEntry.grid(row=2, column=1)

        login = Button(self, text="Login", command=lambda: master.switchFrame(HomePage))
        newUser = Button(self, text="Create New User", command=lambda: master.switchFrame(NewUser))
        login.grid(row=3)
        newUser.grid(row=3, column=1)
                          
class NewUser(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
                          
        title = Label(self, text="Enter new username and password", font=("Helvetica", 16))
        title.grid(row=0, columnspan=2)
        
        username = Label(self, text="Username")
        password = Label(self, text="Password")
        username.grid(row=1)
        password.grid(row=2)

        userEntry = Entry(self)
        passwordEntry = Entry(self)
        userEntry.grid(row=1, column=1)
        passwordEntry.grid(row=2, column=1)
        
        register = Button(self, text="Register new user", command=lambda: master.switchFrame(WelcomeScreen))
        register.grid(row=3, columnspan=2)
class HomePage(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font="Helvetica 44")
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14), text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')


        dropDown.bind("<<ComboboxSelected>>", lambda _ : master.callback(dropDown.get()))



class AOO_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14), text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(0)

        dropDown.bind("<<ComboboxSelected>>", lambda _ : master.callback(dropDown.get()))

        #LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        #PARAMETERS AND ENTRIES FOR THEM
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

        #VALUES -> replace '0' with stored values (from the file)

        self.value1= Label(self, text='0') #LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2= Label(self, text='0')#URL
        self.value2.place(relx=0.8, rely=0.56)
        self.value3= Label(self, text='0')#ATR AMP
        self.value3.place(relx=0.8, rely=0.62)
        self.value4= Label(self, text='0')#ATR PW
        self.value4.place(relx=0.8, rely=0.68)
        self.value5= Label(self, text='0')#ARP
        self.value5.place(relx=0.8, rely=0.74)

        #BUTTON TO STORE VALUES
        storeButton = Button(self, text="Store", command=lambda:self.storeValues(master, entry1.get(),entry2.get(),entry3.get(),entry4.get(),entry5.get()))
        storeButton.place(relx=0.8, rely=0.8)

        #button to connect
        connectButton = Button(self, text="Connect")
        connectButton.place(relx=0.9, rely=0.8)



    def storeValues(self, master, e1, e2, e3, e4, e5):

        #STORE NEW ENTRY VALUES IN TEXT FILE (replace old values)

        #If statements are for when the entry is EMPTY, in which case it is assumed to be 0.
        if e1 != '':
            self.value1.config(text=e1)
        else:
            self.value1.config(text='0')

        if e2 != '':
            self.value2.config(text=e2)
        else:
            self.value2.config(text='0')

        if e3 != '':
            self.value3.config(text=e3)
        else:
            self.value3.config(text='0')

        if e4 != '':
            self.value4.config(text=e4)
        else:
            self.value4.config(text='0')

        if e5 != '':
            self.value5.config(text=e5)
        else:
            self.value5.config(text='0')



class VOO_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14), text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(1)

        dropDown.bind("<<ComboboxSelected>>", lambda _ : master.callback(dropDown.get()))

        #LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        #PARAMETERS AND ENTRIES FOR THEM
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

        #VALUES -> replace '0's with stored values (in the file)
        self.value1= Label(self, text='0') #LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2= Label(self, text='0')#URL
        self.value2.place(relx=0.8, rely=0.56)
        self.value3= Label(self, text='0')#VENT AMP
        self.value3.place(relx=0.8, rely=0.62)
        self.value4= Label(self, text='0')#VENT PW
        self.value4.place(relx=0.8, rely=0.68)
        self.value5= Label(self, text='0')#VRP
        self.value5.place(relx=0.8, rely=0.74)

        #button to store values
        storeButton = Button(self, text="Store", command=lambda:self.storeValues(master, entry1.get(),entry2.get(),entry3.get(),entry4.get(),entry5.get()))
        storeButton.place(relx=0.8, rely=0.8)
        #button to connect
        connectButton = Button(self, text="Connect")
        connectButton.place(relx=0.9, rely=0.8)


    def storeValues(self, master, e1, e2, e3, e4, e5):
        #Labels = last saved entry values (if first time, then all = 0)
        #When saved, store the entry values in text file.
        
        #If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
        else:
            self.value1.config(text='0')

        if e2 != '':
            self.value2.config(text=e2)
        else:
            self.value2.config(text='0')

        if e3 != '':
            self.value3.config(text=e3)
        else:
            self.value3.config(text='0')

        if e4 != '':
            self.value4.config(text=e4)
        else:
            self.value4.config(text='0')

        if e5 != '':
            self.value5.config(text=e5)
        else:
            self.value5.config(text='0')

class AAI_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14), text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(2)

        dropDown.bind("<<ComboboxSelected>>", lambda _ : master.callback(dropDown.get()))

        #LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        #PARAMETERS AND ENTRIES FOR THEM
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

        #VALUES -> replace '0's with stored values (in the file)
        self.value1= Label(self, text='0') #LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2= Label(self, text='0')#URL
        self.value2.place(relx=0.8, rely=0.56)
        self.value3= Label(self, text='0')#ATR AMP
        self.value3.place(relx=0.8, rely=0.62)
        self.value4= Label(self, text='0')#ATR PW
        self.value4.place(relx=0.8, rely=0.68)
        self.value5= Label(self, text='0')#ARP
        self.value5.place(relx=0.8, rely=0.74)
        

        #button to store values
        storeButton = Button(self, text="Store", command=lambda:self.storeValues(master, entry1.get(),entry2.get(),entry3.get(),entry4.get(),entry5.get()))
        storeButton.place(relx=0.8, rely=0.8)
        #button to connect
        connectButton = Button(self, text="Connect")
        connectButton.place(relx=0.9, rely=0.8)


    def storeValues(self, master, e1, e2, e3, e4, e5):
        #Labels = last saved entry values (if first time, then all = 0)
        #When saved, store the entry values in text file.
        
        #If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
        else:
            self.value1.config(text='0')

        if e2 != '':
            self.value2.config(text=e2)
        else:
            self.value2.config(text='0')

        if e3 != '':
            self.value3.config(text=e3)
        else:
            self.value3.config(text='0')

        if e4 != '':
            self.value4.config(text=e4)
        else:
            self.value4.config(text='0')

        if e5 != '':
            self.value5.config(text=e5)
        else:
            self.value5.config(text='0')

class VVI_Mode(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.config(width='800', height='600')

        welcome = Label(self, text="Programmable Parameters", font=("Helvetica", 44))
        welcome.place(relx=0.5, rely=0.1, anchor='center')

        welcome_message = Label(self, font=("Helvetica", 14), text="Please select a mode from the dropdown menu below to set its programmable parameters.")
        welcome_message.place(relx=0.5, rely=0.2, anchor='center')

        dropDown = ttk.Combobox(self, values=["AOO","VOO","AAI","VVI"], state="readonly")
        dropDown.place(relx=0.5, rely=0.3, anchor='center')
        dropDown.current(3)

        dropDown.bind("<<ComboboxSelected>>", lambda _ : master.callback(dropDown.get()))

        parameters = Label(self, text='Parameters')

        #LABELS
        parameters = Label(self, text='Parameters:', font='Helvetica 12 bold')
        parameters.place(relx=0.2, rely=0.4)

        values = Label(self, text='Values:', font='Helvetica 12 bold')
        values.place(relx=0.8, rely=0.4)

        #PARAMETERS AND ENTRIES FOR THEM
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


         #VALUES -> replace '0's with stored values (in the file)
        self.value1= Label(self, text='0') #LRL
        self.value1.place(relx=0.8, rely=0.5)
        self.value2= Label(self, text='0')#URL
        self.value2.place(relx=0.8, rely=0.56)
        self.value3= Label(self, text='0')#VENT AMP
        self.value3.place(relx=0.8, rely=0.62)
        self.value4= Label(self, text='0')#VENT PW
        self.value4.place(relx=0.8, rely=0.68)
        self.value5= Label(self, text='0')#VRP
        self.value5.place(relx=0.8, rely=0.74)
        

        #button to store values
        storeButton = Button(self, text="Store", command=lambda:self.storeValues(master, entry1.get(),entry2.get(),entry3.get(),entry4.get(),entry5.get()))
        storeButton.place(relx=0.8, rely=0.8)
        #button to connect
        connectButton = Button(self, text="Connect")
        connectButton.place(relx=0.9, rely=0.8)


    def storeValues(self, master, e1, e2, e3, e4, e5):
        #Labels = last saved entry values (if first time, then all = 0)
        #When saved, store the entry values in text file.
        
        #If the entry is EMPTY, then it is assumed 0.
        if e1 != '':
            self.value1.config(text=e1)
        else:
            self.value1.config(text='0')

        if e2 != '':
            self.value2.config(text=e2)
        else:
            self.value2.config(text='0')

        if e3 != '':
            self.value3.config(text=e3)
        else:
            self.value3.config(text='0')

        if e4 != '':
            self.value4.config(text=e4)
        else:
            self.value4.config(text='0')

        if e5 != '':
            self.value5.config(text=e5)
        else:
            self.value5.config(text='0')



dcm = DCM()
dcm.mainloop()