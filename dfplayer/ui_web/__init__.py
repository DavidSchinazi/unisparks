import os
import sys
import time
import base64
import gevent
import logging
import StringIO

from flask import Flask,request,render_template,make_response,abort
from flask.ext.socketio import SocketIO, emit

from ..util import ExceptionLogger, catch_all, PROJECT_DIR, PACKAGE_DIR

STREAM_FRAMES = False
STREAM_FRAMES = True

app = Flask(__name__)
socketio = SocketIO(app)
player = None

def workthread():
    while True:
        with ExceptionLogger():
            gevent.sleep(0.5 if not STREAM_FRAMES else 0.1)
            socketio.emit('player_state', {
                    'status': player.status,
                    'volume': player.volume,
                    'elapsed': player.elapsed,
                    'clipName': player.clip_name
                }, namespace="/player" )

            if STREAM_FRAMES and player.status == 'playing':
                img = player.frame()
                outbuf = StringIO.StringIO()
                img.save(outbuf,'JPEG')
                imgdata = base64.b64encode(outbuf.getvalue())
                outbuf.close()
                socketio.emit('frame', {'data':imgdata}, namespace="/player" )


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/currframe')
def currframe():
    pass

@socketio.on('play', namespace="/player")
@catch_all
def play(msg):
    print "Play"
    player.play( msg['clipIdx'] )

@socketio.on('pause', namespace="/player")
@catch_all
def pause():
    print "Pause"
    player.pause()    

@socketio.on('resume', namespace="/player")
@catch_all
def resume():
    print "Resume"
    player.resume()

@socketio.on('next', namespace="/player")
@catch_all
def next():
    print "Next"
    player.next()


@socketio.on('prev', namespace="/player")
@catch_all
def prev():
    print "Prev"
    player.prev()


@socketio.on('volume', namespace="/player")
@catch_all
def volume(msg):
    player.volume = msg['volume']

def run(with_player,host,port):
    global player
    player = with_player        
    gevent.spawn(workthread)
    print "Listening on %s:%d" % (host,port)    
    socketio.run(app,host=host, port=port) 
