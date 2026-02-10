# Procedural-Horse-Race

Feel free to 'play' this procedural horse race @ https://onlinegdb.com/-R-gttciJD
Press run in the top menu bar and press menu to advance the race.

Each horse's turn generates a random number 1-100 - if even the horse advances 1 spot in the race, if odd it stays stationary for 1 turn. If the number is 42 the horse advances 3 spaces, for fun.

Code works as follows:
```
while there is not a winner of the race:
  wait for input from user to iterate
  for each horse:
    generate a number 1-100
    if 42:
      advance 3
    if even
      advance 1
  if horse wins:
    break the loop, declare winner
```
