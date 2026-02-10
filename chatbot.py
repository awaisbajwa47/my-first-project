# -------------------------------
# Import required libraries
# -------------------------------
import tkinter as tk
from tkinter import scrolledtext
from transformers import AutoTokenizer, AutoModelForSeq2SeqLM
import torch
import os

# -------------------------------
# Suppress TensorFlow warnings (optional)
# -------------------------------
os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"

# -------------------------------
# Load instruction-tuned FLAN-T5 model
# This model answers factual questions correctly
# -------------------------------
tokenizer = AutoTokenizer.from_pretrained("google/flan-t5-base")
model = AutoModelForSeq2SeqLM.from_pretrained("google/flan-t5-base")

# -------------------------------
# Function to handle user input
# -------------------------------
def send_message():
    # Get user input from entry widget
    user_text = user_entry.get().strip()
    if not user_text:
        return  # Do nothing if input is empty

    # Display user message in chat box
    chat_box.config(state=tk.NORMAL)
    chat_box.insert(tk.END, "You: " + user_text + "\n")
    chat_box.config(state=tk.DISABLED)
    chat_box.yview(tk.END)

    # Clear input field
    user_entry.delete(0, tk.END)

    # -------------------------------
    # Prepare prompt for FLAN-T5
    # -------------------------------
    prompt = f"Answer the following question clearly:\n{user_text}"
    # Encode text to tokens
    inputs = tokenizer(prompt, return_tensors="pt")

    # -------------------------------
    # Generate model response
    # -------------------------------
    outputs = model.generate(
        **inputs,
        max_length=150,  # Maximum tokens for answer
        temperature=0.7  # Sampling temperature for variability
    )

    # Decode tokens back to readable text
    reply = tokenizer.decode(outputs[0], skip_special_tokens=True)

    # Display bot response in chat box
    chat_box.config(state=tk.NORMAL)
    chat_box.insert(tk.END, "Bot: " + reply + "\n\n")
    chat_box.config(state=tk.DISABLED)
    chat_box.yview(tk.END)

# -------------------------------
# Create GUI window
# -------------------------------
root = tk.Tk()
root.title("AI Chatbot (Accurate Q&A)")
root.geometry("600x500")

# -------------------------------
# Create scrollable chat display area
# -------------------------------
chat_box = scrolledtext.ScrolledText(root, state=tk.DISABLED, wrap=tk.WORD)
chat_box.pack(padx=10, pady=10, fill=tk.BOTH, expand=True)

# -------------------------------
# Bottom frame for entry + button
# -------------------------------
bottom = tk.Frame(root)
bottom.pack(fill=tk.X, padx=10)

# -------------------------------
# Entry widget for user input
# -------------------------------
user_entry = tk.Entry(bottom)
user_entry.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=(0, 10))
# Bind Enter key to send message
user_entry.bind("<Return>", lambda e: send_message())

# -------------------------------
# Send button widget
# -------------------------------
tk.Button(bottom, text="Send", command=send_message).pack(side=tk.RIGHT)

# -------------------------------
# Display welcome message
# -------------------------------
chat_box.config(state=tk.NORMAL)
chat_box.insert(
    tk.END,
    "Bot: Hello! Ask factual questions like 'What is AI?' or 'Explain ML'.\n\n"
)
chat_box.config(state=tk.DISABLED)

# -------------------------------
# Start the Tkinter GUI loop
# -------------------------------
root.mainloop()
