import tkinter as tk
from tkinter import ttk, messagebox
import json

# Static sensor data
static_temperature = "25°C"
static_humidity = "60%"
static_gas_concentration = "10 ppm"

class InventoryManagementApp:
    def _init_(self, master):
        self.master = master

        # Tkinter variables to hold sensor data
        self.temperature_var = tk.StringVar()
        self.humidity_var = tk.StringVar()
        self.gas_var = tk.StringVar()

        # Set static sensor data
        self.temperature_var.set(static_temperature)
        self.humidity_var.set(static_humidity)
        self.gas_var.set(static_gas_concentration)

        # Create main frame
        self.main_frame = tk.Frame(master)
        self.main_frame.pack(fill=tk.BOTH, expand=True)

        # Create frames for sensor data and inventory management
        self.create_sensor_frame()
        self.create_inventory_input_frame()
        self.create_inventory_display_frame()

        # Load existing inventory data from JSON file
        self.inventory_data = self.load_inventory_data()

    def create_sensor_frame(self):
        # Create frame for sensor data
        sensor_frame = tk.Frame(self.main_frame, relief="groove", borderwidth=2)
        sensor_frame.pack(fill=tk.X, padx=10, pady=10)

        moisture = tk.Label(sensor_frame, text="Moisture Data: ")
        moisture.grid(row=0, column=0, padx=10, pady=10, sticky="w")
        moisture_value = tk.Entry(sensor_frame, textvariable=self.humidity_var)
        moisture_value.grid(row=0, column=1)

        temperature = tk.Label(sensor_frame, text="Temperature Data: ")
        temperature.grid(row=1, column=0, padx=10, pady=10, sticky="w")
        temperature_value = tk.Entry(sensor_frame, textvariable=self.temperature_var)
        temperature_value.grid(row=1, column=1)

        ethylene = tk.Label(sensor_frame, text="Ethylene Data: ")
        ethylene.grid(row=2, column=0, padx=10, pady=10, sticky="w")
        ethylene_value = tk.Entry(sensor_frame, textvariable=self.gas_var)
        ethylene_value.grid(row=2, column=1)

    def create_inventory_input_frame(self):
        frame = tk.Frame(self.main_frame, relief="groove", borderwidth=2)
        frame.pack(side=tk.LEFT, fill=tk.BOTH, padx=10, pady=10, expand=True)

        # Input fields
        ttk.Label(frame, text="Serial Number:").grid(row=0, column=0, padx=5, pady=5, sticky="w")
        self.serial_number_entry = ttk.Entry(frame)
        self.serial_number_entry.grid(row=0, column=1, padx=5, pady=5)

        ttk.Label(frame, text="Name:").grid(row=1, column=0, padx=5, pady=5, sticky="w")
        self.name_entry = ttk.Entry(frame)
        self.name_entry.grid(row=1, column=1, padx=5, pady=5)

        ttk.Label(frame, text="Quantity:").grid(row=2, column=0, padx=5, pady=5, sticky="w")
        self.quantity_entry = ttk.Entry(frame)
        self.quantity_entry.grid(row=2, column=1, padx=5, pady=5)

        ttk.Label(frame, text="Date:").grid(row=3, column=0, padx=5, pady=5, sticky="w")
        self.date_entry = ttk.Entry(frame)
        self.date_entry.grid(row=3, column=1, padx=5, pady=5)

        # Add button
        add_button = ttk.Button(frame, text="Add", command=self.add_product)
        add_button.grid(row=4, column=0, pady=10)

        # Delete button
        delete_button = ttk.Button(frame, text="Delete", command=self.delete_product)
        delete_button.grid(row=4, column=1, pady=10)

    def create_inventory_display_frame(self):
        self.treeview_frame = tk.Frame(self.main_frame, relief="groove", borderwidth=2)
        self.treeview_frame.pack(side=tk.RIGHT, fill=tk.BOTH, padx=10, pady=10, expand=True)

        # Treeview
        self.tree = ttk.Treeview(self.treeview_frame, columns=("Serial Number", "Name", "Quantity", "Date"))
        self.tree.heading("#0", text="ID")
        self.tree.heading("Serial Number", text="Serial Number")
        self.tree.heading("Name", text="Name")
        self.tree.heading("Quantity", text="Quantity")
        self.tree.heading("Date", text="Date")
        self.tree.pack(fill=tk.BOTH, expand=True)

    def add_product(self):
        # Get data from entry fields
        serial_number = self.serial_number_entry.get()
        name = self.name_entry.get()
        quantity = self.quantity_entry.get()
        date = self.date_entry.get()

        # Validate inputs
        if not all((serial_number, name, quantity, date)):
            messagebox.showerror("Error", "Please fill in all fields.")
            return

        # Add product to inventory data
        self.inventory_data.append({
            "serial_number": serial_number,
            "name": name,
            "quantity": quantity,
            "date": date
        })

        # Update treeview
        self.update_treeview()

        # Clear entry fields
        self.clear_entry_fields()

        # Save inventory data to JSON file
        self.save_inventory_data()

    def delete_product(self):
        # Get selected item
        selected_item = self.tree.selection()
        if not selected_item:
            messagebox.showerror("Error", "Please select a product to delete.")
            return

        # Remove selected item from inventory data
        for item in selected_item:
            item_id = self.tree.item(item, "text")
            del self.inventory_data[int(item_id) - 1]

        # Update treeview
        self.update_treeview()

        # Save inventory data to JSON file
        self.save_inventory_data()

    def update_treeview(self):
        # Clear existing items in treeview
        for item in self.tree.get_children():
            self.tree.delete(item)

        # Insert new items
        for idx, item in enumerate(self.inventory_data, start=1):
            self.tree.insert("", "end", text=str(idx),
                             values=(item["serial_number"], item["name"], item["quantity"], item["date"]))

    def clear_entry_fields(self):
        self.serial_number_entry.delete(0, tk.END)
        self.name_entry.delete(0, tk.END)
        self.quantity_entry.delete(0, tk.END)
        self.date_entry.delete(0, tk.END)

    def load_inventory_data(self):
        try:
            with open("inventory_data.json", "r") as file:
                return json.load(file)
        except FileNotFoundError:
            return []

    def save_inventory_data(self):
        with open("inventory_data.json", "w") as file:
            json.dump(self.inventory_data, file, indent=4)

# Main window
window = tk.Tk()
window.wm_title("STORAGE MANAGEMENT SYSTEM")

# Create main frame
main_frame = tk.Frame(window)
main_frame.pack(fill=tk.BOTH, expand=True)

# Buttons for storage rooms
storage_buttons_frame = tk.Frame(main_frame)
storage_buttons_frame.pack(fill=tk.BOTH)

btn_storage1 = tk.Button(storage_buttons_frame, text="Storage Room 1",
                         command=lambda: print("Showing storage room 1"),
                         relief="groove", bg="skyblue")
btn_storage1.pack(side=tk.LEFT, padx=10, pady=5)

btn_storage2 = tk.Button(storage_buttons_frame, text="Storage Room 2",
                         command=lambda: print("Showing storage room 2"),
                         relief="groove", bg="skyblue")
btn_storage2.pack(side=tk.LEFT, padx=10, pady=5)

btn_storage3 = tk.Button(storage_buttons_frame, text="Storage Room 3",
                         command=lambda: print("Showing storage room 3"),
                         relief="groove", bg="skyblue")
btn_storage3.pack(side=tk.LEFT, padx=10, pady=5)

# Initialize the Inventory Management App
app = InventoryManagementApp(main_frame)

# Display window
window.mainloop()