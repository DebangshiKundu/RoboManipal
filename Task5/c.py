import cv2 as cv
import cvzone 
from cvzone.ColorModule import ColorFinder

capture = cv.VideoCapture("/Users/debangshi/Downloads/Scr.mp4")
vid = cv.VideoCapture('/Users/debangshi/Downloads/Scr.mp4')
img = cv.imread('/Users/debangshi/Downloads/ball.png')
img2 = cv.imread('/Users/debangshi/Downloads/ball.png')

#cv.imshow('Ball', img)

#cv.waitKey(0)

#Create the color finder object
myColorFinder = ColorFinder(False)
hsvVals = {'hmin': 0, 'smin': 0, 'vmin': 86, 'hmax': 179, 'smax': 78, 'vmax': 145}

#jimgColor, mask = myColorFinder.update(img,hsvVals)
#cv.imshow("ImageColor", imgColor)
  
#cv.waitKey(0)


while True:
    isTrue, frame = capture.read()
    # if cv.waitKey(20) & 0xFF==ord('d'):
    # This is the preferred way - if `isTrue` is false (the frame could 
    # not be read, or we're at the end of the video), we immediately
    # break from the loop. 
    
    success, img = capture.read() 
    imgColor, mask = myColorFinder.update(img,hsvVals)
    cv.imshow("ImageColor", img2)

    #Find Location of the BALL
    imgContours, countours = cvzone.findContours(img,mask,minArea=200)

    if isTrue:    
        cv.imshow('Video', imgContours)
        if cv.waitKey(100) & 0xFF==ord('d'):
            break            
    else:
        break
    
    #cv.waitKey(0)

#cv.waitKey(0)
capture.release()
cv.destroyAllWindows()

#Create the color finder object
#myColorFinder = myColorFinder(True)