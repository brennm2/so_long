<div align="center">
  <img src="https://i.imgur.com/kUP07l3.gif">
</div>

<div align="center">
  <h1>What is this all about?</h1>
</div>
<div align="center">
<p>Basically, this project is about making a game from scratch, from the logic of movement to the "graphics engine" of the game.
<br>
<br>
You have to learn how to work with textures, how to position them on the screen, and how to keep your projectorganized and clean. Following the rules of 42 School</p>
 </div>
 
<br>
<div align="center">
  <h1>What game is this?</h1>
</div>

<div align="center">
<p>My game follows the theme of the PAYDAY franchise. Where the "story" of the game is to steal things without using violence (basically, without using guns).

But watch your step! Some Cloakers are escorting the place... But don't worry, your friend Bain will guide you through the heist.</p>
</div>
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
so_long maps/map_tester.ber
```
or
```bash
so_long_bonus maps/map_aftershock.ber
```
<br>
<h4>5º Step - Winning the game</h4>

- You move your character with the arrow keys or WASD
- You must avoid the Cloakers, they move randomly only after the player moves, and ONLY IF the player moves<br> (no walking on the wall to escape from enemies ;) )
- You need to collect ALL the money bags in order to escape the heist
- An additional objective is to try to finish the map with as little movement as possible.<br>
This won't influence anything, just another way to improve your performance!


/// * GAME RUNNING HERE * ////

<div align="center">
  <h1>Considerations and Explanations</h1>
</div>

<div align="center">
<p>One idea I had was to have dialogues in the game. Texts will appear in the shell depending on what happens in the game.<br><br>
In total, the game has 4 dialogue scenarios, and each scenario has 4 different sets of dialogue to choose from at random.<br>
In short, there are 16 different dialogues! Four of them only happen if you're on Death Wish difficulty</p>
<p>I won't show you an example because I want YOU to find out for yourself, can you beat it on this difficulty?<br>
Here are some examples:</p>
<br>
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

