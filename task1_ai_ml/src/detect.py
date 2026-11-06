"""
Drone Object Detection using YOLO26n fine-tuned on VisDrone2019-DET.

Example:
    python detect.py --model best_model.pt --source drone_image.jpg
    python detect.py --model best_model.pt --source ./test_images --output ./runs/predictions

Install dependencies:
    pip install ultralytics
"""

import argparse
from pathlib import Path
from ultralytics import YOLO


def main():
    parser = argparse.ArgumentParser(
        description="Run YOLO26n object detection on drone images."
    )
    parser.add_argument(
        "--model", required=True,
        help="Path to the trained YOLO model checkpoint (.pt file)."
    )
    parser.add_argument(
        "--source", required=True,
        help="Path to an image or a folder of images."
    )
    parser.add_argument(
        "--output", default="runs/predictions",
        help="Folder where prediction images will be saved."
    )
    parser.add_argument(
        "--imgsz", type=int, default=1536,
        help="Inference image size (default: 1536)."
    )
    parser.add_argument(
        "--conf", type=float, default=0.25,
        help="Confidence threshold (default: 0.25)."
    )
    args = parser.parse_args()

    model_path = Path(args.model)
    source_path = Path(args.source)

    if not model_path.is_file():
        raise FileNotFoundError(f"Model checkpoint not found: {model_path}")
    if not source_path.exists():
        raise FileNotFoundError(f"Image or folder not found: {source_path}")
    if not 0.0 <= args.conf <= 1.0:
        raise ValueError("--conf must be between 0 and 1.")

    model = YOLO(str(model_path))
    results = model.predict(
        source=str(source_path),
        imgsz=args.imgsz,
        conf=args.conf,
        save=True,
        show_labels=True,
        show_conf=True,
        line_width=2,
        project=str(Path(args.output).parent),
        name=Path(args.output).name,
        exist_ok=True,
    )

    print(f"Detection completed. Results saved in: {args.output}")
    print(f"Images processed: {len(results)}")


if __name__ == "__main__":
    main()
