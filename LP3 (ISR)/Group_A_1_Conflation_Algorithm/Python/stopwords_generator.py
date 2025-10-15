import nltk
from nltk.corpus import stopwords

nltk.download('stopwords')  # Run this once
english_stopwords = set(stopwords.words('english'))

# Save to stopwords.txt (optional)
with open('Group_A_1_Conflation_Algorithm/Python/stopwords.txt', 'w') as f:
    for word in english_stopwords:
        f.write(f"{word}\n")
