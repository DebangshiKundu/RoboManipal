import cv2
import numpy as np
import matplotlib.pyplot as plt

def track_basketball(video_path):
    cap = cv2.VideoCapture(video_path)

    ret, frame = cap.read()
    roi = cv2.selectROI("Select the basketball", frame)
    cv2.destroyAllWindows()

    tracker = cv2.TrackerMeanShift_create()
    tracker.init(frame, roi)

    path = []

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        success, bbox = tracker.update(frame)

        if success:
            x, y, w, h = [int(i) for i in bbox]
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

            center = (x + w // 2, y + h // 2)
            path.append(center)

        cv2.imshow("Basketball Tracking", frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

    return path

def plot_path(path):
    path = np.array(path)
    plt.plot(path[:, 0], path[:, 1], label='Basketball Path', marker='o')
    plt.title('Basketball Tracking Path')
    plt.xlabel('X-coordinate')
    plt.ylabel('Y-coordinate')
    plt.legend()
    plt.show()

video_path = "https://www.youtube.com/watch?v=aPxFcPYWlAA"

basketball_path = track_basketball(video_path)

plot_path(basketball_path)
