import tkinter as tk
from tkinter import messagebox
import json
import random
import re
import os

# Hàm để đọc danh sách khách hàng từ file JSON
def read_customers():
    if not os.path.exists('Khach.json'):
        return []
    with open('Khach.json', 'r') as file:
        return json.load(file)

# Hàm để ghi danh sách khách hàng vào file JSON
def write_customers(customers):
    with open('Khach.json', 'w') as file:
        json.dump(customers, file, indent=4)

# Hàm để hiển thị danh sách khách hàng trong Listbox
def display_customers(customers):
    for widget in customer_frame.winfo_children():
        widget.destroy()
    
    for idx, customer in enumerate(sorted(customers, key=lambda x: x['tong_tien'], reverse=True)):
        customer_label = tk.Label(customer_frame, text=f"{customer['ma_so']} - {customer['ho_ten']} {customer['so_dien_thoai']} - {customer['tong_tien']}")
        customer_label.grid(row=idx, column=0, sticky='w')

        delete_button = tk.Button(customer_frame, text="Xóa", command=lambda idx=idx: delete_customer(idx))
        delete_button.grid(row=idx, column=1)

# Hàm để thêm khách hàng mới
def add_customer():
    ho_ten = ho_ten_entry.get()
    so_dien_thoai = so_dien_thoai_entry.get()
    tong_tien = tong_tien_entry.get()

    if not ho_ten or not so_dien_thoai or not tong_tien:
        messagebox.showerror("Lỗi", "Vui lòng nhập đầy đủ thông tin khách hàng")
        return

    if not re.match(r'^(0|\+84)(3[2-9]|5[6|8|9]|7[0|6-9]|8[1-9]|9[0-9])[0-9]{7}$', so_dien_thoai):
        messagebox.showerror("Lỗi", "Số điện thoại không hợp lệ")
        return

    try:
        tong_tien = int(tong_tien)
    except ValueError:
        messagebox.showerror("Lỗi", "Tổng tiền phải là một số")
        return

    ma_so = "24" + "".join(random.choices("0123456789", k=4))
    new_customer = {
        "ma_so": ma_so,
        "ho_ten": ho_ten,
        "so_dien_thoai": so_dien_thoai,
        "tong_tien": tong_tien
    }

    customers.append(new_customer)
    write_customers(customers)
    display_customers(customers)
    ho_ten_entry.delete(0, tk.END)
    so_dien_thoai_entry.delete(0, tk.END)
    tong_tien_entry.delete(0, tk.END)

# Hàm để xóa khách hàng
def delete_customer(index):
    result = messagebox.askyesno("Xác nhận", "Bạn có chắc chắn muốn xóa khách hàng này?")
    if result:
        del customers[index]
        write_customers(customers)
        display_customers(customers)

# Hàm để tìm kiếm khách hàng
def search_customer():
    keyword = search_entry.get().lower()
    result_listbox.delete(0, tk.END)
    for customer in customers:
        if keyword in customer['ho_ten'].lower() or keyword in customer['so_dien_thoai']:
            result_listbox.insert(tk.END, f"{customer['ma_so']} - {customer['ho_ten']} {customer['so_dien_thoai']} - {customer['tong_tien']}")

# Tạo cửa sổ chính
root = tk.Tk()
root.title("Quản lý khách hàng")

# Đọc danh sách khách hàng từ file JSON
customers = read_customers()

# Tạo các trường nhập liệu và nút thêm khách hàng
tk.Label(root, text="Họ và tên").grid(row=0, column=0, padx=5, pady=5, sticky='w')
ho_ten_entry = tk.Entry(root, width=50)
ho_ten_entry.grid(row=0, column=1, padx=5, pady=5)

tk.Label(root, text="Số điện thoại").grid(row=1, column=0, padx=5, pady=5, sticky='w')
so_dien_thoai_entry = tk.Entry(root, width=50)
so_dien_thoai_entry.grid(row=1, column=1, padx=5, pady=5)

tk.Label(root, text="Tổng tiền").grid(row=2, column=0, padx=5, pady=5, sticky='w')
tong_tien_entry = tk.Entry(root, width=50)
tong_tien_entry.grid(row=2, column=1, padx=5, pady=5)

tk.Button(root, text="Thêm khách hàng", command=add_customer).grid(row=3, column=1, padx=5, pady=5, sticky='e')

# Khung hiển thị danh sách khách hàng
customer_frame = tk.Frame(root)
customer_frame.grid(row=4, column=0, columnspan=2, padx=5, pady=5, sticky='nsew')

# Tạo ô tìm kiếm khách hàng
tk.Label(root, text="Tìm kiếm khách hàng").grid(row=5, column=0, padx=5, pady=5, sticky='w')
search_entry = tk.Entry(root, width=50)
search_entry.grid(row=5, column=1, padx=5, pady=5, sticky='w')
tk.Button(root, text="Tìm kiếm", command=search_customer).grid(row=6, column=1, padx=5, pady=5, sticky='e')

# Listbox hiển thị kết quả tìm kiếm
tk.Label(root, text="Kết quả tìm kiếm:").grid(row=7, column=0, padx=5, pady=5, sticky='w')
result_listbox = tk.Listbox(root, width=75, height=10)
result_listbox.grid(row=8, column=0, columnspan=2, padx=5, pady=5)

# Hiển thị danh sách khách hàng ban đầu
display_customers(customers)

root.mainloop()