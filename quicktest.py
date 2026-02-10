from transformers import pipeline

# Load sentiment analysis model
sentiment_analyzer = pipeline("sentiment-analysis")

# Analyze sentiment of a sample sentence
result = sentiment_analyzer("I love the new AI tools. They're amazing!")

# Print result
print("Sentiment:", result[0]['label'], "| Score:", round(result[0]['score'], 2))
