# PID
The PID is difficult to calculate, so we have consulte a [raspberry site](https://projects.raspberrypi.org/en/projects/robotPID/5) to understand how make a simple PID. </br>
The principe is simple, we need to see the present, futur and past error to make the proportional, integrator and derivator actions.

## Why we need this ?
The PID allows to control the motors. We can see the motor like a systeme, when we to move the drone, we control the motion with a set point. Each motor must follow the set point and the PID allows to do that.

## Calcul
The regulation is based on a set-point and a mesured value. </br>
With both elements, we can calculate the error like : `error = setPoint - mesuredValue`. </br>

We can create four differents regulators:
1) P
2) PI
3) PD
4) PID

### Regulator P
This regulator is based only on the present error. </br> So, the action on the systeme is calculate like that : `action = Kp * error` where Kp is equal to the proportional factor.

### Regulator PI
The PI regulator use the proportional and integrator actions. </br> The integrator action use the futur error. Like we can not predict the futur, we sum all of the previous errors and divided it by the error's number, we take the mean. </br>
We have `action = Kp * error + Ki * sumOfError` where Ki is egale to the integrator factor. </br>
Add a integrator action allows to cancel the static error, if we have not a integrator in the system, it's important to add it with the regulator.

### Regulator PD
Now we can see of the futur and the present, we need to see in the past, the derivator action does that. </br>
The output action is calculated like that : `Kp * error + Kd * previousError` where Kd is the derivator factor. </br>
The derivator action allows to increase the system's dynamic. Be careful, to add too much action, can destabilize the system.

### Regulator PID
This regulator is the most completed, we have the three actions. </br>
We can cancel the static error with the integrator, the derivator increase the dynamic and "boost" with the proportional.

## ESC mapping
The ESC mapping is important because the PID can generate the output value different of the ESC input. </br>
So, the principe is simple. We have two bounds: </br>
1) The minimum value to send at the ESC, called *minBound* in the **pid.h**.
2) The maximum value to send at the ESC, called *maxBound* in the **pid.h**.

The both are determinated arbitrarily with tests. </br>

We accept a maximum error (for the moment we accept 10°) and with this error, we calculate the maximum output that the regulator can give. </br>
The mapping estimates that the regulator used is allways the **P**, so the maximum output accepted is : `Kp * errorMax`. We define the maximum output like the maximum bound for the ESC. </br>
Now, we can use a simple formula to determinate the new output : `newOutput = minBound + (output/maxOutput) * maxBound`. </br>
To be sure that the value send by the function is between the maximum and minimum bounds, we check if :
1) The new output is smaller than *minBound*, we send the minimum bound.
2) The new output is greater than *maxBound*, we send the maximum bound.
3) The new output is between both bounds, we send the new output.