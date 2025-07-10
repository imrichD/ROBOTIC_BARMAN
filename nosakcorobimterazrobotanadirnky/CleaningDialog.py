# CleaningDialog.py
from PySide6.QtWidgets import QDialog, QVBoxLayout, QLabel, QPushButton
from PySide6.QtCore import Qt
from ImportSerial import send_signal_to_esp32

class CleaningDialog(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Do you really want to use the cleaning program?")
        self.setWindowFlags(Qt.FramelessWindowHint | Qt.Dialog)
        self.setObjectName("CleaningDialog")
        self.setStyleSheet("""
            QDialog#CleaningDialog {
                border: 2px solid white;
                background-color: black;
            }
            QLabel {
                color: white;
                font-size: 30px;
                border: none;
            }
            QPushButton {
                color: white;
                font-size: 30px;
                background-color: black;
            }
        """)

        layout = QVBoxLayout(self)

        text_question = QLabel("Do you really want to use the cleaning program?\nIt takes several minutes.")
        text_question.setAlignment(Qt.AlignCenter)
        layout.addWidget(text_question)

        self.resize(400, 200)
        self.buttonYes = QPushButton("YES")
        layout.addWidget(self.buttonYes)
        self.buttonNo = QPushButton("NO")
        layout.addWidget(self.buttonNo)

        self.buttonYes.clicked.connect(self.handle_yes)
        self.buttonNo.clicked.connect(self.handle_no)

    def handle_yes(self):
        print("Cleaning confirmed.")
        send_signal_to_esp32(28)  # Send cleaning signal
        self.accept()

    def handle_no(self):
        print("Cleaning canceled.")
        self.reject()
