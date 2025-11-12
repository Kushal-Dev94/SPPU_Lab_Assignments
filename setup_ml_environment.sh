#!/bin/bash

# Step 1: Update system packages
echo "Updating system packages..."
sudo apt-get update && sudo apt-get upgrade -y

# Step 2: Install Python 3 and pip
echo "Installing Python 3 and pip..."
sudo apt-get install python3 python3-pip python3-dev -y

# Step 3: Install Jupyter Notebook
echo "Installing Jupyter Notebook..."
pip3 install jupyter

# Step 4: Install necessary ML libraries
echo "Installing ML libraries..."
pip3 install scikit-learn pandas numpy nltk mlxtend matplotlib seaborn

# Step 5: Verify installed versions

echo "Verifying Python version..."
python3 --version

echo "Verifying pip version..."
pip3 --version

echo "Verifying scikit-learn version..."
python3 -c "import sklearn; print('scikit-learn version:', sklearn.__version__)"

echo "Verifying pandas version..."
python3 -c "import pandas; print('pandas version:', pandas.__version__)"

echo "Verifying numpy version..."
python3 -c "import numpy; print('numpy version:', numpy.__version__)"

echo "Verifying nltk version..."
python3 -c "import nltk; print('nltk version:', nltk.__version__)"

echo "Verifying mlxtend version..."
python3 -c "import mlxtend; print('mlxtend version:', mlxtend.__version__)"

echo "Verifying matplotlib version..."
python3 -c "import matplotlib; print('matplotlib version:', matplotlib.__version__)"

echo "Verifying seaborn version..."
python3 -c "import seaborn; print('seaborn version:', seaborn.__version__)"

# Step 6: Optionally, start Jupyter Notebook
echo "Starting Jupyter Notebook..."
jupyter notebook

