# Ultrasound sensor
The ultrasound sensor, HCSR04, is a device wich use ultrasound to determine the distance of an object. </br>
It allows to detect some objects or/and a wall when the drone is flying. </br>
It also offer a good range of detection without contatc.

## features
The modules includes ultrasonic transmitters, receiver and control circuit. </br>
![Electric Parameter](C:\Users\maxim\OneDrive\Documents\cours\ECAM\Projet_drone\dossier\electric_parameter.PNG)*Electric Parameter*

## Wire connecting
* 5V Supply
* Trigger Pulse Input 
* Echo Pulse Output
* 0V Ground 

## Timing diagram
The Timing diagram is shown below. You only need to supply a short 10uS pulse to the trigger input to start the ranging, </br>
and then the module will send out an 8 cycle burst of ultrasound at 40 kHz and raise its echo. The Echo is a distance </br>
object that is pulse width and the range in proportion. You can calculate the range through the time interval between 
sending trigger signal and receiving echo signal. </br>
*  Formula : 

