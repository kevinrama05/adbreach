import curses
import subprocess
import uiautomator2 as u2

def get_x_y():
    
    x_and_y = subprocess.run("adb shell wm size | awk '{print $3}'",
                             capture_output=True,
                             text=True)
    x, y = x_and_y.split("x")
    return x_and_y.stdout

def move_cursor(stdscr, x, y, max_x, max_y):
    while True:
        key = stdscr.getch()
        if key == curses.KEY_LEFT:
            if x >= 5:
                subprocess.run(f"adb shell input swipe {x} {y} {x-5} {y} 500",
                               shell=True,
                               stdout=subprocess.DEVNULL,
                               stderr=subprocess.DEVNULL)
                x -= 5
            elif x < 5 and x != 0:
                subprocess.run(f"adb shell input swipe {x} {y} 0 {y} 500",
                               shell=True,
                               stdout=subprocess.DEVNULL,
                               stderr=subprocess.DEVNULL)
                x = 0
            elif x == 0:
                pass
        elif key == curses.KEY_RIGHT:
            if x <= max_x - 5:
                subprocess.run(f"adb shell input swipe {x} {y} {x+5} {y} 500",
                               shell=True,
                               stdout=subprocess.DEVNULL,
                               stderr=subprocess.DEVNULL)
                x += 5
            elif x > max_x - 5 and x != max_x:
                subprocess.run(f"adb shell input swipe {x} {y} {max_x} {y} 500",
                               shell=True,
                               stdout=subprocess.DEVNULL,
                               stderr=subprocess.DEVNULL)
                x = max_x
            elif x == max_x:
                pass
        elif key == curses.KEY_UP:
            if y >= 5:
                subprocess.run(f"adb shell input swipe {x} {y} {x} {y-5} 500",
                               shell=True,
                               stdout=subprocess.DEVNULL,
                               stderr=subprocess.DEVNULL)
                y -= 5
            elif y < 5 and y != 0:
                subprocess.run(f"adb shell input swipe {x} {y} {x} 0 500",
                               shell=True,
                               stdout=subprocess.DEVNULL,
                               stderr=subprocess.DEVNULL)
                y == max_y
            elif y == 0:
                pass
        elif key == curses.KEY_DOWN:
            if y <= max_ - 5:
                subprocess.run(f"adb shell input swipe {x} {y} {x} {y+5} 500",
                               shell=True,
                               stdout=subprocess.DEVNULL,
                               stderr=subprocess.DEVNULL)
                y += 5
            elif y > max_y - 5 and y != max_y:
                subprocess.run(f"adb shell input swipe {x} {y} {x} {max_y} 500",
                               shell=True,
                               stdout=subprocess.DEVNULL,
                               stderr=subprocess.DEVNULL)
                y = max_y
            elif y == max_y:
                pass
        elif key in (10, 13, curses.KEY_ENTER):
            d = u2.connect()
            d.click(x, y)
            focused = d(focused=True)
            if focused.info["className"] == "android.widget.EditText":
                input_tap = True
            else:
                input_tap = False
            return x, y, input_tap
        