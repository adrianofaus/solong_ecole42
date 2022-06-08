![so_longm](https://user-images.githubusercontent.com/63206471/172677363-1a38377a-bf3c-4cd8-95f2-1b16b2fb2dfe.png)

# So_long A 2D Game

* [Introduction](#introduction)
* [Notion](#notion-link)
* [The Project](#the-project)

## Introduction
So_long is a project that introduced me the idea that could I transform my code in a Living Thing. This project was moderate difficulty. Once I had already mastered the use of my Library Forty Two I could play with it and create the base for my own game. The support library to handle graphics that I used is the Minilibx and learn how to use it was the biggest challange along the project.

## Skills that I have improved

## The project


### Follow these steps to run the project
* This project only runs on Linux
* run `sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev`
* run `make` or `make bonus`
* If you are using WSL2 you must have Xming installed and then:
  * Click Multiple windows and go to the next page
  * Click Start no client and go to the next page
  * Make sure that the No Access Control box is ticked and go to the next page
  * Click Save configuration and then Finish
  * Run `export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0`
  * Run xeyes and check if a window appears
* Inside the `maps` folder there are maps that can be played
* For instance, run `./so_long ./maps/pdf1.ber`

### How to play it?
The objective is collect all items avoiding the enemys.

If you bump into flames you going to get toasted

![Dead](https://user-images.githubusercontent.com/63206471/172672626-9e0708a3-f4d9-4f2b-b329-ea8eb1c4929f.gif)

You can move using the keyboard

W => Move up<br>
S => Move down<br>
A => Move left<br>
D => Move right

Once all items were collected a door will be open an you can head into it.

![Alive](https://user-images.githubusercontent.com/63206471/172672691-4d6fa51f-82c8-4942-8f69-26a68d3d618e.gif)

