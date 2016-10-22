# Lab2_TeamThimble
*This is Lab 2 website for EE209 Robotics.* 

Group Members: Ryan Hamidi, Xuerui Yan, Alia Nasrallah, Jiahui Li


<b>Pictures of Jam Band System Prototype below.</b>

Top view:

<img width="551" alt="systemtopview" src="https://cloud.githubusercontent.com/assets/22850278/19546970/d3f6df52-9648-11e6-9574-9cee3a052e3f.png">


Side view:

<img width="344" alt="systemsideview" src="https://cloud.githubusercontent.com/assets/22850278/19547109/18b62b7e-964a-11e6-8418-fd4064a4580c.png">



<b>Descriptions of the construction and operation:</b>

In our Jam Band, three drums will be played in our system. We name them as KEY2 and KEY3. We use two micro-controllers to control two motors and two sensors in order to play drums with our mechanical linkages, which in this case are replicating fingers. The two sensors that we use are an ultrasonic sensor and a pressure sensor; specifically a Force Sensitive Resistor (FSR). Basically, codes that control sensors and motors in Arduino are compiled into the micro-controllers. Once the codes are successfully compiled, based on the pictures shown above, the moter on the linear motion control stands will rotate the linkages that will drive the sliding cart move to a starting point on the track, and the ultrasonic sesnor on the cart will begin to sense the distance between itself and the surface of the drum. Once the distance that is sensed by the ultrasonic sensor is matched with what the user indicates on a web-interface, the hammer (or mallet) on the track will beat the drum. Meanwhile, the pressure sensor which is placed on the surface of the drum would sense that hit and the microcontroller will control the hammer to move back to its original place. In this way, our system finishes one entire cycle of operations between the two microcontrollers. We can use the web server to begin another motion to play a different key, or the same key again. For visualization of how our system works, please watch the videos below.



<b>Demonstration Video:</b>
Three videos for our system.

1. https://youtu.be/vxaB1NvaTI8

2. https://youtu.be/EJ_i2grq3rw

3. https://youtu.be/PvcinqmIPOQ





<b>Code Gallery:</b>

Linked to Our Github: 

Master MCU Codes:
https://github.com/jacklijiahui/Lab2_TeamThimble-/blob/master/Code/Lab2_finalMaster.ino

Slaver MCU Codes:
https://github.com/jacklijiahui/Lab2_TeamThimble-/blob/master/Code/Lab2_finalSlave.ino




<b>Wiring Schematics:</b>

Block Diagram of our System:

![system diagram](https://cloud.githubusercontent.com/assets/22620839/19614219/a3195a3a-97a7-11e6-882d-db1d3bd70dc8.jpeg)

<b>Wiring Schematic of our System</b>:

![wiring](https://cloud.githubusercontent.com/assets/22620839/19615492/ac345c7a-97b4-11e6-895d-9801cfa30037.jpeg)






<b>Bill of Materials</b>, Click and Download:
[Bill of Materials.xlsx](https://github.com/jacklijiahui/Lab2_TeamThimble-/files/545482/Bill.of.Materials.xlsx)







