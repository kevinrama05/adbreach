import curses
from adbreach_funct import *

def main(stdscr):
    stdscr.clear()
    stdscr.refresh()

    stdscr.addstr(50, 20, "Welcome to ADBreach >_")
    
d = get_x_y()
print(f"This is the output adb shel wm size: {d}")
    