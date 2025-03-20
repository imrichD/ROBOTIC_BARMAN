from PySide6.QtGui import QPixmap
from PySide6.QtWidgets import QWidget,  QLabel, QHBoxLayout, QVBoxLayout, QPushButton

class Widget2(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QLabel Image Demo")

        image_label = QLabel()
        image_label.setPixmap(QPixmap("images/Drink.png"))

        layout = QVBoxLayout()
        layout.addWidget(image_label)

        self.setLayout(layout)