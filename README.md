# FireFighter-Car

THE IDEA:

We thought it would be a really funny to create project that might also work as a real thing if we adjust and improve the mechanics sometime in the future. So we conceived the model of a simple fire alarm, using flame sensors and the analogic values they are generating to discover the precise location of the fire. We added to that simple fire alarm system an extinguish mechanism that helps us put down the fire based on the analogic values of the sensors.


PURPOSE:

In the simplest terms, the role of a fire alarm system is to detect fire and alert people around the problematic area. As a bonus, our fire alarm system comes with an extinguish system that puts down the fire using the water from the tank and also the water pump to reach that specific area. 

THE WAY IT WORKS:

1. Detection of flames is achieved using flame sensors (front side: middle, left, right, left side, right side) mounted on the car.

2. When the car is too close to the flame, the sensor on the middle (front) is read (function: AnalogRead().). The car goes to the back so as not to burn out. 

3. Using the servo motor (void porneste_servo()) which manages the water hose and water pump which are located in a container above the cars, the effective action begins putting out the fire once the car has reached a favorable distance from the flame (void put_off_fire()).

4. As long as no fire is detected, the vehicle keeps moving until it meets a fire source using the sensor data.



HARDWARE COMPONENTS:


-> 1 Arduino Mega256
-> 3 plexiglass pads (26cm x 25cm x0.2cm)
-> 4 DC motors ( 6V)
-> H-bridge
-> 5 flame sensors
-> 1 water pump
-> 1 servo-motor
-> 1 stepper
-> jumpers
-> power relay
-> 9V accumulator
