# Importing necessary libraries
import os
import numpy as np
import pandas as pd
import warnings
import matplotlib.pyplot as plt
from sklearn import preprocessing
from sklearn.model_selection import train_test_split, cross_val_score, cross_val_predict
from sklearn.metrics import accuracy_score, recall_score, roc_auc_score, confusion_matrix
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
import seaborn as sns

# Ignoring warnings
warnings.filterwarnings('ignore')

# Load data
data_file = 'Hanoi.csv'

data = pd.read_csv(data_file)

# Display basic information about the data
print(data.head())
print(data.tail())
print(data.isnull().sum())  # Check for missing values
print(data.shape)
print(data.describe())

# Check data types
print(data.dtypes)

# Filter only numerical columns for covariance and correlation
numerical_data = data.select_dtypes(include=[np.number])
print(numerical_data.cov())
print(numerical_data.corr())

# Replace categorical values in FLOODS column with numeric
data['FLOODS'].replace(['YES', 'NO'], [1, 0], inplace=True)
print(data.head())

# Split data into features (X) and labels (y)
X = data.iloc[:, 1:14]
y = data.iloc[:, -1].astype('int')

# Visualizing data
X[['JUN', 'JUL', 'AUG', 'SEP']].hist()
plt.show()

monthly_mean = X.mean()
monthly_mean.plot.bar(width=0.5, edgecolor='k', align='center', linewidth=2, figsize=(14, 6))
plt.xlabel('Month', fontsize=30)
plt.ylabel('Monthly Rainfall', fontsize=20)
plt.title('Rainfall in Hanoi for all Months', fontsize=25)
plt.grid()
plt.show()

# Scaling data
scaler = preprocessing.MinMaxScaler(feature_range=(0, 1))
X_scaled = scaler.fit_transform(X)

# Split data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

# Initialize models
models = {
    "KNN": KNeighborsClassifier(),
    "Logistic Regression": LogisticRegression(),
    "SVM": SVC(kernel='rbf', probability=True),
    "Decision Tree": DecisionTreeClassifier(),
    "Random Forest": RandomForestClassifier(max_depth=3, random_state=0)
}

# Evaluate models
results = []
for name, model in models.items():
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)

    acc = accuracy_score(y_test, y_pred)
    recall = recall_score(y_test, y_pred)
    roc = roc_auc_score(y_test, y_pred)
    cm = confusion_matrix(y_test, y_pred)

    print(f"\n{name} Results:")
    print(f"Accuracy: {acc:.2f}")
    print(f"Recall: {recall:.2f}")
    print(f"ROC AUC: {roc:.2f}")
    print(f"Confusion Matrix:\n{cm}")

    results.append({"Name": name, "Accuracy": acc})

# Visualize model performance
results_df = pd.DataFrame(results)
sns.barplot(x='Name', y='Accuracy', data=results_df)
plt.xlabel('Classifier Models')
plt.ylabel('Accuracy of the Model')
plt.title('Model Comparison')
plt.xticks(rotation=45)
plt.show()

# Save the best model (example with Random Forest)
import joblib
best_model = models["Random Forest"]
joblib.dump(best_model, "best_flood_model.pkl")
