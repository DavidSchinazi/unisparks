import os
import sys
import PIL

from gevent import sleep
from Tkinter import Tk,Frame,Canvas
from PIL import Image,ImageTk

WIN_WIDTH = 1440
WIN_HEIGHT = 900
FPS = 30

class PlayerApp(Frame):
    def __init__(self, root, player):
        Frame.__init__(self, root)
        self.root = root
        self.pack()
        canvas = Canvas(root, width=WIN_WIDTH, height=WIN_HEIGHT, 
            borderwidth=0, background="black")
        canvas.pack()
        self.img = ImageTk.PhotoImage('RGB',(WIN_WIDTH,WIN_HEIGHT))
        imgid = canvas.create_image(WIN_WIDTH/2,WIN_HEIGHT/2,image=self.img)

        self.player = player
        #self.root.bind("<Enter>", lambda e: player.resume() )
        self.root.after(1000/FPS, lambda: self.update() )


    def update(self):
        img = self.player.frame()
        if img:
            ftw_size = (WIN_WIDTH,int(img.size[1]*(float(WIN_WIDTH/img.size[0]))))
            self.img.paste(img.resize(ftw_size,Image.NEAREST))
        self.root.after(1000/FPS, lambda: self.update() )

def run(player):
    root = Tk()
    root.geometry('%dx%d' % (WIN_WIDTH,WIN_HEIGHT))
    root.attributes("-topmost", True)
        
    app = PlayerApp(root,player)
    
    #root.mainloop()
    while True:
        root.update()
        sleep(1.0/FPS)

