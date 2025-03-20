from PySide6.QtWidgets import QDialog, QVBoxLayout, QLabel, QPushButton, QApplication
from PySide6.QtCore import Qt

class CleaningDialog(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Do you really want to use the cleaning program?")
        self.setWindowFlags(Qt.FramelessWindowHint | Qt.Dialog)
        self.setObjectName("CleaningDialog")
        self.setStyleSheet("""
            QDialog#CleaningDialog {
                border: 2px solid white;     /* Outside border */
                background-color: black;
            }
            QLabel {
                color: white;
                font-size: 30px;
                border: none;               /* No border on the label */
            }
            QPushButton {
                color: white;
                font-size: 30px;
                background-color: black;
            }
        """)

        layout = QVBoxLayout(self)
        # Create and center the questioning text
        text_question = QLabel("Do you really want to use the cleaning program?\nIt takes several minutes.")
        text_question.setAlignment(Qt.AlignCenter)
        layout.addWidget(text_question)

        self.resize(400, 200)
        self.buttonYes = QPushButton("YES")
        layout.addWidget(self.buttonYes)
        self.buttonNo = QPushButton("NO")
        layout.addWidget(self.buttonNo)

        # Connect the buttons to methods
        self.buttonYes.clicked.connect(self.handle_yes)
        self.buttonNo.clicked.connect(self.handle_no)

    def handle_yes(self):
        print("Cleaning confirmed.")
        self.accept()  # Closes the dialog

    def handle_no(self):
        print("Cleaning canceled.")
        self.reject()  # Closes the dialog
