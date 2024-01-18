import cv2
import numpy as np
import matplotlib.pyplot as plt

video_path = "/Users/debangshi/Downloads/Scr.mp4"

def track_basketball(video_path):
    cap = cv2.VideoCapture(video_path)

    ret, frame = cap.read()
    roi = cv2.selectROI("Select the basketball", frame)
    cv2.destroyAllWindows()

    tracker = cv2.TrackerKCF_create() 
    tracker.init(frame, roi)

    path = []
    tracking_lost = False  # Flag to indicate if tracking is lost

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

            # Update the ROI based on the tracked object's position
            roi = (x, y, w, h)
            tracking_lost = False  # Reset the flag when tracking is successful
        else:
            tracking_lost = True  # Set the flag if tracking is lost

        # Draw the continuously updated ROI
        cv2.rectangle(frame, (int(roi[0]), int(roi[1])), (int(roi[0] + roi[2]), int(roi[1] + roi[3])), (255, 0, 0), 2)

        # Draw the complete traced path on each frame
        for i in range(1, len(path)):
            cv2.line(frame, path[i-1], path[i], (0, 0, 255), 2)  # Red line for the traced path

        cv2.imshow("Basketball Tracking", frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

    if tracking_lost:
        print("Tracking lost in some frames.")

    return path

def plot_path(path):
    path = np.array(path)
    plt.plot(path[:, 0], path[:, 1], label='Basketball Path', marker='o')
    plt.plot(path[:, 0], path[:, 1], 'r--', label='Tracing Line')  # Dotted line
    plt.title('Basketball Tracking Path')
    plt.xlabel('X-coordinate')
    plt.ylabel('Y-coordinate')
    plt.legend()
    plt.show()

basketball_path = track_basketball(video_path)
plot_path(basketball_path)
