# Ultrasound sensor
The ultrasound sensor, HCSR04, is a device wich use ultrasound to determine the distance of an object. </br>
It allows to detect some objects or/and a wall when the drone is flying. </br>
It also offer a good range of detection without contatc.

## features
The modules includes ultrasonic transmitters, receiver and control circuit. </br>
* Working Voltage 		: DC 5V
* Working Current 		: 15 mA
* Working Frequency 	: 40 Hz
* Max Range 			: 4m
* Min Range 			: 2cm
* MeasuringAngle 		: 15 degree
* Trigger Input Signal 	: 10us TTL pulse


## Wire connecting
* 5V Supply
* Trigger Pulse Input 
* Echo Pulse Output
* 0V Ground 

## Timing diagram
The Timing diagram is shown below. You only need to supply a short 10µs pulse to the trigger input to start the ranging, </br>
and then the module will send out an 8 cycle burst of ultrasound at 40 kHz and raise its echo. The Echo is a distance </br>
object that is pulse width and the range in proportion. You can calculate the range through the time interval between 
sending trigger signal and receiving echo signal. </br>
*  Formula : </br>
`* v= 340 m/s = 0.034 cm/µs` </br>
`* t= d/v = 10 / 0.034 = 294 µs` </br>
`* d= t*0.034/2` </br>

![timing diagram](https://www.electrodragon.com/w/images/8/84/Frequency..jpg)
## Attention 
If you are using a board wich support only 3.3V (like the raspberry Pi), you have to use two resistors.</br>
* Formula : </br>
`* 3.3/5 = R1/(R1+R2)`
