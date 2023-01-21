from cvzone.HandTrackingModule import HandDetector
import cv2

cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.8, maxHands=1)

video = cv2.VideoCapture(0)
while True:
    # Capture frame-by-frame
    _, img = video.read()
    img = cv2.flip(img, 1)

    # Find the hand with help of detector
    hand = detector.findHands(img, draw=False)

    # Here we take img by default if no hand found
    fing = cv2.imread("Put image path with 0 fingures up")
    if hand:
        lmlist = hand[0]
        if lmlist:
            fingerup = detector.fingersUp(lmlist)




    # Change image based on
    # different-different conditions
    if fingerup == [0, 1, 0, 0, 0]:
        fing = cv2.imread("Put image path of 1\
                            fingures up")
    if fingerup == [0, 1, 1, 0, 0]:
        fing = cv2.imread("Put image path of 2 fingeres up")
    if fingerup == [0, 1, 1, 1, 0]:
        fing = cv2.imread("Put image path of 3 fingeres up")
    if fingerup == [0, 1, 1, 1, 1]:
        fing = cv2.imread("sPut image of 4 fingeres up")
    if fingerup == [1, 1, 1, 1, 1]:
        fing = cv2.imread("Put image  of 4 fingeres and thumbs up")
    # Resize the image
    fing = cv2.resize(fing, (220, 280))

    # Place the image in main frame
    img[50:330, 20:240] = fing

    # Display the resulting frame
    cv2.imshow("Video", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

    # When everything done, release
    # the capture and destroy the windows
    video.release()
    cv2.destroyAllWindows()