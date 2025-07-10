from PySide6.QtWidgets import QPushButton
from PySide6.QtGui import QIcon
from PySide6.QtCore import QSize, Signal
from Veci_s_Drinks import Veci_s_Drinks

class MyButton(QPushButton):
    # Custom signal that carries an integer (the button's unique ID)
    numberPressed = Signal(int)
    button_count = 0  # Class variable to count buttons

    def __init__(self):
        super().__init__()
        pics = Veci_s_Drinks.drinks_pics
        self.id = MyButton.button_count
        MyButton.button_count += 1

        # Remove any text; show only the image.
        self.setText("")
        self.setIcon(QIcon(pics[self.id]))
        self.setIconSize(QSize(150, 300))
        self.setMinimumSize(150, 300)
        self.setStyleSheet("border: none;")
        
        # Connect the clicked signal to our on_click handler
        self.clicked.connect(self.on_click)

    def on_click(self, checked=False):
        print(f"Button {self.id} clicked!")
        self.numberPressed.emit(self.id)
