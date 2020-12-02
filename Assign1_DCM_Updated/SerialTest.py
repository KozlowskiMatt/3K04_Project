import serial
import struct
from time import sleep
data = b"\x16\x10\x00" + b"\x00"*30 #send parameters back, NO egram

with serial.Serial(port="COM5", baudrate=115200) as ser:  
	ser.write(data)
	data_r = ser.read(30)

	mode = data_r[0]
	lower_rate_limit = data_r[1]
	upper_rate_limit = data_r[2]
	max_sensor_rate = data_r[3]

	vent_amplitude = struct.unpack("f", data_r[4:8])[0]
	vent_pulse_width = struct.unpack("f", data_r[8:12])[0]
	VRP = struct.unpack("H", data_r[12:14])[0]

	atr_amplitude = struct.unpack("f", data_r[14:18])[0]
	atr_pulse_width = struct.unpack("f", data_r[18:22])[0]
	ARP = struct.unpack("H", data_r[22:24])[0]

	activity_threshold = data_r[24]
	reaction_time = data_r[25]
	response_factor = data_r[26]
	recovery_time = data_r[27]
	AV_Delay = struct.unpack("H",data_r[28:30])[0]

	print(mode)
	print(lower_rate_limit)
	print(upper_rate_limit)
	print(max_sensor_rate)
	print(vent_amplitude)
	print(vent_pulse_width)
	print(VRP)
	print(atr_amplitude)
	print(atr_pulse_width)
	print(ARP)
	print(activity_threshold)
	print(reaction_time)
	print(response_factor)
	print(recovery_time)
	print(AV_Delay)
	ser.close()
