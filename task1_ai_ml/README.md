# AI-Based Drone Object Detection Using YOLO26n

##  Project Overview

This project focuses on detecting and identifying objects in drone-view images using the YOLO26n object detection model.

The model is fine-tuned on the VisDrone2019-DET dataset to detect objects such as pedestrians, people, bicycles, cars, vans, trucks, buses, and motorcycles.

##  Dataset

- **Dataset:** VisDrone2019-DET
- **Source:** VisDrone Dataset
- **Task:** Object Detection
- **Number of Classes:** 10

##  Model and Technologies

- YOLO26n
- Python
- Ultralytics
- Google Colab
- PyTorch

##  Model Evaluation

The selected model was evaluated at an image size of 1536.

|   | Metric    | Result |
| - | --------- | -----: |
|   | Precision | 52.89% |
|   | Recall    | 45.76% |
|   | mAP50     | 45.84% |
|   | mAP50-95  | 27.06% |

##  Detection Settings

- Image Size: 1536
- Confidence Threshold: 0.25
- Bounding Boxes: Enabled
- Class Labels: Enabled
- Confidence Scores: Enabled

##  Project Structure

```text
task1_ai_ml/
├── notebooks/
│   └── VisDrone_Object_Detection.ipynb
├── src/
│   └── detect.py
├── results/
│   ├── sample_predictions/
│   └── training_graphs/
└── README.md
```

##  Results

Sample prediction images and model training/evaluation graphs are available in the `results` folder.
The project was also tested on 10 unseen drone images for visual evaluation.

## 8. Future Improvements

- Improve detection of small and distant objects.
- Reduce false detections in crowded scenes.
- Explore further model optimization.
- Test the model on additional drone videos.
