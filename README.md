# Scrabble

## *Rundown of the game*
### **Menu with options:**
  1. Start game
  2. Settings
  3. Add new word
  4. Achievements
  5. Exit
  
  *Choosing an option is as simple as entering the number preceding it into the console.*
  
### **The core game loop**
  Upon entering '1' into the console the game starts, showing the first round. There are M amount of rounds. 
  In each round the user is presented with N amount of letters (both M and N are predetermined by the user, with default value of 10).
  The goal is to compose a word with the letters given and each letter in the word gives the user +1 point
  (*house - 5 points, cat - 3 points etc.*)
  The input from the user, however, must be an actual word, so there's a validity check (search through a dictionary consisting of 250 000+ words).
  At the end of the last round the user is shown his final score and directed back to the main menu.
  
### **Settings**
  There are three predefined modes (Easy, Normal, Hard) and an option for custom settings which the user can adjust to his preference.
  
### **Add new word**
  The user can add a new word into the dictionary file. There are checks ensuring the word consists only of letters and that it isn't already in the dictionary.
  
### **Achievements**
  Shows the user's highscore and the longest word he has composed.
  
  
