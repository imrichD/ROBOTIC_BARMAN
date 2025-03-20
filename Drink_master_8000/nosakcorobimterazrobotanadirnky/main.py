import sys
from PySide6.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QGridLayout,
    QScrollArea, QPushButton, QLabel, QDialog
)
from PySide6.QtCore import Qt, QSize
from PySide6.QtGui import QIcon

from MyButton import MyButton         # Custom image button with built-in cleaning signal
from Veci_s_Drinks import Veci_s_Drinks # Contains drinks_names and drinks_pics
from CleaningDialog import CleaningDialog
from QuitDialog import QuitDialog

# Define a function to show the cleaning dialog when the cleaning signal is emitted.
def show_cleaning_dialog():
    cleaning_dialog = CleaningDialog()
    if cleaning_dialog.exec() == QDialog.Accepted:
        print("Cleaning action confirmed.")

# Define a function to show the quit dialog when the top button is pressed.
def show_quit_dialog():
    quit_dialog = QuitDialog()
    if quit_dialog.exec() == QDialog.Accepted:
        print("Program will now quit.")
        QApplication.quit()
        
if __name__ == '__main__':
    app = QApplication(sys.argv)
    
    window = QMainWindow()
    window.setWindowTitle("FES APPka")
    window.showFullScreen()
    window.setStyleSheet("background-color: black;")
    
    # Create a central widget with a vertical layout
    central_widget = QWidget()
    main_layout = QVBoxLayout(central_widget)
    main_layout.setContentsMargins(0, 50, 0, 50)
    main_layout.setSpacing(10)

    # ------------------ Top Section ------------------
    top_widget = QWidget()
    top_grid = QGridLayout(top_widget)
    top_grid.setContentsMargins(0, 0, 0, 0)
    top_grid.setSpacing(5)
    
    # Create the top left button that will show the quit dialog
    top_button = QPushButton("")
    top_button.setIcon(QIcon("images/ONOFF.png"))
    top_button.setIconSize(QSize(50, 50))
    top_button.setStyleSheet("background-color: gray; color: white; font-size: 20px;")
    top_grid.addWidget(top_button, 0, 0)
    top_button.clicked.connect(show_quit_dialog)
    
    # Create the top label with big text
    top_label = QLabel("DRINKS")
    top_label.setAlignment(Qt.AlignCenter)
    top_label.setStyleSheet("color: white; font-size: 36px;")
    top_grid.addWidget(top_label, 0, 1, 1, 14)
    
    main_layout.addWidget(top_widget)
    # -------------------------------------------------

    # ------------------ Grid Section ------------------
    grid_container = QWidget()
    grid_layout = QGridLayout(grid_container)
    grid_layout.setHorizontalSpacing(5)
    grid_layout.setVerticalSpacing(5)
    
    texts = Veci_s_Drinks.drinks_names
    num_buttons = 29
    columns = 4
    positions = [(i // columns, i % columns) for i in range(num_buttons)]

    buttons_list = []
    
    for pos, text in zip(positions, texts):
        cell_widget = QWidget()
        cell_layout = QVBoxLayout(cell_widget)
        cell_layout.setContentsMargins(0, 0, 0, 0)
        cell_layout.setSpacing(5)
        
        button = MyButton()
        cell_layout.addWidget(button)
        buttons_list.append(button)
        
        label = QLabel(text)
        label.setStyleSheet("color: white;")
        label.setAlignment(Qt.AlignHCenter)
        cell_layout.addWidget(label)
        
        grid_layout.addWidget(cell_widget, *pos)
    
    # Connect the cleaning signal from the third button (index 2) to our cleaning dialog function.
    if len(buttons_list) > 2:
        buttons_list[28].cleaning.connect(show_cleaning_dialog)
    
    scroll_area = QScrollArea()
    scroll_area.setWidgetResizable(True)
    scroll_area.setWidget(grid_container)
    scroll_area.setStyleSheet("border: none;")
    scroll_area.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
    
    main_layout.addWidget(scroll_area)
    # -------------------------------------------------

    window.setCentralWidget(central_widget)
    window.show()
    
    sys.exit(app.exec())
