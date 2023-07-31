import tkinter as tk
from tkinter import ttk
import csv
from Searcher import search_google

def on_search():
    query = search_entry.get()
    search_results = search_google([query])

    # Display results in the Treeview widget
    for item in tree.get_children():
        tree.delete(item)
    for i, result in enumerate(search_results, start=1):
        tree.insert("", "end", values=(i, result['title'], result['url'], result['snippet']))

    # Save results to a CSV file
    save_to_csv(search_results)

def save_to_csv(results):
    with open('search_results.csv', 'w', newline='', encoding='utf-8') as csvfile:
        fieldnames = ['Title', 'URL', 'Snippet']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        for result in results:
            writer.writerow({'Title': result['title'], 'URL': result['url'], 'Snippet': result['snippet']})

# Create the main window
root = tk.Tk()
root.title("Google Search Bot")

# Search Entry
search_entry = ttk.Entry(root, width=40)
search_entry.grid(row=0, column=0, padx=10, pady=10)

# Search Button
search_button = ttk.Button(root, text="Search", command=on_search)
search_button.grid(row=0, column=1, padx=10, pady=10)

# Search Results Treeview
tree = ttk.Treeview(root, columns=("No.", "Title", "URL", "Snippet"), show="headings", height=15)
tree.heading("No.", text="No.")
tree.heading("Title", text="Title")
tree.heading("URL", text="URL")
tree.heading("Snippet", text="Snippet")
tree.grid(row=1, column=0, columnspan=2, padx=10, pady=10)

root.mainloop()
