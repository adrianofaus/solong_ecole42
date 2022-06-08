# So_long

* [Introduction](#introduction)
* [Notion](#notion-link)
* [The Project](#the-project)

## Skills that I have improved

## Introduction

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

W => Move up
S => Move down
A => Move left
D => Move right

Once all items were collected a door will be open an you can head into it.

![Alive](https://user-images.githubusercontent.com/63206471/172672691-4d6fa51f-82c8-4942-8f69-26a68d3d618e.gif)

