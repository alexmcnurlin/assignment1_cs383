# CS383 Assignment 1

## Download the code
  1. Install git from `https://git-scm.com/downloads`
  2. Open a terminal
    - In Windows, use the program 'Git Bash'.
  3. Clone the repository by running the command `https://github.com/alexmcnurlin/assignment1_cs383 mcnu5088_assignment1`

## Run the program:
  - Run the included executable 
    - For Windows: `mcnu5088_assignment1\executable\assignment1_windows.exe`
    - For Linux: `mcnu5088_assignment1/executable/assignment1_linux`
  - or compile the program manually (see below)
  
## Compile:
  1. Install the latest version of Qt Creator and Qt 5.10.0 from `https://www.qt.io/download-qt-installer`.
  2. Launch Qt Creator, click "Open Project" and choose the file `assignment1\assignment1.pro`.
  3. Compile the project by clicking the green play button or pressing `ctrl+r`.

Known Bugs:
  - Clicking on the game window will cause you to lose control of the paddle.
  - If the ball hits the paddle and a wall at the same time, it may get stuck in the wall.
  - If the ball moves to quickly, it may clip through the paddles.
