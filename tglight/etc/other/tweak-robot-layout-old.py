#!/usr/bin/python3

# Used to tweak the robot layout in a rush.

printPrevious = True

def printLayout(l, num=""):
  s = '{\n  '
  i = 0
  for (x, y) in l:
    for _ in range(2):
      s += '{{{x:.2f}, {y:.2f}}}, '.format(x=x,y=y)
    if i % 4 == 3:
      s += '\n  '
    i += 1
  if i % 4 == 0:
    s = s[:-3]
  s += '\n};'
  s += '\n\n'
  s += '#define LEDNUM{num} {lednum}'.format(num=num, lednum=len(l) * 2)
  print(s)

for head in [False, True]:
  if printPrevious:
    if head:
      print('ROBOT HEAD')
      # Robot head
      previousLayout = [14.30, 1.00, 0.00,14.30, 1.00, 0.00,14.30, 1.14, 0.00,14.30, 1.14, 0.00,14.44, 1.07, 0.00,14.44, 1.07, 0.00,14.44, 1.21, 0.00,14.44, 1.21, 0.00,14.59, 1.00, 0.00,14.59, 1.00, 0.00,14.59, 1.14, 0.00,14.59, 1.14, 0.00,14.73, 1.07, 0.00,14.73, 1.07, 0.00,14.73, 1.21, 0.00,14.73, 1.21, 0.00,14.87, 1.00, 0.00,14.87, 1.00, 0.00,14.87, 1.14, 0.00,14.87, 1.14, 0.00,15.01, 1.07, 0.00,15.01, 1.07, 0.00,15.01, 1.21, 0.00,15.01, 1.21, 0.00,15.16, 1.00, 0.00,15.16, 1.00, 0.00,15.16, 1.14, 0.00,15.16, 1.14, 0.00,15.30, 1.07, 0.00,15.30, 1.07, 0.00,15.30, 1.21, 0.00,15.30, 1.21, 0.00,15.44, 1.00, 0.00,15.44, 1.00, 0.00,15.44, 1.14, 0.00,15.44, 1.14, 0.00,15.59, 1.07, 0.00,15.59, 1.07, 0.00,15.59, 1.21, 0.00,15.59, 1.21, 0.00,15.73, 1.00, 0.00,15.73, 1.00, 0.00,15.73, 1.14, 0.00,15.73, 1.14, 0.00,15.87, 1.07, 0.00,15.87, 1.07, 0.00,15.87, 1.21, 0.00,15.87, 1.21, 0.00,16.01, 1.00, 0.00,16.01, 1.00, 0.00,16.01, 1.14, 0.00,16.01, 1.14, 0.00,16.16, 1.07, 0.00,16.16, 1.07, 0.00,16.16, 1.21, 0.00,16.16, 1.21, 0.00,16.30, 1.00, 0.00,16.30, 1.00, 0.00,16.30, 1.14, 0.00,16.30, 1.14, 0.00,16.44, 1.07, 0.00,16.44, 1.07, 0.00,16.44, 1.21, 0.00,16.44, 1.21, 0.00,16.59, 1.00, 0.00,16.59, 1.00, 0.00,16.59, 1.14, 0.00,16.59, 1.14, 0.00,]
    else:
      print('ROBOT PASSENGER WALL')
      # Robot passenger wall
      previousLayout = [   7.50, 0.00, 0.00,   7.50, 0.00, 0.00,   7.50, 0.25, 0.00,   7.50, 0.25, 0.00,   7.50, 0.51, 0.00,   7.50, 0.51, 0.00,   7.50, 0.76, 0.00,   7.50, 0.76, 0.00,   7.50, 1.01, 0.00,   7.50, 1.01, 0.00,   7.50, 1.26, 0.00,   7.50, 1.26, 0.00,   7.50, 1.52, 0.00,   7.50, 1.52, 0.00,   7.80, 0.20, 0.00,   7.80, 0.20, 0.00,   7.80, 0.46, 0.00,   7.80, 0.46, 0.00,   7.80, 0.71, 0.00,   7.80, 0.71, 0.00,   7.80, 0.96, 0.00,   7.80, 0.96, 0.00,   7.80, 1.22, 0.00,   7.80, 1.22, 0.00,   7.80, 1.47, 0.00,   7.80, 1.47, 0.00,   7.80, 1.72, 0.00,   7.80, 1.72, 0.00,   8.11, 0.00, 0.00,   8.11, 0.00, 0.00,   8.11, 0.25, 0.00,   8.11, 0.25, 0.00,   8.11, 0.51, 0.00,   8.11, 0.51, 0.00,   8.11, 0.76, 0.00,   8.11, 0.76, 0.00,   8.11, 1.01, 0.00,   8.11, 1.01, 0.00,   8.11, 1.26, 0.00,   8.11, 1.26, 0.00,   8.11, 1.52, 0.00,   8.11, 1.52, 0.00,   8.41, 0.20, 0.00,   8.41, 0.20, 0.00,   8.41, 0.46, 0.00,   8.41, 0.46, 0.00,   8.41, 0.71, 0.00,   8.41, 0.71, 0.00,   8.41, 0.96, 0.00,   8.41, 0.96, 0.00,   8.41, 1.22, 0.00,   8.41, 1.22, 0.00,   8.41, 1.47, 0.00,   8.41, 1.47, 0.00,   8.41, 1.72, 0.00,   8.41, 1.72, 0.00,   8.72, 0.00, 0.00,   8.72, 0.00, 0.00,   8.72, 0.25, 0.00,   8.72, 0.25, 0.00,   8.72, 0.51, 0.00,   8.72, 0.51, 0.00,   8.72, 0.76, 0.00,   8.72, 0.76, 0.00,   8.72, 1.01, 0.00,   8.72, 1.01, 0.00,   8.72, 1.26, 0.00,   8.72, 1.26, 0.00,   8.72, 1.52, 0.00,   8.72, 1.52, 0.00,   9.02, 0.20, 0.00,   9.02, 0.20, 0.00,   9.02, 0.46, 0.00,   9.02, 0.46, 0.00,   9.02, 0.71, 0.00,   9.02, 0.71, 0.00,   9.02, 0.96, 0.00,   9.02, 0.96, 0.00,   9.02, 1.22, 0.00,   9.02, 1.22, 0.00,   9.02, 1.47, 0.00,   9.02, 1.47, 0.00,   9.02, 1.72, 0.00,   9.02, 1.72, 0.00,   9.33, 0.00, 0.00,   9.33, 0.00, 0.00,   9.33, 0.25, 0.00,   9.33, 0.25, 0.00,   9.33, 0.51, 0.00,   9.33, 0.51, 0.00,   9.33, 0.76, 0.00,   9.33, 0.76, 0.00,   9.33, 1.01, 0.00,   9.33, 1.01, 0.00,   9.33, 1.26, 0.00,   9.33, 1.26, 0.00,   9.33, 1.52, 0.00,   9.33, 1.52, 0.00,   9.63, 0.20, 0.00,   9.63, 0.20, 0.00,   9.63, 0.46, 0.00,   9.63, 0.46, 0.00,   9.63, 0.71, 0.00,   9.63, 0.71, 0.00,   9.63, 0.96, 0.00,   9.63, 0.96, 0.00,   9.63, 1.22, 0.00,   9.63, 1.22, 0.00,   9.63, 1.47, 0.00,   9.63, 1.47, 0.00,   9.63, 1.72, 0.00,   9.63, 1.72, 0.00,   9.94, 0.00, 0.00,   9.94, 0.00, 0.00,   9.94, 0.25, 0.00,   9.94, 0.25, 0.00,   9.94, 0.51, 0.00,   9.94, 0.51, 0.00,   9.94, 0.76, 0.00,   9.94, 0.76, 0.00,   9.94, 1.01, 0.00,   9.94, 1.01, 0.00,   9.94, 1.26, 0.00,   9.94, 1.26, 0.00,   9.94, 1.52, 0.00,   9.94, 1.52, 0.00,   10.24, 0.20, 0.00,   10.24, 0.20, 0.00,   10.24, 0.46, 0.00,   10.24, 0.46, 0.00,   10.24, 0.71, 0.00,   10.24, 0.71, 0.00,   10.24, 0.96, 0.00,   10.24, 0.96, 0.00,   10.24, 1.22, 0.00,   10.24, 1.22, 0.00,   10.24, 1.47, 0.00,   10.24, 1.47, 0.00,   10.24, 1.72, 0.00,   10.24, 1.72, 0.00,   10.55, 0.00, 0.00,   10.55, 0.00, 0.00,   10.55, 0.25, 0.00,   10.55, 0.25, 0.00,   10.55, 0.51, 0.00,   10.55, 0.51, 0.00,   10.55, 0.76, 0.00,   10.55, 0.76, 0.00,   10.55, 1.01, 0.00,   10.55, 1.01, 0.00,   10.55, 1.26, 0.00,   10.55, 1.26, 0.00,   10.55, 1.52, 0.00,   10.55, 1.52, 0.00,   10.85, 0.20, 0.00,   10.85, 0.20, 0.00,   10.85, 0.46, 0.00,   10.85, 0.46, 0.00,   10.85, 0.71, 0.00,   10.85, 0.71, 0.00,   10.85, 0.96, 0.00,   10.85, 0.96, 0.00,   10.85, 1.22, 0.00,   10.85, 1.22, 0.00,   10.85, 1.47, 0.00,   10.85, 1.47, 0.00,   10.85, 1.72, 0.00,   10.85, 1.72, 0.00,   11.16, 0.00, 0.00,   11.16, 0.00, 0.00,   11.16, 0.25, 0.00,   11.16, 0.25, 0.00,   11.16, 0.51, 0.00,   11.16, 0.51, 0.00,   11.16, 0.76, 0.00,   11.16, 0.76, 0.00,   11.16, 1.01, 0.00,   11.16, 1.01, 0.00,   11.16, 1.26, 0.00,   11.16, 1.26, 0.00,   11.16, 1.52, 0.00,   11.16, 1.52, 0.00,   11.46, 0.20, 0.00,   11.46, 0.20, 0.00,   11.46, 0.46, 0.00,   11.46, 0.46, 0.00,   11.46, 0.71, 0.00,   11.46, 0.71, 0.00,   11.46, 0.96, 0.00,   11.46, 0.96, 0.00,   11.46, 1.22, 0.00,   11.46, 1.22, 0.00,   11.46, 1.47, 0.00,   11.46, 1.47, 0.00,   11.46, 1.72, 0.00,   11.46, 1.72, 0.00,   11.77, 0.00, 0.00,   11.77, 0.00, 0.00,   11.77, 0.25, 0.00,   11.77, 0.25, 0.00,   11.77, 0.51, 0.00,   11.77, 0.51, 0.00,   11.77, 0.76, 0.00,   11.77, 0.76, 0.00,   11.77, 1.01, 0.00,   11.77, 1.01, 0.00,   11.77, 1.26, 0.00,   11.77, 1.26, 0.00,   11.77, 1.52, 0.00,   11.77, 1.52, 0.00,   12.07, 0.20, 0.00,   12.07, 0.20, 0.00,   12.07, 0.46, 0.00,   12.07, 0.46, 0.00,   12.07, 0.71, 0.00,   12.07, 0.71, 0.00,   12.07, 0.96, 0.00,   12.07, 0.96, 0.00,   12.07, 1.22, 0.00,   12.07, 1.22, 0.00,   12.07, 1.47, 0.00,   12.07, 1.47, 0.00,   12.07, 1.72, 0.00,   12.07, 1.72, 0.00,   12.38, 0.00, 0.00,   12.38, 0.00, 0.00,   12.38, 0.25, 0.00,   12.38, 0.25, 0.00,   12.38, 0.51, 0.00,   12.38, 0.51, 0.00,   12.38, 0.76, 0.00,   12.38, 0.76, 0.00,   12.38, 1.01, 0.00,   12.38, 1.01, 0.00,   12.38, 1.26, 0.00,   12.38, 1.26, 0.00,   12.38, 1.52, 0.00,   12.38, 1.52, 0.00,   12.68, 0.20, 0.00,   12.68, 0.20, 0.00,   12.68, 0.46, 0.00,   12.68, 0.46, 0.00,   12.68, 0.71, 0.00,   12.68, 0.71, 0.00,   12.68, 0.96, 0.00,   12.68, 0.96, 0.00,   12.68, 1.22, 0.00,   12.68, 1.22, 0.00,   12.68, 1.47, 0.00,   12.68, 1.47, 0.00,   12.68, 1.72, 0.00,   12.68, 1.72, 0.00,   12.99, 0.00, 0.00,   12.99, 0.00, 0.00,   12.99, 0.25, 0.00,   12.99, 0.25, 0.00,   12.99, 0.51, 0.00,   12.99, 0.51, 0.00,   12.99, 0.76, 0.00,   12.99, 0.76, 0.00,   12.99, 1.01, 0.00,   12.99, 1.01, 0.00,   12.99, 1.26, 0.00,   12.99, 1.26, 0.00,   12.99, 1.52, 0.00,   12.99, 1.52, 0.00,   13.29, 0.20, 0.00,   13.29, 0.20, 0.00,   13.29, 0.46, 0.00,   13.29, 0.46, 0.00,   13.29, 0.71, 0.00,   13.29, 0.71, 0.00,   13.29, 0.96, 0.00,   13.29, 0.96, 0.00,   13.29, 1.22, 0.00,   13.29, 1.22, 0.00,   13.29, 1.47, 0.00,   13.29, 1.47, 0.00,   13.29, 1.72, 0.00,   13.29, 1.72, 0.00,   13.60, 0.00, 0.00,   13.60, 0.00, 0.00,   13.60, 0.25, 0.00,   13.60, 0.25, 0.00,   13.60, 0.51, 0.00,   13.60, 0.51, 0.00,   13.60, 0.76, 0.00,   13.60, 0.76, 0.00,   13.60, 1.01, 0.00,   13.60, 1.01, 0.00,   13.60, 1.26, 0.00,   13.60, 1.26, 0.00,   13.60, 1.52, 0.00,   13.60, 1.52, 0.00,   13.90, 0.20, 0.00,   13.90, 0.20, 0.00,   13.90, 0.46, 0.00,   13.90, 0.46, 0.00,   13.90, 0.71, 0.00,   13.90, 0.71, 0.00,   13.90, 0.96, 0.00,   13.90, 0.96, 0.00,   13.90, 1.22, 0.00,   13.90, 1.22, 0.00,   13.90, 1.47, 0.00,   13.90, 1.47, 0.00,   13.90, 1.72, 0.00,   13.90, 1.72, 0.00,]

    numPixels = len(previousLayout) // 3
    curX = None
    d = {}
    for i in range(numPixels):
      x = previousLayout[i*3]
      y = previousLayout[i*3+1]
      if x != curX:
        curX = x
        d[x] = []
      d[x].append(y)

    xList = list(d.keys())
    xList.sort(reverse=True)

    print('numX:', len(xList))
    reverse = False
    prevX = 0
    for x in xList:
      reverse = not reverse
      diff = prevX - x
      prevX = x
      yList = d[x]
      yList.sort(reverse=reverse)
      print('{:.2f}: (len {}, diff {:.2f}) {}'.format(x, len(yList), diff, yList))

    print('\n')

  robotWallMaxX = 14.5

  if head:
    xDiff = 0.3
    yDiff = 0.25
    maxX = robotWallMaxX + 5.2
    maxY = 1.38
    minY = 1.0
    numX = 17
    numY = 2
    startUp = True
    startMidWay = True
    # x = [14.3 .. 16.59] with diff 0.15
    # on lower y =  [1.0  .. 1.14] with diff 0.14
    # on higher y = [1.07 .. 1.21] with diff 0.14
  else:
    xDiff = 0.3
    yDiff = 0.25
    maxX = robotWallMaxX
    maxY = 1.72
    minY = 0.0
    numX = 24
    numY = 7
    startUp = True
    startMidWay = False
    # x = [7.5 .. 13.9] with diff 0.3 
    # on lower y =  [0.2 .. 1.72] with diff 0.25
    # on higher y = [0.0 .. 1.52] with diff 0.25

  l = []
  x = maxX
  if startMidWay:
    minY += yDiff/2
    maxY -= yDiff/2
  y = maxY if startUp else minY

  for xi in range(numX):
    thisMinY = minY
    thisMaxY = maxY
    up = (xi % 2 == (0 if startUp else 1))
    if head:
      maxyi = 2
    else:
      maxyi = 7
      if xi <= 2:
        maxyi = 3
      if xi == 0:
        thisMinY = 1.26
    yMult = -1.0 if up else 1.0
    for yi in range(maxyi):
      l.append((x, y))
      y += yDiff * yMult
    if up:
      y = thisMinY
    else:
      y = thisMaxY
    x -= xDiff

  if head:
    s = '# ROBOT HEAD'
  else:
    s = '# ROBOT PASSENGER WALL'
  s += '\nlayout = {type="pixelmap", coords=['
  for c in l:
    print("({:.2f}, {:.2f})".format(c[0], c[1]))
    for i in range(2):
      s += "{:.2f}, {:.2f}, 0.0,   ".format(c[0], c[1])
  s = s[:-4]
  s += ']}'

  print('\n')
  print(s)
  print('\n')
  printLayout(l, '2' if head else '')
  print('\n')
