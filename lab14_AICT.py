import tkinter as tk
from tkinter import messagebox
from transformers import pipeline
import os

os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"

print("Loading...")
analyze_sentiment = pipeline("sentiment-analysis")
print("Done.")

def checkemotion():
    
    user_input = text_entry.get("1.0", tk.END).strip()
    
    if not user_input:
        messagebox.showwarning("Warning", "Please enter a sentence ")
        return

    try:
        
        result = analyze_sentiment(user_input)
        label = result[0]['label']
        score = round(result[0]['score'], 2)

        
        result_label.config(text=f"Predicted Sentiment: {label}\nConfidence: {score}", fg="Red")
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {str(e)}")


root = tk.Tk()
root.title("Sentiment Analysis by AI")
root.geometry("400x350")

tk.Label(root, text="Enter a Sentence:", font=("Arial", 20, "bold")).pack(pady=20)
text_entry = tk.Text(root, height=5, width=40)
text_entry.pack(padx=10, pady=5)

analyze_btn = tk.Button(root, text="check sentiment", command=checkemotion, bg="#4CAF50", fg="black")
analyze_btn.pack(pady=10)

result_label = tk.Label(root, text="", font=("Arial", 11, "bold"))
result_label.pack(pady=20)

root.mainloop()