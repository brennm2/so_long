<div align="center">
  <img src="https://i.imgur.com/kUP07l3.gif">
</div>

<div align="center">
  <h1>What is this all about?</h1>
</div>

<p>Basically, this project is about making a game from scratch, from the logic of movement to the "graphics engine" of the game.
<br>
<br>
You have to learn how to work with textures, how to position them on the screen, and how to keep your projectorganized and clean. Following the rules of 42 School</p>

 
<br>
<div align="center">
  <h1>What game is this?</h1>
</div>

<p>My game follows the theme of the PAYDAY franchise. Where the "story" of my game is to steal things without using violence (basically, without using guns).

But watch your step! Some Cloakers are escorting the place... But don't worry, your friend Bain will guide you through the heist.</p>
<br>
<div align="center">
  <img src="https://i.imgur.com/KkOK0JB.png">
</div>
<br>

<div align="center">
  <h1>How can I play it?</h1>
</div>
<div align="center">
<p>I'm glad you asked! The process is very simple.</p>
</div>

<br>
<h4>1º Step - Download the files:</h4>

```bash
git clone https://github.com/brennm2/so_long.git
```
<br>
<h4>2º Step - MinilibX and dependencies:</h4>

- MinilibX download

```bash
cd so_long
make update
```

- MinilibX dependencies

```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

<br>
<h4>3º Step - Compiling the game</h4>

- If you want to play the base game:
```bash
make
```

- If you want to play the bonus game (recommended):
```bash
make bonus
```

<br>
<h4>4º Step - Playing the game!</h4>

Now you have to choose a map. If you have only compiled so_long base, then you should choose the map `"map_tester.ber"`
<br>
<br>
But if you've compiled the bonus game, then you can choose from 4 maps:
- map_syntax_error.ber
- map_aftershock.ber
- mapdw_jewelry_store.ber
- mapdw_firestarter.ber

Now… the game has 2 “difficulties”, `Normal` and `Death Wish`<br>
Choosing the map with the initial `mapdw_` will start the map with more enemies!<br><br>
Here's how to start the game:

```bash
./so_long maps/map_tester.ber
```
or
```bash
./so_long_bonus maps/map_aftershock.ber
```
<br>
<h4>5º Step - Winning the game</h4>

- You move your character with the arrow keys or WASD
- You must avoid the Cloakers, they move randomly only after the player moves, and ONLY IF the player moves<br> (no walking on the wall to escape from enemies ;) )
- You need to collect ALL the money bags in order to escape the heist
- An additional objective is to try to finish the map with as little movement as possible.<br>
This won't influence anything, just another way to improve your performance!
- If you want to stop playing, just press 'ESC' or close the window with the X button.
<br>



<br>
<div align="center">
  <img src="https://i.imgur.com/iBlK3rW.gif">
</div><br>




<div align="center">
  <h1>Considerations and Explanations</h1>
</div>

<div align="center">
<h3>---------------- The Dialogues ----------------</h3>
</div>
<br>
<p>One idea I had was to have dialogues in the game. Texts will appear in the shell depending on what happens in the game.<br><br>
In total, the game has 4 dialogue scenarios, and each scenario has 4 different sets of dialogue to choose from at random.<br>
In short, there are 16 different dialogues! Four of them only happen if you're on Death Wish difficulty</p>
<p>I won't show you an example because I want YOU to find out for yourself, can you beat it on this difficulty?<br>
Here are some examples:</p>
<br>
<div align="center">
Starting a game:
</p>
<div align="center">
  <img src="https://i.imgur.com/0gwMzac.gif">
</div>
<br>
<br>
<p>Getting caught:</p>
<div align="center">
  <img src="https://i.imgur.com/JFpW2zX.gif">
</div>
<br>
<br>
<p>And, the end of the game:</p>
<div align="center">
  <img src="https://i.imgur.com/OyLdAFl.gif">
</div>
</div>
<br>
<br>
<div align="center">
<h3>---------------- The HUD ----------------</h3>
</div>
<br>
<p>The game's HUD has 2 states, 1 - POLICE ASSAULT and 2 - POINT OF NO RETURN.</p>
<p>The first state indicates that the player has to collect the money bags and shows the total movement.<br>
The second state indicates that the player has collected all the money bags and needs to leave the map.</p>
<p>I had a problem with the HUD, as the map can be completely modular, so the size of the window also changes, and you have to re-calculate to place it in the right pixel. So, depending on the size of the map, the HUD won't be perfectly centered on the screen.</p>
<br>
<br>
<div align="center">
  <img src="https://i.imgur.com/6XXhyzi.gif">
</div>
<br>
<br>
<div align="center">
<h3>---------------- The Map ----------------</h3>
</div>
<br>
<p>The map can be modified, altered or even created in a simple and functional way, as long as it follows these rules:</p>

```bash
- Only have ONE Player (P)
- Only have ONE Exit (E)
- There has to be AT LEAST one Collectible (C)
- It has to be enclosed by Walls (1)
- And it needs to be filled with floors (0)
- You can place enemies (X)
- It has to be rectangular
- The player must find a way to collect all the collectibles and reach the exit
- The map can only use the following characters: 1, 0, E, P, C and X(This will not work if you run the base game)
- The map extension must be ".ber"
```
<br>
<br>
<p>Here's a simple example:</p>

```bash
11111111111
1000E0CX001
1000P00C001
10011111001
1X0CX0X0011
1000C000001
10011111001
100C0000001
1000C000X01
11111111111
```

<div align="center">
<h3>---------------- 42 Rules ----------------</h3>
</div>


