import tkinter as tk
from tkinter import messagebox
from transformers import pipeline
import os

# Suppress warnings for a cleaner console
os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"

# Load the sentiment analysis model (DistilBERT is the default)
print("Loading model... please wait.")
sentiment_analyzer = pipeline("sentiment-analysis")
print("Model Ready.")

def analyze_sentiment():
    # Get user input from the text box
    user_input = text_entry.get("1.0", tk.END).strip()
    
    if not user_input:
        messagebox.showwarning("Warning", "Please enter a sentence to analyze.")
        return

    try:
        # Perform analysis
        result = sentiment_analyzer(user_input)
        label = result[0]['label']
        score = round(result[0]['score'], 2)

        # Show the result on the screen as required by the task
        result_label.config(text=f"Predicted Sentiment: {label}\nConfidence: {score}", fg="blue")
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {str(e)}")

# Create the GUI window
root = tk.Tk()
root.title("AI Sentiment Analysis")
root.geometry("400x350")

# Task requirement: User enters "Sample Sentence" in Text box
tk.Label(root, text="Enter Sample Sentence:", font=("Arial", 10, "bold")).pack(pady=10)
text_entry = tk.Text(root, height=5, width=40)
text_entry.pack(padx=10, pady=5)

# Button to trigger analysis
analyze_btn = tk.Button(root, text="Analyze Sentiment", command=analyze_sentiment, bg="#4CAF50", fg="white")
analyze_btn.pack(pady=10)

# Task requirement: Show "Predicted Sentiment" and "Confidence" on screen
result_label = tk.Label(root, text="", font=("Arial", 11, "bold"))
result_label.pack(pady=20)

root.mainloop()