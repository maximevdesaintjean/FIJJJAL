# PID
The PID is difficult to calculate, so we have consulte a [raspberry site](https://projects.raspberrypi.org/en/projects/robotPID/5) to understand how make a simple PID. </br>
The principe is simple, we need to see the present, futur and past error to make the proportional, integrator and derivator action.

## Calcul
The regulation is based on a set-point and a mesured value. </br>
With both elements, we can calculate the error like `error = setPoint - mesuredValue`. </br>

We can create four differents regulators:
1) P
2) PI
3) PD
4) PID

### Regulator P
This regulator is based only on the present error. </br> So, the action on the systeme is calculate like that : `action = Kp * error` where Kp is egale to the proportional factor.

### Regulator PI
The PI regulator use the proportional and integrator actions. </br> The integrator action use the futur error. Like we can not predict the futur, we sum all of the previous errors and divided it by the error's number, we take the mean. </br>
We have `action = Kp * error + Ki * sumOfError` where Ki is egale to the integrator factor.

### Regulator PD


### Regulator PID


## ESC mapping