# Lab2_TeamThimble
*This is Lab 2 website for EE209 Robotics.* 

Group Members: Ryan Hamidi, Xuerui Yan, Alia Nasrallah, Jiahui Li

*Requirement of team report on Lab 2 for you guys convenience, feel free to add anything that you think which need to be here*: <b>As a team, you will create a webpage documenting and demonstrating your band. This should contain everything necessary to recreate your system. Be sure to include your code, wiring schematics, and a bill of materials, as well as pictures, videos, and text descriptions of the construction and operation.</b>


<b>Pictures of Jam Band Prototype below.</b>

Top view:

<img width="551" alt="systemtopview" src="https://cloud.githubusercontent.com/assets/22850278/19546970/d3f6df52-9648-11e6-9574-9cee3a052e3f.png">


Side view:

<img width="344" alt="systemsideview" src="https://cloud.githubusercontent.com/assets/22850278/19547109/18b62b7e-964a-11e6-8418-fd4064a4580c.png">


<b>Descriptions of the construction and operation:</b>

In our Jam Band, three drums will be played in our system. We name them as KEY1, KEY2 and KEY3. We mainly use two micro-controllers to control two motors and two sensors in order to play drums with our mechanical linkages. The two sensors that we use are ultrasonic sensor and touch sensor. Basically, codes that control sensors and motors in Arduino are compiled into the micro-controllers. Once the codes are successfully compiled, based on the pictures shown above, the moter on the main control desk will rotate the linkages that will drive the sliding cart move to the original point on the track, and the ultrasonic sesnor on the cart will begin to sense the distance with the surface of the drum. Once the distance that is sensed by the ultrasonic sensor is matched with what we set in the codes, the hammer on the track will beat the drum. Meanwhile, the touch sensor which is placed on the surface of the drum would sense that beat and the microcontroller will control the hammer to move back to its original place. In this way, our system finishs one entire interoperation motion. We can use the web server to begin another motion to play the KEYS. For more straightforward way to show how our system works, please watch the video below.


<b>Demonstration Video:</b>









<b>Code Gallery:</b>

Linked to Our Github: https://github.com/jacklijiahui/Lab2_TeamThimble-/blob/master/Code/Lab2Code.ino





<b>Wiring Schematics:</b>







<b>Bill of Materials</b>, Click and Download:
[Bill of Materials.xlsx](https://github.com/jacklijiahui/Lab2_TeamThimble-/files/543081/Bill.of.Materials.xlsx)






