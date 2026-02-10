import tkinter as tk
from tkinter import messagebox, scrolledtext
from transformers import pipeline
import os

# Suppress TensorFlow warnings (optional)
os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"

# Load summarization model (lightweight & fast)
summarizer = pipeline(
    "summarization",
    model="t5-small",
    framework="pt"
)

def generate_summary():
    text = input_text.get("1.0", tk.END).strip()
    if len(text) < 50:
        messagebox.showwarning(
            "Warning", "Please enter more text for summarization."
        )
        return
    try:
        summary = summarizer(text, max_length=60, min_length=30)
        output_text.delete("1.0", tk.END)
        output_text.insert(tk.END, summary[0]['summary_text'])
    except Exception as e:
        messagebox.showerror("Error", str(e))

# GUI window
root = tk.Tk()
root.title("AI Text Summarizer")
root.geometry("700x500")

# Labels and Input Text
tk.Label(root, text="Enter Text:", font=("Arial", 12, "bold")).pack(anchor="w", padx=10)
input_text = scrolledtext.ScrolledText(root, height=10, wrap=tk.WORD)
input_text.pack(fill="both", padx=10, pady=5)

# Generate Summary Button
tk.Button(
    root,
    text="Generate Summary",
    font=("Arial", 11, "bold"),
    bg="#4CAF50",
    fg="white",
    command=generate_summary
).pack(pady=10)

# Output Label and Text
tk.Label(root, text="Summary:", font=("Arial", 12, "bold")).pack(anchor="w", padx=10)
output_text = scrolledtext.ScrolledText(root, height=8, wrap=tk.WORD)
output_text.pack(fill="both", padx=10, pady=5)

root.mainloop()
