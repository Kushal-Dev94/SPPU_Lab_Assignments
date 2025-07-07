import re
from collections import Counter
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
import nltk

# Download stopwords if not already present
nltk.download('stopwords')

def tokenize(text):
    # Extract words and convert to lowercase
    return re.findall(r'\b\w+\b', text.lower())

def process_document(document_path):
    stemmer = PorterStemmer()
    stop_words = set(stopwords.words('english'))
    print(stop_words)

    with open(document_path, 'r') as f:
        text = f.read()

    words = tokenize(text)
    # Remove stopwords
    filtered_words = [word for word in words if word not in stop_words]
    # Apply stemming
    stemmed_words = [stemmer.stem(word) for word in filtered_words]

    return Counter(stemmed_words)

def save_conflated_output(word_freq, output_path, min_freq=1):
    with open(output_path, 'w') as f:
        for word, freq in word_freq.most_common():
            if freq >= min_freq:
                f.write(f"{word}: {freq}\n")

if __name__ == "__main__":
    input_file = "Group_A_1_Conflation_Algorithm/Python/document.txt"
    output_file = "Group_A_1_Conflation_Algorithm/Python/conflated_output.txt"

    word_freq = process_document(input_file)
    save_conflated_output(word_freq, output_file)

    print(f"Conflated output saved to '{output_file}'")
