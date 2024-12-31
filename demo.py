import matplotlib.pyplot as plt
import seaborn as sns
import datetime
import pandas as pd
from sklearn.preprocessing import LabelEncoder, StandardScaler
from sklearn.model_selection import train_test_split
from keras.layers import Dense, BatchNormalization, Dropout
from keras.models import Sequential
from keras.optimizers import Adam
from keras import callbacks
import numpy as np
from sklearn.metrics import accuracy_score, f1_score, classification_report

# Load dataset with error handling
try:
    features = pd.read_csv('weatherAUS.csv', on_bad_lines='skip')
except Exception as e:
    print("Error loading dataset:", e)
    exit()

# Ensure reproducibility
np.random.seed(0)

# Convert Date column to datetime
features['Date'] = pd.to_datetime(features['Date'], errors='coerce')

# Drop rows with invalid dates
features = features.dropna(subset=['Date'])

# Extract year, month, and day as separate features
features['Year'] = features['Date'].dt.year
features['Month'] = features['Date'].dt.month
features['Day'] = features['Date'].dt.day

# Drop the original Date column
features = features.drop(['Date'], axis=1)

# Handle missing values
features = features.fillna(features.median(numeric_only=True))

# Encode categorical variables
categorical_cols = features.select_dtypes(include=['object']).columns
for col in categorical_cols:
    features[col] = features[col].astype(str)
    features[col] = LabelEncoder().fit_transform(features[col])

# Prepare features and target
if 'RainTomorrow' not in features.columns:
    raise ValueError("The target column 'RainTomorrow' is missing from the dataset.")

X = features.drop("RainTomorrow", axis=1)
y = features["RainTomorrow"]

# Data preprocessing
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

# Early stopping with improved parameters
early_stopping = callbacks.EarlyStopping(
    monitor='val_loss',
    min_delta=0.001,
    patience=20,
    restore_best_weights=True,
    verbose=1
)

# Improved model architecture
model = Sequential([
    Dense(128, activation='relu', kernel_initializer='he_normal', input_dim=X.shape[1]),
    BatchNormalization(),
    Dropout(0.4),
    Dense(64, activation='relu', kernel_initializer='he_normal'),
    BatchNormalization(),
    Dropout(0.3),
    Dense(32, activation='relu', kernel_initializer='he_normal'),
    Dropout(0.2),
    Dense(1, activation='sigmoid')
])

# Compile with better learning rate
opt = Adam(learning_rate=0.001)
model.compile(optimizer=opt, loss='binary_crossentropy', metrics=['accuracy', 'AUC'])

# Train model
history = model.fit(
    X_train, 
    y_train,
    batch_size=32,
    epochs=100,
    validation_split=0.2,
    callbacks=[early_stopping],
    verbose=1
)

# Model evaluation
y_pred = model.predict(X_test)
y_pred_classes = (y_pred > 0.5).astype(int)

print('\nModel Evaluation:')
print('Accuracy:', accuracy_score(y_test, y_pred_classes))
# Check the unique classes in y_test to decide on f1_score
unique_classes = np.unique(y_test)
if len(unique_classes) == 2:
    # Binary classification
    print('F1 Score:', f1_score(y_test, y_pred_classes))
else:
    # Multiclass classification
    print('F1 Score (macro):', f1_score(y_test, y_pred_classes, average='macro'))

print('\nClassification Report:')
print(classification_report(y_test, y_pred_classes))

# Plot training history
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 4))

ax1.plot(history.history['loss'], label='Training Loss')
ax1.plot(history.history['val_loss'], label='Validation Loss')
ax1.set_title('Model Loss')
ax1.set_xlabel('Epoch')
ax1.set_ylabel('Loss')
ax1.legend()

ax2.plot(history.history['accuracy'], label='Training Accuracy')
ax2.plot(history.history['val_accuracy'], label='Validation Accuracy')
ax2.set_title('Model Accuracy')
ax2.set_xlabel('Epoch')
ax2.set_ylabel('Accuracy')
ax2.legend()

plt.tight_layout()
plt.show()