"""
Learn about graphics in Python using tkinter

"""

from tkinter import *

def main():
    # Create a window
    window = Tk()
    window.title("Graphics Demo")

    # Create a canvas
    canvas = Canvas(window, bg = "white", width = 200, height = 100)
    canvas.pack()

    # Draw a line
    canvas.create_line(0, 0, 200, 100)
    canvas.create_line(0, 100, 200, 0, fill = "red", dash = (4, 4))

    # # Draw a rectangle
    # canvas.create_rectangle(50, 25, 150, 75, fill = "blue")

    # # Draw an oval
    # canvas.create_oval(50, 25, 150, 75, fill = "green")

    # # Draw an arc
    # canvas.create_arc(50, 25, 150, 75, start = 0, extent = 180, fill = "red")

    # # Draw a polygon
    # canvas.create_polygon(75, 25, 100, 50, 125, 25, 100, 75, fill = "yellow")

    # Display the window
    window.mainloop()

main()