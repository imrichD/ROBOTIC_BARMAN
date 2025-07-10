from PySide6.QtWidgets import QDialog, QVBoxLayout, QLabel, QPushButton, QApplication
from PySide6.QtCore import Qt

class QuitDialog(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Do you really want to end the program?")
        self.setWindowFlags(Qt.FramelessWindowHint | Qt.Dialog)
        self.setObjectName("OFFDialog")
        self.setStyleSheet("""
            QDialog#OFFDialog {
                border: 2px solid white;     /* Outside border */
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
        text_question = QLabel("Do you really want to end the program?")
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
        print("Quitting program.")
        self.accept()  # Closes the dialog
        QApplication.quit()  # Quits the entire application

    def handle_no(self):
        print("Quit canceled.")
        self.reject()  # Closes the dialog
