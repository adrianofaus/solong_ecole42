![so_longm](https://user-images.githubusercontent.com/63206471/172677363-1a38377a-bf3c-4cd8-95f2-1b16b2fb2dfe.png)

# So_long a 2D Game

* [Introduction](#introduction)
* [Notion](#notion-link)
* [The Project](#the-project)

## Introduction
This project is a small 2D game with minilibx. I have learned about textures, sprites and tiles.

## Skills that I have improved
* Graphics
* Imperative programming

## The project
The program receives a map with .ber extension

_Sample map_<br>
1111111111111111<br>
1E00000A00000AC1<br>
1010010100100001<br>
1010010010101011<br>
1P000A000CA0C001<br>
1111111111111111

_Caption_
* 0 for an empty space
* 1 for a wall
* C for a collectible
* E for a map exit
* P for the player's starting position
* A for adversary

The game is rendered based on a map with these configuration with the help of Minilibx that provides tools that put tiles in the windows at CPU time.

_Rules of the game_
* The player can only be moved by `WASD`
* The player cannot move into walls
* The game ends if all items were collected
* There is a movement counter on the top left side of the screen
* If the player touches an enemy he dies and the game ends

### What are my thoughts about the project?
The biggest challange in this project is learn how to use the Minilibx. This is because, the concept of events and how to handle these events where quite new for me. I had already learned how to deal with callback functions on Libft but I had not truly applied the concepts before.
I didn't have any difficult dealing with the base for the game because projects that came before this one, were enough to provide me a solid control about my library. 
Of course that I had to deal with a lot of coding in a small range of time and because of this I couldn't apply all my ideas for the game.


### Follow these steps to run the project

```
* This project only runs on Linux
* run sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
* run make or make bonus
* If you are using WSL2 you must have Xming installed and then:
  * Click Multiple windows and go to the next page
  * Click Start no client and go to the next page
  * Make sure that the No Access Control box is ticked and go to the next page
  * Click Save configuration and then Finish
  * Run export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0
  * Run xeyes and check if a window appears
* Inside the maps folder there are maps that can be played
* For instance, run ./so_long ./maps/pdf1.ber
```

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

