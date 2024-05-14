import tkinter as tk
root = tk.Tk()
root.title("Window")
label = tk.Label(root, text="Hello World")
label.pack()
button = tk.Button(root, text="Click me!", command = root.quit)
button.pack()
root.geometry("400x300+100+50") # Kích thước 400x300, vị trí 100, 50 trên màn hình
root.resizable(width=True, height=True) # Cho phép thay đổi kích thước cửa sổ
root.configure(bg='lightblue') # Đổi màu nền của cửa sổ
root.mainloop()