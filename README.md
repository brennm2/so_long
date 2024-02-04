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
<h4>4º Step - Download the files</h4>

Now you have to choose a map. If you have only compiled so_long base, then you should choose the map "map_tester.ber"
