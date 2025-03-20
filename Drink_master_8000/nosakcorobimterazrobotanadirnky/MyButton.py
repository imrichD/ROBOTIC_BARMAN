from PySide6.QtWidgets import QPushButton
from PySide6.QtGui import QIcon
from PySide6.QtCore import QSize,Signal
from Veci_s_Drinks import Veci_s_Drinks

class MyButton(QPushButton):
    button_count = 0    #tu ratam kolko kram bola funkcia zavolana
    cleaning = Signal()
    def __init__(self, index=0):
        super().__init__()
        
        
        pics = Veci_s_Drinks.drinks_pics
        index = MyButton.button_count 
        MyButton.button_count = MyButton.button_count + 1
        
        # Remove any text so only the image is visible.
        self.setText("")
        # Set the image icon for the button (update the path to your image)
        self.setIcon(QIcon(pics[index]))
        # Set the desired icon size (adjust 200x200 as needed)
        self.setIconSize(QSize(150, 300))
        # Ensure the button doesn't shrink below the icon size
        self.setMinimumSize(150, 300)
        # Remove button border
        self.setStyleSheet("border: none;")
        # Connect the click event to a method
        if(index == 28):
            self.clicked.connect(self.on_click_clean)
        else :
            self.clicked.connect(self.on_click)
        
    def on_click(self):
        print("Button clicked!")
    
    def on_click_clean(self,checked=False):
        print("Cleaning button clicked!")
        self.cleaning.emit()

